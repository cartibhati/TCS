import os
import json
import re

def sync_repository():
    base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    problems = []

    # 1. Scan for problems containing metadata.json
    for root, dirs, files in os.walk(base_dir):
        # Ignore hidden directories like .git and the scripts folder itself
        dirs[:] = [d for d in dirs if not d.startswith('.') and d != 'scripts']
        
        if 'metadata.json' in files:
            metadata_path = os.path.join(root, 'metadata.json')
            try:
                with open(metadata_path, 'r', encoding='utf-8') as f:
                    meta = json.load(f)
                
                # Check required fields
                required_fields = ['id', 'name', 'topic', 'difficulty', 'tags', 'companies', 'nqt_frequency']
                for field in required_fields:
                    if field not in meta:
                        raise ValueError(f"Missing field '{field}' in {metadata_path}")
                
                # Add path details relative to base_dir
                rel_dir = os.path.relpath(root, base_dir).replace('\\', '/')
                meta['rel_dir'] = rel_dir
                meta['abs_dir'] = root
                problems.append(meta)
            except Exception as e:
                print(f"Error parsing {metadata_path}: {e}")

    # 2. Sort problems: group by Topic, then by ID
    problems.sort(key=lambda x: (x['topic'], x['id']))

    # Group problems by topic
    topics_grouped = {}
    for p in problems:
        topic = p['topic']
        if topic not in topics_grouped:
            topics_grouped[topic] = []
        topics_grouped[topic].append(p)

    # 3. Calculate statistics
    total_solved = len(problems)
    easy_count = sum(1 for p in problems if p['difficulty'].lower() == 'easy')
    medium_count = sum(1 for p in problems if p['difficulty'].lower() == 'medium')
    hard_count = sum(1 for p in problems if p['difficulty'].lower() == 'hard')

    # 4. Update Navigation Links in individual problem READMEs
    for i, p in enumerate(problems):
        readme_path = os.path.join(p['abs_dir'], 'README.md')
        if not os.path.exists(readme_path):
            print(f"Warning: README.md not found at {readme_path}")
            continue

        # Find previous and next problem in global sorted list
        prev_p = problems[i - 1] if i > 0 else None
        next_p = problems[i + 1] if i < len(problems) - 1 else None

        # Build navigation markdown table
        nav_lines = []
        nav_lines.append("| Links | Navigation |")
        nav_lines.append("| :--- | :--- |")
        
        # Dashboard and Index Row
        topic_anchor = p['topic'].lower().replace(' ', '-')
        nav_lines.append(f"| [🏛️ Repository Dashboard](../../README.md) | [📂 {p['topic']} Index](../../README.md#{topic_anchor}) |")
        
        # Prev / Next Row
        prev_link = f"[← Prev: {prev_p['name']}](../{os.path.basename(prev_p['rel_dir'])}/README.md)" if prev_p else "None (First)"
        next_link = f"[Next: {next_p['name']} →](../{os.path.basename(next_p['rel_dir'])}/README.md)" if next_p else "None (Last)"
        nav_lines.append(f"| **Prev:** {prev_link} | **Next:** {next_link} |")
        
        nav_content = "\n".join(nav_lines)

        # Replace standard navigation block in problem README
        try:
            with open(readme_path, 'r', encoding='utf-8') as f:
                content = f.read()

            pattern = r'<!-- navigation -->.*?<!-- navigation -->'
            replacement = f"<!-- navigation -->\n{nav_content}\n<!-- navigation -->"
            
            if re.search(pattern, content, re.DOTALL):
                new_content = re.sub(pattern, replacement, content, flags=re.DOTALL)
            else:
                new_content = content + "\n\n## Navigation\n" + replacement

            with open(readme_path, 'w', encoding='utf-8') as f:
                f.write(new_content)
            print(f"Updated navigation for {p['name']}")
        except Exception as e:
            print(f"Error updating navigation for {p['name']}: {e}")

    # 5. Generate root README.md
    readme_content = f"""# TCS NQT Coding Preparation Dashboard

[![Exam: TCS NQT](https://img.shields.io/badge/Exam-TCS%20NQT-blue?style=for-the-badge&logo=github)](https://www.tcs.com)
[![Solved Problems](https://img.shields.io/badge/Solved-{total_solved}-success?style=for-the-badge)](https://github.com/cartibhati/TCS)
[![Language: C++17](https://img.shields.io/badge/Language-C%2B%2B17-orange?style=for-the-badge&logo=c%2B%2B)](https://en.cppreference.com/w/cpp/compiler_support/17)
[![Profile: Placement Ready](https://img.shields.io/badge/Placement-Ready-red?style=for-the-badge)](https://github.com/cartibhati)

Welcome to my personal **TCS NQT, Prime, and Digital** coding preparation repository! This repository contains structured solutions to data structures and algorithms (DSA) problems asked in recent placement assessments. Every solution is refactored for readability, optimized to modern standards (C++17), and documented with notes designed for quick 5-minute revision.

---

## 🎯 Repository Dashboard

### 📊 Progress Counters
- **Total Solved Questions:** `{total_solved}`
- **Difficulty Distribution:**
  - 🟢 **Easy:** `{easy_count}`
  - 🟡 **Medium:** `{medium_count}`
  - 🔴 **Hard:** `{hard_count}`

### 📈 Progress Tracker
```text
Easy:   [{"█" * int(easy_count/max(total_solved, 1)*20)}{"░" * (20 - int(easy_count/max(total_solved, 1)*20))}] {int(easy_count/max(total_solved, 1)*100)}%
Medium: [{"█" * int(medium_count/max(total_solved, 1)*20)}{"░" * (20 - int(medium_count/max(total_solved, 1)*20))}] {int(medium_count/max(total_solved, 1)*100)}%
Hard:   [{"█" * int(hard_count/max(total_solved, 1)*20)}{"░" * (20 - int(hard_count/max(total_solved, 1)*20))}] {int(hard_count/max(total_solved, 1)*100)}%
```

---

## 🗺️ Study Roadmap & Strategy
This preparation focuses on patterns most commonly tested by TCS (Ninja/Digital/Prime) and other service-based giants (Accenture, Capgemini, Wipro, Cognizant):

1. **Phase 1: Foundation (Arrays & Strings)** — Linear scanning, two pointers, basic hashing, prefix-sums.
2. **Phase 2: Intermediate (Math & Searching)** — Binary search, GCD/LCM, prime numbers, base conversions, greedy techniques.
3. **Phase 3: Advanced (Recursion & Dynamics)** — Basic DP, sliding window, tree traversals, sorting.

---

## 📚 Table of Contents
"""

    # Add Topics & Index
    for topic, p_list in sorted(topics_grouped.items()):
        topic_anchor = topic.lower().replace(' ', '-')
        readme_content += f"- [📂 {topic} ({len(p_list)})](#{topic_anchor})\n"
    
    readme_content += "\n---\n"

    for topic, p_list in sorted(topics_grouped.items()):
        readme_content += f"\n## 📊 {topic}\n\n"
        readme_content += "| ID | Problem Name | Difficulty | Frequency | Target Companies | Solution |\n"
        readme_content += "| :--- | :--- | :--- | :--- | :--- | :--- |\n"
        
        for p in p_list:
            diff_label = "🟢 Easy" if p['difficulty'].lower() == 'easy' else ("🟡 Medium" if p['difficulty'].lower() == 'medium' else "🔴 Hard")
            companies_str = ", ".join(p['companies'][:3]) + ("..." if len(p['companies']) > 3 else "")
            readme_content += f"| {p['id']} | [{p['name']}]({p['rel_dir']}/README.md) | {diff_label} | {p['nqt_frequency']} | `{companies_str}` | [C++17]({p['rel_dir']}/solution.cpp) |\n"
        
        readme_content += "\n"

    readme_content += """
---

## 🛠️ Resources Used
*   **Practice Portals:** GeeksforGeeks, LeetCode, PrepInsta, FacePrep
*   **Syllabus Focus:** TCS NQT coding syllabus including basic numerical logic, arrays manipulation, string processing, and matrix patterns.
*   **Reference Code Style:** Modern C++17 with explicit type declarations, STL algorithms, and clean input/output checks.

---

## 🤝 Recruiter Information
This repository is designed to demonstrate:
- **Consistent Code Quality:** Standard coding style, clean variables, modern standard compliance, and input checks.
- **Strong Explanatory Skills:** Detailed problem write-ups reflecting system design awareness, performance trade-offs, and logical correctness.
- **Placement Readiness:** Focused study on the topics that matter most for fast, correct execution under exam time limits.
"""

    # Write root README.md
    readme_path = os.path.join(base_dir, 'README.md')
    try:
        with open(readme_path, 'w', encoding='utf-8') as f:
            f.write(readme_content)
        print("Root README.md regenerated successfully.")
    except Exception as e:
        print(f"Error writing root README.md: {e}")

if __name__ == '__main__':
    sync_repository()
