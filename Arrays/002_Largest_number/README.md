# Find Largest Number

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Linear Scan`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Foundational array-scanning problem. Frequently appears in the coding section of TCS NQT and Ninja exams, often as the first question or as a subproblem.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported (derived from student placement records).

---

## Pattern Recognition
This problem belongs to the **Linear Scan (Single-Pass)** pattern. 
*   **When to use:** Whenever you need to find a global optimum (e.g., maximum, minimum) in an unsorted array.
*   **Core signature:** Maintain a running state variable (`ans`) and update it as you examine each element of the array exactly once.

---

## Intuition
To find the largest element in an unsorted collection of size $N$, we must look at every element at least once.
1. Initialize a variable `ans` with the smallest possible integer value (`INT_MIN`) to guarantee that any element in the array will be larger than or equal to it on the first comparison.
2. Traverse the array element-by-element.
3. Compare the current element with our recorded maximum, updating our tracker whenever a larger value is encountered.

---

## Approaches

### 1. Documented Solution (Linear Scan with Double Guard)
*   **Concept:** Scan the array from index `0` to `N-1`. Initialize `ans = INT_MIN`. During traversal, the code checks `if (nums[i] > ans)` to assign `ans = nums[i]`, and additionally applies `ans = max(ans, nums[i])` for safety.
*   **Time Complexity:** $\mathcal{O}(N)$ (every element visited exactly once).
*   **Space Complexity:** $\mathcal{O}(1)$ (only a single integer variable used for tracking).

### 2. Alternative Optimized Approach (Cleaner Linear Scan)
*   **Concept:** To avoid redundant comparisons (both the conditional block and the `max()` function), initialize `ans` directly to the first element `nums[0]` (if non-empty) and iterate from index `1` onwards with a single comparison.
*   **C++ Implementation:**
    ```cpp
    int largest(const vector<int>& nums) {
        if (nums.empty()) return -1; // Or handle error
        int ans = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > ans) {
                ans = nums[i];
            }
        }
        return ans;
    }
    ```

### 3. Brute Force (Sorting)
*   **Concept:** Sort the array in ascending order. The last element (`nums[N-1]`) will be the maximum.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to sorting algorithms like Quicksort or Mergesort).
*   **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(N)$ depending on the language's sorting implementation.
*   **Drawback:** Sorting does unnecessary work. We do not need the entire array ordered, only the single largest element.

---

## Algorithm (Documented Solution)
1. Initialize `ans` to `INT_MIN`.
2. Loop through the array from index `0` to `N-1`.
3. Inside the loop, for each index `i`:
   * If `nums[i] > ans`, set `ans = nums[i]`.
   * Re-evaluate `ans = max(ans, nums[i])`.
4. Return `ans`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {4, 3, 5, 67, 2, 78, 8}`

| Step | Index ($i$) | Current Element (`nums[i]`) | Step A: `if (nums[i] > ans)` | Step B: `ans = max(ans, nums[i])` | Running `ans` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | - | - | - | **-2147483648 (INT_MIN)** |
| 1 | 0 | 4 | $4 > \text{INT\_MIN}$ (True) $\rightarrow$ `ans` = 4 | `max(4, 4)` $\rightarrow$ `ans` = 4 | **4** |
| 2 | 1 | 3 | $3 > 4$ (False) | `max(4, 3)` $\rightarrow$ `ans` = 4 | **4** |
| 3 | 2 | 5 | $5 > 4$ (True) $\rightarrow$ `ans` = 5 | `max(5, 5)` $\rightarrow$ `ans` = 5 | **5** |
| 4 | 3 | 67 | $67 > 5$ (True) $\rightarrow$ `ans` = 67 | `max(67, 67)` $\rightarrow$ `ans` = 67 | **67** |
| 5 | 4 | 2 | $2 > 67$ (False) | `max(67, 2)` $\rightarrow$ `ans` = 67 | **67** |
| 6 | 5 | 78 | $78 > 67$ (True) $\rightarrow$ `ans` = 78 | `max(78, 78)` $\rightarrow$ `ans` = 78 | **78** |
| 7 | 6 | 8 | $8 > 78$ (False) | `max(78, 8)` $\rightarrow$ `ans` = 78 | **78** |

**Output:** `78`

---

## Why This Works (Correctness)
Because the array is unsorted, any element could potentially be the maximum. Therefore, any correct algorithm must inspect all $N$ elements. By maintaining the invariant that `ans` is the maximum of all prefix elements `nums[0...i]`, by mathematical induction, when $i = N-1$, `ans` is the maximum of the entire array.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — We traverse the array of size $N$ exactly once.
*   **Space Complexity:** $\mathcal{O}(1)$ — We only allocate a single variable `ans` to store the maximum value.

---

## Edge Cases
1.  **Array of size 1:** E.g., `nums = {5}`. Loop runs once for $i = 0$, updates `ans` to `5`, and returns `5`. Correct.
2.  **All negative numbers:** E.g., `nums = {-5, -2, -10, -1}`. Initialized to `INT_MIN`. Updates to `-5`, then to `-2` and finally `-1` correctly. (This is why initializing `ans = 0` fails).
3.  **Duplicate maximums:** E.g., `nums = {78, 5, 78, 3}`. Correctly returns `78`.
4.  **Empty array:** The loop does not execute; returns `INT_MIN`.

---

## Common Mistakes
*   **Wrong Initialization:** Initializing `ans = 0`. If the array contains all negative numbers like `{-5, -12, -3}`, the program will return `0`, which is incorrect because `0` is not in the array and is greater than all elements. Always initialize to `INT_MIN` or `nums[0]`.
*   **Redundant sorting:** Sorting the array first. While it works, it is computationally less efficient ($\mathcal{O}(N \log N)$ vs. $\mathcal{O}(N)$).

---

## Similar Questions
*   Find the minimum element in an array.
*   Find the second smallest and second largest elements in an array.
*   Find the range of an array (Max element - Min element).

---

## Interview Tips & Insights
*   **What is tested:** Loops, array scanning, handling edge cases (like empty/single-element arrays), and optimization awareness (linear scan vs sorting).
*   **Follow-up to expect:** *"Can you find both the minimum and maximum in the minimum number of comparisons?"* (Optimal comparison count is $\approx 1.5N$ comparisons by comparing elements in pairs rather than comparing every element to both min and max).
*   **Explain your steps:** Discuss the time complexity of sorting vs linear scan first to show algorithmic efficiency.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Find the largest element.
*   **Formula:** `ans = max(ans, nums[i])`.
*   **Initialization:** `ans = INT_MIN`.
*   **Time:** $\mathcal{O}(N)$ | **Space:** $\mathcal{O}(1)$.
*   **Caution:** Handle negative numbers correctly by initializing with `INT_MIN` or the first array element, never `0`.

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
| **Prev:** [← Prev: Find Minimum Element](../001_Find_Minimum_Element/README.md) | **Next:** [Next: Second Smallest and Second Largest →](../003_sec_big_sec_small/README.md) |
<!-- navigation -->
