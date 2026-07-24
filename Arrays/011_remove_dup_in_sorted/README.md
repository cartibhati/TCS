# Remove Duplicates from Sorted Array

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Two Pointers`, `In-Place`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** A classic interview problem that tests list manipulation, in-place updates, and optimization (avoiding extra space). Excellent benchmark for evaluating basic two-pointer techniques.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Two Pointers (Slow & Fast)** pattern.
*   **When to use:** When you need to filter or modify elements of a sorted collection in-place, keeping unique elements at the front of the collection.
*   **Core signature:** Maintain a "slow" pointer (`i`) representing the end of the unique prefix, and a "fast" pointer (`j`) that scans forward to find new unique elements.

---

## Intuition
Because the input array is sorted, any duplicate elements will be adjacent to each other.
1. We can maintain a pointer `i` that points to the last unique element found.
2. We scan the array with a pointer `j` from index 1 to the end.
3. Whenever we find an element `nums[j]` that is not equal to `nums[i]`, we have found a new unique element. We increment `i` and write `nums[j]` at index `i`.
4. After traversing the whole array, the elements up to index `i` (inclusive) will be the unique values, and the count of unique elements will be `i + 1`.

---

## Approaches

### 1. Documented Solution (In-Place Two Pointers)
*   **Concept:** Use index `i` as the slow pointer to track unique elements, and `j` as the fast pointer to scan. Since we process the array in-place, the auxiliary space is constant.
*   **Time Complexity:** $\mathcal{O}(N)$ (single pass over the array).
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.

### 2. Standard Library Approach (Using `std::unique`)
*   **Concept:** C++ STL provides a built-in algorithm `std::unique` that removes consecutive duplicates in-place and returns an iterator to the end of the unique range.
*   **C++ Implementation:**
    ```cpp
    #include <algorithm>
    #include <vector>

    int removeDuplicatesSTL(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        auto it = std::unique(nums.begin(), nums.end());
        return std::distance(nums.begin(), it);
    }
    ```

### 3. Naive / Brute Force Approach (Using an Auxiliary Set)
*   **Concept:** Insert all elements into a hash set or tree set (like `std::set`), which automatically removes duplicates. Then, copy the elements back to the beginning of the array.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to set insertion).
*   **Space Complexity:** $\mathcal{O}(N)$ auxiliary space (to store elements in the set).
*   **Drawback:** Not space-efficient; fails the in-place constraint.

---

## Algorithm (Documented Solution)
1. If the array is empty, return `0`.
2. Initialize slow pointer `i = 0`.
3. Loop fast pointer `j` from `1` to `nums.size() - 1`:
   * If `nums[i] != nums[j]`:
     * Increment `i` by 1.
     * Copy `nums[j]` to `nums[i]`.
4. Return `i + 1`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 1, 2, 2, 2, 3, 3}`

| Step | slow pointer (`i`) | fast pointer (`j`) | Comparison (`nums[i] != nums[j]`) | Action | Array State |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | 0 | - | - | - | `{1, 1, 2, 2, 2, 3, 3}` |
| 1 | 0 | 1 | `nums[0] != nums[1]` ($1 \neq 1$) $\rightarrow$ False | None | `{1, 1, 2, 2, 2, 3, 3}` |
| 2 | 0 | 2 | `nums[0] != nums[2]` ($1 \neq 2$) $\rightarrow$ True | `i++` (1), `nums[1] = nums[2]` | `{1, 2, 2, 2, 2, 3, 3}` |
| 3 | 1 | 3 | `nums[1] != nums[3]` ($2 \neq 2$) $\rightarrow$ False | None | `{1, 2, 2, 2, 2, 3, 3}` |
| 4 | 1 | 4 | `nums[1] != nums[4]` ($2 \neq 2$) $\rightarrow$ False | None | `{1, 2, 2, 2, 2, 3, 3}` |
| 5 | 1 | 5 | `nums[1] != nums[5]` ($2 \neq 3$) $\rightarrow$ True | `i++` (2), `nums[2] = nums[5]` | `{1, 2, 3, 2, 2, 3, 3}` |
| 6 | 2 | 6 | `nums[2] != nums[6]` ($3 \neq 3$) $\rightarrow$ False | None | `{1, 2, 3, 2, 2, 3, 3}` |

*   **Result count:** `i + 1` = `2 + 1` = `3`.
*   **First 3 elements:** `{1, 2, 3}`.
*   **Output:** `3`

---

## Why This Works (Correctness)
Because the array is sorted, duplicates are grouped sequentially. The pointer `i` always marks the boundary of the unique prefix segment we've constructed. Whenever `j` encounters a value different from the boundary `nums[i]`, it is guaranteed to be a new unique element because it is strictly greater than all elements seen so far. Placing it at `i + 1` extends our unique prefix correctly.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — The fast pointer `j` scans the array of size $N$ exactly once.
*   **Space Complexity:** $\mathcal{O}(1)$ — No extra vectors or memory are allocated; the modification is done completely in-place.

---

## Edge Cases
1.  **Empty Array:** Handled correctly by checking `if (nums.empty()) return 0;`.
2.  **No Duplicates:** E.g., `nums = {1, 2, 3}`. The check `nums[i] != nums[j]` is always true. `i` increments alongside `j`, elements are copied onto themselves, and the function returns the original size. Correct.
3.  **All Duplicates:** E.g., `nums = {2, 2, 2, 2}`. The check is never true. `i` remains `0`. Returns `1` with the array starting with `{2}`. Correct.

---

## Common Mistakes
*   **Using a Set/Map unnecessarily:** Set operations add $\mathcal{O}(N)$ space complexity and $\mathcal{O}(N \log N)$ time complexity, which are suboptimal.
*   **Not checking for empty inputs:** If `nums` is empty, reading `nums[i]` or `nums[0]` triggers out-of-bound errors.

---

## Similar Questions
*   Remove Duplicates from Sorted Array II (allowing duplicates up to 2 times).
*   Remove Element in-place.
*   Move Zeroes to the end of the array.

---

## Interview Tips & Insights
*   **Clarify In-Place:** Make sure you confirm whether you need to modify the array in-place or if you can return a new array. Interviewers usually ask this to test memory management awareness.
*   **Mention two pointers:** Be explicit about using a "slow runner, fast runner" two-pointer strategy.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Remove duplicate elements from a sorted array in-place.
*   **Strategy:** Two pointers. `i` stores unique element boundary, `j` scans.
*   **Formula:** `if (nums[i] != nums[j]) { i++; nums[i] = nums[j]; }`
*   **Complexity:** Time: $\mathcal{O}(N)$ | Space: $\mathcal{O}(1)$ (in-place).

---

## Key Takeaways
1.  A sorted array guarantees duplicates are adjacent, making two pointers optimal.
2.  In-place modification saves memory allocation time and memory overhead.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Find Median of the Array](../010_Median_of_array/README.md) | **Next:** None (Last) |
| <!-- navigation -->
