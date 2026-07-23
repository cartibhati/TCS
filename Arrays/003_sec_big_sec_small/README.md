# Second Smallest and Second Largest

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Linear Scan`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** This is one of the most frequently asked array questions in TCS coding rounds. It directly builds upon the concept of finding the minimum/maximum element, but tests if you can track multiple running state variables correctly.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported (found across prep guides and assessment archives).

---

## Pattern Recognition
This problem belongs to the **Linear Scan (Tracking Top 2 Candidates)** pattern.
*   **When to use:** Whenever you need to find the top $K$ extreme values (e.g., largest and second largest) in an unsorted collection in $O(N)$ time.
*   **Core signature:** Keep two running variables (e.g., `small` and `secsmall`) representing the extreme and sub-extreme values. When a new element beats the extreme, demote the old extreme to the sub-extreme and update the extreme. If it only beats the sub-extreme, update the sub-extreme.

---

## Intuition
Consider running a race where you want to identify the winner and the runner-up:
1. If a runner arrives who is faster than the current winner (`x < small`), the current winner becomes the runner-up (`secsmall = small`), and the new runner becomes the winner (`small = x`).
2. If a runner is slower than the winner but faster than the runner-up (`x > small && x < secsmall`), they simply replace the runner-up (`secsmall = x`).
3. Apply the exact symmetric logic to find the largest and second largest elements.

---

## Approaches

### 1. Documented Solution (Single-Pass Linear Scan)
*   **Concept:** Implement two independent single-pass loops. For `secsmall`, keep `small` and `secsmall` initialized to `INT_MAX`. For `secbig`, keep `big` and `secbig` initialized to `INT_MIN`.
*   **Time Complexity:** $\mathcal{O}(N)$ (two linear scans).
*   **Space Complexity:** $\mathcal{O}(1)$ (only tracking variables used).

### 2. Alternative Approach (Brute Force by Sorting)
*   **Concept:** Sort the array in ascending order.
    *   Second Smallest = `nums[1]`
    *   Second Largest = `nums[N-2]`
*   **Drawbacks:**
    *   Time Complexity: $\mathcal{O}(N \log N)$ (suboptimal).
    *   **Duplicate Failure:** If the input is `{2, 2, 3, 4}`, sorting gives `{2, 2, 3, 4}`. The second element `nums[1]` is `2`, which is not the *distinct* second smallest element. Correcting this requires writing extra duplicate filtration code, making sorting highly complex and inefficient.

### 3. Alternative Approach (Two-Pass Linear Scan)
*   **Concept:** 
    *   Pass 1: Find the absolute minimum (or maximum) value.
    *   Pass 2: Find the minimum (or maximum) value again, but ignore any elements equal to the absolute minimum (or maximum) found in Pass 1.
*   **Time Complexity:** $\mathcal{O}(N)$ (two passes, but slightly more comparisons than single-pass).

---

## Algorithm (Documented Solution)

### Finding Second Smallest (`secsmall`):
1. Initialize `small = INT_MAX` and `secsmall = INT_MAX`.
2. For each element `x` in the array:
   * If `x < small`, set `secsmall = small` and `small = x`.
   * Else if `x > small` and `x < secsmall`, set `secsmall = x`.
3. Return `secsmall`.

### Finding Second Largest (`secbig`):
1. Initialize `big = INT_MIN` and `secbig = INT_MIN`.
2. For each element `x` in the array:
   * If `x > big`, set `secbig = big` and `big = x`.
   * Else if `x < big` and `x > secbig`, set `secbig = x`.
3. Return `secbig`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {4, 3, 5, 67, 2, 78, 8}`

### 1. Tracing `secsmall`
*   Initial state: `small = INT_MAX`, `secsmall = INT_MAX`

| Element ($x$) | Condition Met | Action taken | Running `small` | Running `secsmall` |
| :--- | :--- | :--- | :--- | :--- |
| **4** | $4 < \text{small}$ (True) | `secsmall = small` (INT_MAX), `small = 4` | 4 | **INT_MAX** |
| **3** | $3 < \text{small}$ (True) | `secsmall = small` (4), `small = 3` | 3 | **4** |
| **5** | $5 > 3 \ \&\& \ 5 < 4$ (False) | None | 3 | **4** |
| **67**| $67 > 3 \ \&\& \ 67 < 4$ (False)| None | 3 | **4** |
| **2** | $2 < \text{small}$ (True) | `secsmall = small` (3), `small = 2` | 2 | **3** |
| **78**| $78 > 2 \ \&\& \ 78 < 3$ (False)| None | 2 | **3** |
| **8** | $8 > 2 \ \&\& \ 8 < 3$ (False) | None | 2 | **3** |

*   **Output:** `3`

### 2. Tracing `secbig`
*   Initial state: `big = INT_MIN`, `secbig = INT_MIN`

| Element ($x$) | Condition Met | Action taken | Running `big` | Running `secbig` |
| :--- | :--- | :--- | :--- | :--- |
| **4** | $4 > \text{big}$ (True) | `secbig = big` (INT_MIN), `big = 4` | 4 | **INT_MIN** |
| **3** | $3 < 4 \ \&\& \ 3 > \text{INT\_MIN}$ (True) | `secbig = 3` | 4 | **3** |
| **5** | $5 > 4$ (True) | `secbig = big` (4), `big = 5` | 5 | **4** |
| **67**| $67 > 5$ (True) | `secbig = big` (5), `big = 67` | 67 | **5** |
| **2** | $2 < 67 \ \&\& \ 2 > 5$ (False) | None | 67 | **5** |
| **78**| $78 > 67$ (True) | `secbig = big` (67), `big = 78` | 78 | **67** |
| **8** | $8 < 78 \ \&\& \ 8 > 67$ (True) | `secbig = 8` | 78 | **8** |

*   **Output:** `8` (Note: the loop ends, and we print `secbig` which is `8`, not `67`, because `8` is smaller than `78` and larger than `67`, updating `secbig` correctly at the last step).

---

## Why This Works (Correctness)
The logic implements a mathematical induction invariant:
*   At any step $i$ in the scan, `small` is the absolute minimum of the sub-array `nums[0...i]`, and `secsmall` is the second smallest distinct value in `nums[0...i]`.
*   When a new element `x` is examined:
    *   If `x` is strictly less than `small`, it is the new overall minimum. The previous minimum (`small`) becomes the second smallest candidate.
    *   If `x` is between `small` and `secsmall`, it is not small enough to beat `small`, but it is smaller than `secsmall`, so we update the second smallest value.
    *   If `x == small`, it is ignored, which correctly skips duplicates to ensure we find the second *distinct* smallest.

---

## Complexity Analysis
*   **Time Complexity:** $\mathcal{O}(N)$ — We traverse the array exactly once for each function.
*   **Space Complexity:** $\mathcal{O}(1)$ — No extra arrays are allocated; we only store four primitive variables.

---

## Edge Cases
1.  **Array size < 2:** E.g., `nums = {5}`. Loop runs once. `secsmall` remains `INT_MAX`, and `secbig` remains `INT_MIN`. (In production code, you should assert `nums.size() >= 2` before run).
2.  **All elements identical:** E.g., `nums = {2, 2, 2}`. `secsmall` remains `INT_MAX` because the `else if` check `x > small` is false for all duplicate 2s. This is correct behavior to identify that no second *distinct* smallest exists.
3.  **Negative values:** Initializing trackers to `INT_MAX` and `INT_MIN` ensures correct transitions for all negative integers.

---

## Common Mistakes
*   **Incorrect Updates:** Forgetting to update `secsmall = small` when `x < small` is true. Doing only `small = x` will lose the correct second smallest value.
*   **Zero Initialization:** Initializing `big` or `secbig` to `0`. If the array contains negative numbers like `{-5, -12, -3}`, they will all be compared against `0`, resulting in `0` as the incorrect output.

---

## Similar Questions
*   Find the third smallest/largest element in an array.
*   Find the largest element and its index.

---

## Interview Tips & Insights
*   **Recruiter Target:** This question tests logical clarity with tracking states. Many students fail to write the single-pass solution correctly under pressure and default to sorting.
*   **Key Talking Point:** Discuss the duplicate elements edge case immediately. Ask the interviewer: *"Should we return the second distinct smallest, or just the second element of the sorted array?"* (Almost always, they want the second *distinct* smallest, which is exactly what our linear scan does).

---

## Revision Notes (1-Minute Quick Check)
*   **secsmall:** `small = INT_MAX`, `secsmall = INT_MAX`.
    *   `if (x < small)` $\rightarrow$ `secsmall = small; small = x;`
    *   `else if (x > small && x < secsmall)` $\rightarrow$ `secsmall = x;`
*   **secbig:** `big = INT_MIN`, `secbig = INT_MIN`.
    *   `if (x > big)` $\rightarrow$ `secbig = big; big = x;`
    *   `else if (x < big && x > secbig)` $\rightarrow$ `secbig = x;`
*   **Complexity:** Time: $\mathcal{O}(N)$ | Space: $\mathcal{O}(1)$.

---

## Key Takeaways
1.  Always update the second-best state before updating the best state.
2.  Single-pass linear scan is strictly superior to sorting because it handles duplicates naturally and runs in linear time.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Find Largest Number](../002_Largest_number/README.md) | **Next:** None (Last) |
<!-- navigation -->
