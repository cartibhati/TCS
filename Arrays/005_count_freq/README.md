# Count Frequency of Elements

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Hashing`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Counting frequencies is the foundation of many hashing problems (e.g., finding the majority element, finding the first non-repeating character, checking for anagrams). This is one of the most frequently asked problems in TCS NQT.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Hashing** pattern.
*   **When to use:** Whenever you need to track the occurrences, counts, or presence of elements in a collection to perform lookups in $\mathcal{O}(1)$ average time.
*   **Core signature:** Use a hash table (like C++'s `std::unordered_map` or a frequency array if inputs are bounded) to store `element -> count` mappings while iterating over the data.

---

## Intuition
To count the occurrences of each element:
1. We need a memory structure that allows us to associate each unique number with a counter.
2. An `unordered_map` serves as a lookup dictionary where the key is the number and the value is its frequency.
3. As we iterate through the array, for every element `x`, we increase its counter in the map (`f[x]++`).
4. Finally, we iterate through the map to output each number and its compiled count.

---

## Approaches

### 1. Documented Solution (Hashing with `unordered_map`)
*   **Concept:** Iterate through the array once to build the frequency map `f`. The map dynamically creates keys as new elements are visited. Output the results by iterating through the map.
*   **Time Complexity:** $\mathcal{O}(N)$ average (since hash table insertions/lookups take $\mathcal{O}(1)$ average time).
*   **Space Complexity:** $\mathcal{O}(N)$ (to store up to $N$ unique keys in the hash table).

### 2. Alternative Approach (Brute Force using Nested Loops)
*   **Concept:** Use two nested loops. The outer loop selects an element, and the inner loop scans the rest of the array to count its occurrences. To avoid printing duplicates, mark visited elements in a parallel boolean array.
*   **Time Complexity:** $\mathcal{O}(N^2)$
*   **Space Complexity:** $\mathcal{O}(N)$ (for visited array).
*   **Drawback:** Suboptimal for larger arrays.

### 3. Alternative Approach (Sorting)
*   **Concept:** Sort the array first. Equal elements will be grouped adjacently. Scan the sorted array linearly, counting consecutive identical elements and printing their counts when the element changes.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to sorting).
*   **Space Complexity:** $\mathcal{O}(1)$ if sorted in-place.

---

## Algorithm (Documented Solution)
1. Declare a global hash map `f`.
2. Define function `freq(nums)`:
   * Loop through each element `x` in the array `nums`:
     * Increment `f[x]` by 1.
3. In `main()`:
   * Populate test input `nums`.
   * Call `freq(nums)`.
   * Iterate through the hash map `f`:
     * Print the element (`it.first`) and its count (`it.second`).

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 2, 3, 2, 1, 4, 2, 5}`

*   Initial State: `f` is empty.

| Iteration | Element `x` | Action | Hash Map `f` State |
| :--- | :--- | :--- | :--- |
| 1 | 1 | `f[1]++` | `{1: 1}` |
| 2 | 2 | `f[2]++` | `{1: 1, 2: 1}` |
| 3 | 3 | `f[3]++` | `{1: 1, 2: 1, 3: 1}` |
| 4 | 2 | `f[2]++` | `{1: 1, 2: 2, 3: 1}` |
| 5 | 1 | `f[1]++` | `{1: 2, 2: 2, 3: 1}` |
| 6 | 4 | `f[4]++` | `{1: 2, 2: 2, 3: 1, 4: 1}` |
| 7 | 2 | `f[2]++` | `{1: 2, 2: 3, 3: 1, 4: 1}` |
| 8 | 5 | `f[5]++` | `{1: 2, 2: 3, 3: 1, 4: 1, 5: 1}` |

**Output Order (depending on hash ordering):**
*   `1 -> 2`
*   `2 -> 3`
*   `3 -> 1`
*   `4 -> 1`
*   `5 -> 1`

---

## Why This Works (Correctness)
The hash map behaves as an associative array. On `f[x]++`, if key `x` does not exist, standard C++ `std::unordered_map` default-initializes the value to `0` and then increments it to `1`. If the key already exists, it directly updates the value. This guarantees that every element is accounted for and counted correctly in a single pass.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ average — Single pass of size $N$ to build the map, and printing takes time proportional to the number of unique elements (at most $N$).
*   **Space Complexity:** $\mathcal{O}(N)$ — The map holds at most $N$ unique elements.

---

## Edge Cases
1.  **Empty array:** Map remains empty, nothing is printed. Correct.
2.  **All elements identical:** Map will contain only 1 key with value $N$. Correct.
3.  **All elements distinct:** Map will contain $N$ keys, each with value `1`. Correct.
4.  **Negative/Large numbers:** Unordered map handles keys of any integer range naturally (unlike frequency arrays which are limited by index boundaries).

---

## Common Mistakes
*   **Using frequency arrays for large values:** If the array contains elements like `10^9`, allocating `arr[10^9]` will cause a memory limit exceeded (MLE) error. Always use hash maps unless input bounds are small (e.g., $1 \le nums[i] \le 10^5$).
*   **Printing duplicates:** When using brute force, students often print the frequency of duplicate elements multiple times.

---

## Similar Questions
*   Find the most frequent / least frequent element in an array.
*   Find elements that appear more than $N/2$ times (Majority Element).
*   Find all duplicate elements in an array.

---

## Interview Tips & Insights
*   **`unordered_map` vs `map`:** Be ready for the follow-up: *"What is the difference between map and unordered_map in C++?"*
    *   `std::unordered_map` uses a hash table, providing $\mathcal{O}(1)$ average time complexity for insertions and lookups. Elements are printed in arbitrary order.
    *   `std::map` uses a Red-Black Tree, providing $\mathcal{O}(\log N)$ time complexity. Elements are printed in sorted order of their keys.
*   **Space-Time Trade-off:** Explain that hashing trading auxiliary space ($\mathcal{O}(N)$) to achieve optimal time complexity ($\mathcal{O}(N)$).

---

## Revision Notes (1-Minute Quick Check)
*   **Structure:** `unordered_map<int, int> f;`
*   **Population:** `for(int x : nums) f[x]++;`
*   **Lookup/Print:** `for(auto it : f) cout << it.first << " -> " << it.second;`
*   **Complexity:** Time: $\mathcal{O}(N)$ average | Space: $\mathcal{O}(N)$.

---

## Key Takeaways
1.  Hashing is the go-to technique for frequency and existence tracking.
2.  `std::unordered_map` provides average constant-time operations, but watch out for the $\mathcal{O}(N)$ worst-case behavior during hash collisions.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Reverse Array](../004_reverse_array/README.md) | **Next:** None (Last) |
<!-- navigation -->
