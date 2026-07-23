# Reverse Array

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Two Pointers`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Reversing an array or string is a fundamental building block for many coding problems (like reversing parts of an array to rotate it, or checking for palindromes). It is extremely common in TCS coding tests.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Two Pointers** pattern.
*   **When to use:** Whenever you need to swap, compare, or process elements from opposite ends of a linear collection moving towards the center.
*   **Core signature:** Initialize two index pointers, one at the start (`i = 0`) and one at the end (`j = N-1`). In a loop, swap their elements and step them closer (`i++`, `j--`) until they meet or cross (`i >= j`).

---

## Intuition
To reverse a sequence, the first element must swap with the last element, the second with the second-to-last, and so on:
1. Place a pointer at the beginning (`i`) and another at the end (`j`).
2. Swap the elements at `i` and `j`.
3. Increment `i` and decrement `j`.
4. Repeat this process until `i` and `j` meet or cross in the middle. At that point, the entire collection is reversed in-place.

---

## Approaches

### 1. Documented Solution (In-Place Swap with Two Pointers)
*   **Concept:** Use two indexes starting at opposite ends. Keep swapping `nums[i]` and `nums[j]`, incrementing `i` and decrementing `j` in a `while(i < j)` loop.
*   **Time Complexity:** $\mathcal{O}(N)$ (iterates $N/2$ times).
*   **Space Complexity:** $\mathcal{O}(1)$ (modifies the input vector directly).

### 2. Alternative Approach (Using a Stack / Auxiliary Space)
*   **Concept:** Push all elements of the array onto a stack, then pop them one-by-one to overwrite the array from start to end (or construct a new reversed array).
*   **C++ Implementation:**
    ```cpp
    vector<int> reverseUsingStack(vector<int>& nums) {
        stack<int> s;
        for(int x : nums) s.push(x);
        for(int i = 0; i < nums.size(); ++i) {
            nums[i] = s.top();
            s.pop();
        }
        return nums;
    }
    ```
*   **Drawback:** Requires $\mathcal{O}(N)$ auxiliary space for the stack, which is suboptimal compared to the $\mathcal{O}(1)$ in-place swap.

### 3. Alternative Approach (C++ STL Standard Library)
*   **Concept:** Use the standard standard library function `std::reverse`.
*   **C++ Implementation:**
    ```cpp
    #include <algorithm>
    // inside function:
    std::reverse(nums.begin(), nums.end());
    ```

---

## Algorithm (Documented Solution)
1. Initialize pointer `i = 0`.
2. Find the size of the array `n` and initialize pointer `j = n - 1`.
3. While `i < j`:
   * Swap `nums[i]` and `nums[j]`.
   * Increment `i` by 1.
   * Decrement `j` by 1.
4. Return the reversed array `nums`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 2, 3, 4, 5}`

*   Initial State: `i = 0`, `n = 5`, `j = 4`

| Step | Pointer `i` | Pointer `j` | Condition `i < j` | Action Taken | Array State |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | 0 | 4 | - | - | `{1, 2, 3, 4, 5}` |
| 1 | 0 | 4 | $0 < 4$ (True) | Swap `nums[0]` & `nums[4]`; `i++`, `j--` | `{5, 2, 3, 4, 1}` |
| 2 | 1 | 3 | $1 < 3$ (True) | Swap `nums[1]` & `nums[3]`; `i++`, `j--` | `{5, 4, 3, 2, 1}` |
| 3 | 2 | 2 | $2 < 2$ (False)| Loop terminates | `{5, 4, 3, 2, 1}` |

**Output:** `5 4 3 2 1`

---

## Why This Works (Correctness)
Swapping symmetric elements `nums[i]` and `nums[n - 1 - i]` ensures that elements equidistant from the boundaries exchange positions. By stopping when `i >= j` (which is the middle of the array), we ensure that each pair is swapped exactly once. If we kept running beyond the midpoint, we would swap the elements back to their original positions.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — We iterate $N/2$ times, which performs $N/2$ swaps.
*   **Space Complexity:** $\mathcal{O}(1)$ — The algorithm reverses the array in-place without allocating auxiliary lists or structures.

---

## Edge Cases
1.  **Array of size 0 or 1:** `i < j` is false immediately, so the loop does not run. Returns the array unmodified. Correct.
2.  **Even size array:** E.g., `nums = {1, 2, 3, 4}`. Pointers meet at index `1` and `2`, swap, then cross. Reverses correctly.
3.  **Odd size array:** E.g., `nums = {1, 2, 3, 4, 5}`. Middle element index `2` is not swapped since `i == j` evaluates to false. Reverses correctly.

---

## Common Mistakes
*   **Reversing Twice:** Running the loop up to `n - 1` instead of meeting in the middle (`i < j`). If you loop through the entire array swapping elements, you will swap them back to their original configuration.
*   **Off-by-One Pointer Initialization:** Initializing `j = n` instead of `j = n - 1`, leading to an out-of-bounds memory access.

---

## Similar Questions
*   Reverse a string.
*   Reverse a sub-array (e.g. from index `L` to `R`).
*   Rotate an array by `K` positions (solved by reversing parts of the array).

---

## Interview Tips & Insights
*   **Key Question:** Interviewers often ask to reverse an array *without* using any extra memory. Be sure to point out that the two-pointer approach satisfies this with $\mathcal{O}(1)$ auxiliary space.
*   **Array Rotation Connection:** Know how this is used to rotate an array: To rotate left by `K` elements, reverse `nums[0...K-1]`, reverse `nums[K...N-1]`, and then reverse the entire array `nums[0...N-1]`.

---

## Revision Notes (1-Minute Quick Check)
*   **Logic:** Two pointers `i = 0` and `j = n - 1`.
*   **Loop condition:** `while (i < j)`.
*   **Body:** `swap(nums[i], nums[j]); i++; j--;`
*   **Complexity:** Time: $\mathcal{O}(N)$ | Space: $\mathcal{O}(1)$ (in-place).

---

## Key Takeaways
1.  In-place reversal via two pointers is the most memory-efficient approach.
2.  Be careful with loop boundaries to avoid double-reversing.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Second Smallest and Second Largest](../003_sec_big_sec_small/README.md) | **Next:** None (Last) |
<!-- navigation -->
