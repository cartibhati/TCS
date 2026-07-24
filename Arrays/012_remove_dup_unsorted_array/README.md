# Remove Duplicates from Unsorted Array

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Hashing`, `Hash Set`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** A direct progression from the sorted version. Unlike the sorted version, duplicates are not adjacent, requiring hash-based lookups or sorting. Tests understanding of hash sets and order preservation.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Hashing / Set Uniqueness** pattern.
*   **When to use:** When you need to filter duplicates from a collection where the elements can appear in any arbitrary order, and you need to perform fast lookups to check if an element was already processed.
*   **Core signature:** Maintain a hash-based lookup structure (e.g., `std::unordered_set` in C++) to store already-seen elements.

---

## Intuition
To remove duplicates from an unsorted array while maintaining their original relative order (the order of their first occurrence):
1. We cannot rely on adjacent comparisons because duplicates may be far apart.
2. We use a hash set `s` to keep track of all unique numbers we have seen so far.
3. We iterate through the array element by element.
4. For each element `x`, if it is not present in `s`, we add it to both our hash set `s` and our result vector `ans`.
5. If it is already in `s`, we simply skip it.

---

## Approaches

### 1. Documented Solution (Hash Set & Auxiliary List)
*   **Concept:** Iterate through the array, using `unordered_set::find` to check if the current element is a duplicate in $\mathcal{O}(1)$ average time. If not, insert it into the set and append it to `ans`. Preserves relative order.
*   **Time Complexity:** $\mathcal{O}(N)$ average time.
*   **Space Complexity:** $\mathcal{O}(N)$ auxiliary space (for the hash set and result array).

### 2. Sorting-Based Approach (If Order Preservation is NOT Required)
*   **Concept:** Sort the array first, which groups duplicates together. Then use the two-pointer in-place duplicate removal.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to sorting).
*   **Space Complexity:** $\mathcal{O}(1)$ (if sorted in-place, neglecting recursion stack).
*   **Drawback:** Alters the original order of elements.

### 3. Brute Force Approach (Double Loop)
*   **Concept:** For each element, scan all previous elements to check if it has already appeared. If not, add it to the result list.
*   **Time Complexity:** $\mathcal{O}(N^2)$ (due to nested loops).
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.

---

## Algorithm (Documented Solution)
1. Initialize an empty `unordered_set<int> s` and an empty vector `ans`.
2. For each element `x` in the input array `nums`:
   * If `s.find(x) == s.end()` (meaning `x` is not in the set):
     * Insert `x` into `s`.
     * Push `x` to `ans`.
3. Return `ans`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 1, 2, 2, 2, 3, 3}`

| Step | Element (`x`) | Set State (`s`) | Seen? (`s.find(x) != s.end()`) | Action | Result State (`ans`) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | `{}` | - | - | `{}` |
| 1 | 1 | `{1}` | False $\rightarrow$ Unique | Insert to `s`, push to `ans` | `{1}` |
| 2 | 1 | `{1}` | True $\rightarrow$ Duplicate | Skip | `{1}` |
| 3 | 2 | `{1, 2}` | False $\rightarrow$ Unique | Insert to `s`, push to `ans` | `{1, 2}` |
| 4 | 2 | `{1, 2}` | True $\rightarrow$ Duplicate | Skip | `{1, 2}` |
| 5 | 2 | `{1, 2}` | True $\rightarrow$ Duplicate | Skip | `{1, 2}` |
| 6 | 3 | `{1, 2, 3}` | False $\rightarrow$ Unique | Insert to `s`, push to `ans` | `{1, 2, 3}` |
| 7 | 3 | `{1, 2, 3}` | True $\rightarrow$ Duplicate | Skip | `{1, 2, 3}` |

**Output:** `{1, 2, 3}`

---

## Why This Works (Correctness)
The hash set serves as a perfect memory of all elements visited. Since search and insertion in a hash set operate in average $\mathcal{O}(1)$ time, we can determine whether any element has been encountered before almost instantly. The result list `ans` is built sequentially, ensuring that the first occurrence of each unique element is added in its original order.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ average time — We iterate through the array of size $N$ once, performing constant-time hash set operations. (Worst-case time complexity is $\mathcal{O}(N^2)$ if there are excessive hash collisions, but this is rare).
*   **Space Complexity:** $\mathcal{O}(N)$ — In the worst case (all unique elements), the hash set and output vector will store $N$ elements.

---

## Edge Cases
1.  **Empty Array:** The loop does not execute; returns an empty vector. Correct.
2.  **All Unique Elements:** E.g., `nums = {1, 2, 3}`. The set records all elements, and the result vector is a copy of the input. Correct.
3.  **All Duplicate Elements:** E.g., `nums = {5, 5, 5}`. Set keeps `{5}`, returns `{5}`. Correct.

---

## Common Mistakes
*   **Assuming input is sorted:** Trying to use adjacent pointer comparison (like `nums[i] != nums[i-1]`) on an unsorted array will fail to catch duplicates that are separated.
*   **Using `std::set` instead of `std::unordered_set`:** `std::set` is implemented as a Red-Black Tree, yielding $\mathcal{O}(N \log N)$ complexity. `std::unordered_set` uses hashing and yields $\mathcal{O}(N)$ average complexity.

---

## Similar Questions
*   Find duplicates in an unsorted array.
*   First unique character in a string.
*   Intersection/Union of two unsorted arrays.

---

## Interview Tips & Insights
*   **Trade-off explanation:** Be ready to explain the time/space trade-off. Using a hash set takes $\mathcal{O}(N)$ space but gives optimal $\mathcal{O}(N)$ time. Sorting first takes $\mathcal{O}(1)$ auxiliary space but takes $\mathcal{O}(N \log N)$ time and ruins the relative order.
*   **Order preservation:** Always check if preserving the original order of elements is required by the problem statement.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Remove duplicate elements from an unsorted array while maintaining relative order.
*   **Strategy:** Hashing with `unordered_set`.
*   **Complexity:** Time: $\mathcal{O}(N)$ average | Space: $\mathcal{O}(N)$.
*   **Alternate:** Sort the array if order doesn't matter and space must be $\mathcal{O}(1)$.

---

## Key Takeaways
1.  Unsorted duplicate filtering requires a lookup structure like a hash set to achieve linear time.
2.  `std::unordered_set` is preferred over `std::set` in C++ for hashing-based average $\mathcal{O}(1)$ operations.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Remove Duplicates from Sorted Array](../011_remove_dup_in_sorted/README.md) | **Next:** [Next: Adding Elements in an Array →](../013_Adding_elements_in_array/README.md) |
| <!-- navigation -->
