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
*   **Core signature:** Keep a running state variable (`minVal`) and update it as you examine each element of the array exactly once.

---

## Intuition
To find the smallest element in an unsorted collection of size $N$, we must look at every element at least once. 
1. Assume the first element `nums[0]` is the smallest value we've seen so far.
2. Traverse the rest of the array. If we find an element smaller than our current smallest, update our record.
3. Once we finish the traversal, the recorded value is guaranteed to be the absolute minimum.

---

## Approaches

### 1. Brute Force (Sorting)
*   **Concept:** Sort the array in ascending order. The first element (`nums[0]`) will be the minimum.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to sorting algorithms like Quicksort or Mergesort).
*   **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(N)$ depending on the language's sorting implementation.
*   **Drawback:** Sorting does unnecessary work. We do not need the entire array ordered, only the single smallest element.

### 2. Optimal Approach (Single-Pass Linear Scan)
*   **Concept:** Scan the array from left to right, updating a tracker `minVal` with the minimum of itself and the current element.
*   **Time Complexity:** $\mathcal{O}(N)$ (every element visited exactly once).
*   **Space Complexity:** $\mathcal{O}(1)$ (only a single integer variable used for tracking).

---

## Algorithm (Optimal)
1. If the array is empty, handle the error (e.g., throw an exception or return a sentinel value).
2. Initialize `minVal` to the first element of the array: `minVal = nums[0]`.
3. Loop through the array starting from the second element (index `1`) to the end (`N-1`).
4. At each step `i`, compare `nums[i]` with `minVal`. If `nums[i] < minVal`, update `minVal = nums[i]`.
5. After the loop completes, return `minVal`.

---

## Dry Run
**Input:** `nums = {4, 3, 5, 67, 2, 78, 8}`

| Step | Index ($i$) | Current Element (`nums[i]`) | Comparison (`nums[i] < minVal`) | Running `minVal` | Notes |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | - | - | **4** | Initialized to `nums[0]` |
| 1 | 1 | 3 | $3 < 4$ (True) | **3** | Updated `minVal` |
| 2 | 2 | 5 | $5 < 3$ (False) | **3** | No change |
| 3 | 3 | 67 | $67 < 3$ (False) | **3** | No change |
| 4 | 4 | 2 | $2 < 3$ (True) | **2** | Updated `minVal` |
| 5 | 5 | 78 | $78 < 2$ (False) | **2** | No change |
| 6 | 6 | 8 | $8 < 2$ (False) | **2** | No change |

**Output:** `2`

---

## Why This Works (Correctness)
Because the array is unsorted, any element could potentially be the minimum. Therefore, any correct algorithm must inspect all $N$ elements. By maintaining the invariant that `minVal` is the minimum of all prefix elements `nums[0...i]`, by mathematical induction, when $i = N-1$, `minVal` is the minimum of the entire array.

---

## Complexity Analysis
*   **Time Complexity:** $\mathcal{O}(N)$ — We traverse the array of size $N$ exactly once.
*   **Space Complexity:** $\mathcal{O}(1)$ — We only allocate a single variable `minVal` to store the minimum value.

---

## Edge Cases
1.  **Array of size 1:** E.g., `nums = {5}`. The loop does not execute; returns `5`. Correct.
2.  **All negative numbers:** E.g., `nums = {-5, -2, -10, -1}`. Initialized to `-5`. Updates to `-10` correctly. (This is why initializing to `0` is a classic mistake).
3.  **Duplicate minimums:** E.g., `nums = {2, 5, 2, 3}`. Correctly returns `2`.
4.  **Empty array:** Throw an exception or return a clear error code. Our implementation throws `std::invalid_argument`.

---

## Common Mistakes
*   **Wrong Initialization:** Initializing `minVal = 0`. If the array contains `{5, 12, 3}`, the program will return `0`, which is incorrect because `0` is not in the array. Always initialize to `nums[0]` or `INT_MAX`.
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
*   **Formula:** `minVal = min(minVal, nums[i])`.
*   **Initialization:** `minVal = nums[0]`.
*   **Time:** $\mathcal{O}(N)$ | **Space:** $\mathcal{O}(1)$.
*   **Caution:** Handle empty arrays gracefully and initialize with elements from the array, not arbitrary zeros.

---

## Key Takeaways
1.  Linear scan is optimal when we need to find a single maximum or minimum in an unsorted collection.
2.  Proper initialization (using the first element) is crucial to avoid overflow/underflow or incorrect bounds errors.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** None (First) | **Next:** None (Last) |
<!-- navigation -->
