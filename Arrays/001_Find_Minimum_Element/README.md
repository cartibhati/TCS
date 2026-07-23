# Find Minimum Element

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Linear Scan`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Foundational array-scanning problem. Frequently appears either as a standalone starter problem or as a sub-routine in more complex array manipulation tasks.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported (based on placement prep resources and student interview logs).

---

## Pattern Recognition
This problem belongs to the **Linear Scan (Single-Pass)** pattern. 
*   **When to use:** Whenever you need to find a global optimum (e.g., min, max, second min, peak) in an unsorted array where every element must be examined.
*   **Core signature:** Keep a running state variable (`ans`) and update it as you examine each element of the array exactly once.

---

## Intuition
To find the smallest element in an unsorted collection of size $N$, we must look at every element at least once.
1. Initialize a variable `ans` with a very large value (`INT_MAX`) to guarantee that any element in the array will be smaller than or equal to it on the first comparison.
2. Traverse the array element-by-element.
3. Compare the current element with our recorded minimum, updating our tracker whenever a smaller value is encountered.

---

## Approaches

### 1. Documented Solution (Linear Scan with Double Guard)
*   **Concept:** Scan the array from index `0` to `N-1`. Initialize `ans = INT_MAX`. During traversal, the code checks `if (nums[i] < ans)` to assign `ans = nums[i]`, and additionally applies `ans = min(ans, nums[i])` for safety.
*   **Time Complexity:** $\mathcal{O}(N)$ (every element visited exactly once).
*   **Space Complexity:** $\mathcal{O}(1)$ (only a single integer variable used for tracking).

### 2. Alternative Optimized Approach (Cleaner Linear Scan)
*   **Concept:** To avoid redundant comparisons (both the conditional block and the `min()` function), initialize `ans` directly to the first element `nums[0]` (if non-empty) and iterate from index `1` onwards with a single comparison.
*   **C++ Implementation:**
    ```cpp
    int smallest(const vector<int>& nums) {
        if (nums.empty()) return -1; // Or throw error
        int ans = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < ans) {
                ans = nums[i];
            }
        }
        return ans;
    }
    ```

### 3. Brute Force (Sorting)
*   **Concept:** Sort the array in ascending order. The first element (`nums[0]`) will be the minimum.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to sorting algorithms like Quicksort or Mergesort).
*   **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(N)$ depending on the language's sorting implementation.
*   **Drawback:** Sorting does unnecessary work. We do not need the entire array ordered, only the single smallest element.

---

## Algorithm (Documented Solution)
1. Initialize `ans` to `INT_MAX`.
2. Loop through the array from index `0` to `N-1`.
3. Inside the loop, for each index `i`:
   * If `nums[i] < ans`, set `ans = nums[i]`.
   * Re-evaluate `ans = min(ans, nums[i])`.
4. Return `ans`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {4, 3, 5, 67, 2, 78, 8}`

| Step | Index ($i$) | Current Element (`nums[i]`) | Step A: `if (nums[i] < ans)` | Step B: `ans = min(ans, nums[i])` | Running `ans` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | - | - | - | **2147483647 (INT_MAX)** |
| 1 | 0 | 4 | $4 < \text{INT\_MAX}$ (True) $\rightarrow$ `ans` = 4 | `min(4, 4)` $\rightarrow$ `ans` = 4 | **4** |
| 2 | 1 | 3 | $3 < 4$ (True) $\rightarrow$ `ans` = 3 | `min(3, 3)` $\rightarrow$ `ans` = 3 | **3** |
| 3 | 2 | 5 | $5 < 3$ (False) | `min(3, 5)` $\rightarrow$ `ans` = 3 | **3** |
| 4 | 3 | 67 | $67 < 3$ (False) | `min(3, 67)` $\rightarrow$ `ans` = 3 | **3** |
| 5 | 4 | 2 | $2 < 3$ (True) $\rightarrow$ `ans` = 2 | `min(2, 2)` $\rightarrow$ `ans` = 2 | **2** |
| 6 | 5 | 78 | $78 < 2$ (False) | `min(2, 78)` $\rightarrow$ `ans` = 2 | **2** |
| 7 | 6 | 8 | $8 < 2$ (False) | `min(2, 8)` $\rightarrow$ `ans` = 2 | **2** |

**Output:** `2`

---

## Why This Works (Correctness)
Because the array is unsorted, any element could potentially be the minimum. Therefore, any correct algorithm must inspect all $N$ elements. By maintaining the invariant that `ans` is the minimum of all prefix elements `nums[0...i]`, by mathematical induction, when $i = N-1$, `ans` is the minimum of the entire array.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — We traverse the array of size $N$ exactly once.
*   **Space Complexity:** $\mathcal{O}(1)$ — We only allocate a single variable `ans` to store the minimum value.

---

## Edge Cases
1.  **Array of size 1:** E.g., `nums = {5}`. Loop runs once for $i = 0$, updates `ans` to `5`, and returns `5`. Correct.
2.  **All negative numbers:** E.g., `nums = {-5, -2, -10, -1}`. Initialized to `INT_MAX`. Updates to `-5`, then `-10` correctly.
3.  **Duplicate minimums:** E.g., `nums = {2, 5, 2, 3}`. Correctly returns `2`.
4.  **Empty array:** The loop does not execute; returns `INT_MAX`. (Note: In robust production code, checking `nums.empty()` beforehand is recommended).

---

## Common Mistakes
*   **Wrong Initialization:** Initializing `ans = 0`. If the array contains `{5, 12, 3}`, the program will return `0`, which is incorrect because `0` is not in the array. Always initialize to `INT_MAX` or `nums[0]`.
*   **Redundant sorting:** Sorting the array first. While it works, it shows lack of optimization awareness to the interviewer.

---

## Similar Questions
*   Find the maximum element in an array.
*   Find the second smallest and second largest elements in an array (Very common TCS variant).
*   Find the range of an array (Max element - Min element).

---

## Interview Tips & Insights
*   **What is tested:** Basic loops, array indexing, handling edge cases (like empty/single-element arrays), and optimization awareness (linear scan vs sorting).
*   **Follow-up to expect:** *"Can you find both the minimum and maximum in the minimum number of comparisons?"* (Optimal comparison count is $\approx 1.5N$ comparisons by comparing elements in pairs rather than comparing every element to both min and max).
*   **Explain your steps:** Explain why sorting is suboptimal ($\mathcal{O}(N \log N)$) and why a single-pass linear scan is optimal ($\mathcal{O}(N)$) before writing the code.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Find the smallest element.
*   **Formula:** `ans = min(ans, nums[i])`.
*   **Initialization:** `ans = INT_MAX`.
*   **Time:** $\mathcal{O}(N)$ | **Space:** $\mathcal{O}(1)$.
*   **Caution:** Handle empty arrays gracefully and initialize with elements from the array or `INT_MAX`, not arbitrary zeros.

---

## Key Takeaways
1.  Linear scan is optimal when we need to find a single maximum or minimum in an unsorted collection.
2.  Proper initialization is crucial to avoid overflow/underflow or incorrect bounds errors.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** None (First) | **Next:** None (Last) |
<!-- navigation -->
