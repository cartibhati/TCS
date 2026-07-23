# Rearrange Array in Increasing-Decreasing Order

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Sorting`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** A classic array rearrangement problem that tests your understanding of sorting, array partitioning, and using custom comparators. Frequently appears in the TCS Ninja and NQT coding sections.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Sorting & Partial Reversal / Partial Sorting** pattern.
*   **When to use:** Whenever you need to structure parts of an array under different ordering rules (e.g., first half ascending, second half descending).
*   **Core signature:** Sort the array entirely to establish a baseline order, compute partition points (like `mid = N/2`), and selectively sort or reverse subsequent sections.

---

## Intuition
To make the first half of the array increasing and the second half decreasing:
1. If the entire array is sorted in ascending order, the smallest elements end up in the first half and the largest elements in the second half.
2. The first half is already in increasing order.
3. The second half is also in increasing order, but we want it in decreasing order. 
4. Thus, if we reverse or sort the second half in descending order, we satisfy the problem requirement.

---

## Approaches

### 1. Documented Solution (Sort & Reverse-Sort Second Half)
*   **Concept:** Sort the entire copy of the array in ascending order. Identify the midpoint `mid = N/2`. Sort the sub-range starting from `begin() + mid` to `end()` in descending order using `greater<int>()`.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to standard `sort` operations).
*   **Space Complexity:** $\mathcal{O}(N)$ auxiliary space (because the function parameter `vector<int> nums` is passed by value, creating a copy of the input array).

### 2. Alternative Approach (In-Place sorting with Pass-by-Reference)
*   **Concept:** To optimize space complexity to $\mathcal{O}(1)$ auxiliary space, pass the vector by reference `vector<int>& nums`.
*   **C++ Implementation:**
    ```cpp
    void ascdescInPlace(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        sort(nums.begin() + mid, nums.end(), greater<int>());
    }
    ```

---

## Algorithm (Documented Solution)
1. Define function `ascdesc` taking `nums` by value.
2. Sort the entire vector `nums` from start to end in ascending order: `sort(nums.begin(), nums.end())`.
3. Calculate the midpoint index: `mid = nums.size() / 2`.
4. Sort the sub-array from `nums.begin() + mid` to `nums.end()` in descending order: `sort(nums.begin() + mid, nums.end(), greater<int>())`.
5. Return the modified vector `nums`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {8, 7, 1, 6, 5, 9}` (Size $N = 6$)

1.  **Initial State:** `{8, 7, 1, 6, 5, 9}`
2.  **Full Ascending Sort (`sort(nums.begin(), nums.end())`):**
    *   Sorted state: `{1, 5, 6, 7, 8, 9}`
3.  **Midpoint Calculation:**
    *   `mid = 6 / 2 = 3`
    *   The index range for the second half starts at index `3` (value `7`) up to index `5` (value `9`).
4.  **Second Half Descending Sort (`sort(begin + 3, end, greater<int>())`):**
    *   The elements to sort are `{7, 8, 9}`.
    *   Descending sort results in `{9, 8, 7}`.
    *   Resulting vector: `{1, 5, 6, 9, 8, 7}`

**Output:** `1 5 6 9 8 7`

---

## Why This Works (Correctness)
Sorting the entire array first ensures all elements are ordered globally. Since the midpoint divides the array, the first half contains the smallest $N/2$ elements in ascending order, and the second half contains the largest $N/2$ elements. By sorting the second half in descending order, we successfully transition from the largest elements to the smallest ones in that sub-range, satisfying the increasing-decreasing requirement.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N \log N)$ — Sorting the entire array of size $N$ takes $\mathcal{O}(N \log N)$ time. Sorting the second half of size $N/2$ takes $\mathcal{O}((N/2) \log(N/2))$ time. The overall time complexity is dominated by $\mathcal{O}(N \log N)$.
*   **Space Complexity:** $\mathcal{O}(N)$ — The vector parameter is passed by value, creating a complete copy of size $N$ in memory. (Can be optimized to $\mathcal{O}(1)$ auxiliary space if passed by reference).

---

## Edge Cases
1.  **Odd Size Array:** E.g., `nums = {1, 2, 3, 4, 5}` (Size $N = 5$).
    *   `mid = 5 / 2 = 2`.
    *   First half has 2 elements: `nums[0...1]` (`{1, 2}`).
    *   Second half has 3 elements: `nums[2...4]` (`{3, 4, 5}`).
    *   Reversed second half: `{5, 4, 3}`.
    *   Result: `{1, 2, 5, 4, 3}`. Correct.
2.  **Size 0 or 1:** Handled safely by iterator ranges, returns original array.
3.  **Duplicates:** E.g., `nums = {2, 2, 3, 3}`. Re-arranges correctly.

---

## Common Mistakes
*   **Passing by Reference vs Value:** Be aware of the difference. If the interviewer asks for in-place modifications to save memory, pass by reference.
*   **Midpoint Indexing:** Starting the second half at `mid + 1` instead of `mid`. This leaves the element at index `mid` unsorted relative to the second half.

---

## Similar Questions
*   Rearrange array such that even positioned elements are greater than odd.
*   Sort first half in ascending and second half in descending order (identical).
*   Bitonic array manipulations.

---

## Interview Tips & Insights
*   **What is tested:** Basic partitioning logic, working with C++ iterator arithmetic (e.g., `begin() + mid`), custom comparators like `greater<int>()`, and pass-by-value vs pass-by-reference memory impacts.
*   **Key Optimization Note:** Mention that if we want to run this in $\mathcal{O}(N)$ time (for very large inputs), we could use `std::nth_element` to find the median in $\mathcal{O}(N)$, partition the array, and then sort each half. However, for placement assessments, the simple $\mathcal{O}(N \log N)$ sort is completely acceptable and preferred for write speed.

---

## Revision Notes (1-Minute Quick Check)
*   **Step 1:** Sort the entire array ascending.
*   **Step 2:** Find the midpoint `mid = size / 2`.
*   **Step 3:** Sort from `mid` to end with `greater<int>()` comparator.
*   **Complexity:** Time: $\mathcal{O}(N \log N)$ | Space: $\mathcal{O}(N)$ copy (or $\mathcal{O}(1)$ if in-place).

---

## Key Takeaways
1.  Partitioning using C++ iterator additions (like `begin() + mid`) is a clean way to perform operations on specific subsegments of vectors.
2.  Be mindful of odd array sizes during divisions.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Count Frequency of Elements](../005_count_freq/README.md) | **Next:** [Next: Calculate Sum of Elements →](../007_sum_of_elements/README.md) |
<!-- navigation -->
