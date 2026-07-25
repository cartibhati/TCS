# Maximum Product Subarray

## Problem Metadata
*   **Difficulty:** Medium
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Dynamic Programming`, `Kadane's Algorithm`, `Subarray`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Amazon, Microsoft

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** An advanced array manipulation problem that modifies standard Kadane's algorithm. It requires careful handling of zeros and negative numbers, which makes it a favorite for intermediate and advanced coding rounds in TCS Digital/Prime and other hiring tests.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Kadane's Algorithm / Dynamic Programming** pattern.
*   **When to use:** When you need to find the contiguous subarray that maximizes a certain property (sum, product, etc.), and the current state can be computed from the previous state.
*   **Core signature:** Unlike the maximum sum subarray where we only track the maximum sum, for product we must track *both* the maximum product and the minimum product ending at each position. This is because a negative minimum product multiplied by another negative number can suddenly yield a new maximum product.

---

## Intuition
When traversing the array:
1. If the current number is positive, the maximum product ending here will be the current number multiplied by the previous maximum product ending at the prior element (or just the current number itself if the prior product was less than 1).
2. If the current number is negative, it can be multiplied by the previous *minimum* product (which might be highly negative) to yield a very large positive product.
3. If the current number is zero, it resets both the minimum and maximum product trackers to zero.

Therefore, at each position $i$, we compute three candidate values:
- `v1` = `nums[i]` (starting a new subarray at index $i$)
- `v2` = `maxend * nums[i]` (extending the maximum product subarray ending at $i-1$)
- `v3` = `minend * nums[i]` (extending the minimum product subarray ending at $i-1$)

We then update our running trackers:
- `maxend = max({v1, v2, v3})`
- `minend = min({v1, v2, v3})`
- `ans = max(ans, maxend)`

---

## Approaches

### 1. Documented Solution (Dynamic Programming / Modified Kadane's)
*   **Concept:** Maintain `maxend` and `minend` representing the maximum and minimum product subarrays ending at the current index. For each element, update these values by considering the element itself, its product with the previous `maxend`, and its product with the previous `minend`.
*   **Time Complexity:** $\mathcal{O}(N)$ since we perform a single pass over the array.
*   **Space Complexity:** $\mathcal{O}(1)$ as we only maintain a few integer variables.

### 2. Brute Force (All Subarrays)
*   **Concept:** Generate all possible subarrays and calculate their products, keeping track of the maximum product found.
*   **Time Complexity:** $\mathcal{O}(N^2)$ (using nested loops).
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
*   **Drawback:** TLE (Time Limit Exceeded) for $N > 10^3$.

---

## Algorithm (Documented Solution)
1. Initialize `ans`, `maxend`, and `minend` to `nums[0]`.
2. Iterate through the array starting from index 1:
   * Define `v1 = nums[i]`, `v2 = maxend * nums[i]`, and `v3 = minend * nums[i]`.
   * Update `maxend = max(v1, max(v2, v3))`.
   * Update `minend = min(v1, min(v2, v3))`.
   * Update `ans = max(ans, max(maxend, minend))`.
3. Return `ans`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 2, -3, 0, -4, -5}`

| Step | Index ($i$) | `nums[i]` | `v1` | `v2` | `v3` | `maxend` | `minend` | `ans` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | - | - | - | - | 1 | 1 | **1** |
| 1 | 1 | 2 | 2 | 2 | 2 | 2 | 2 | **2** |
| 2 | 2 | -3 | -3 | -6 | -6 | -3 | -6 | **2** |
| 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | **2** |
| 4 | 4 | -4 | -4 | 0 | 0 | 0 | -4 | **2** |
| 5 | 5 | -5 | -5 | 0 | 20 | 20 | -5 | **20** |

**Output:** `20`

---

## Why This Works (Correctness)
By computing `v1`, `v2`, and `v3` at each step, we ensure that:
1. We can start a new subarray at `nums[i]` if the previous product was shrinking the value.
2. We can propagate positive products via `maxend * nums[i]`.
3. We can flip negative products to positive via `minend * nums[i]` when `nums[i]` is negative.
This covers all possible transitions (positive $\rightarrow$ positive, negative $\times$ negative $\rightarrow$ positive, and reset at zero).

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — The array of size $N$ is traversed exactly once.
*   **Space Complexity:** $\mathcal{O}(1)$ — No extra data structures are used; only scalar trackers are updated.

---

## Edge Cases
1.  **Array with all negative numbers:** E.g., `{-2, -3, -4}`.
    - $i=1$: `v1=-3, v2=6, v3=6` $\rightarrow$ `maxend=6`, `minend=-3`, `ans=6`.
    - $i=2$: `v1=-4, v2=-24, v3=12` $\rightarrow$ `maxend=12`, `minend=-24`, `ans=12`.
    - Correctly outputs `12` (product of `{-3, -4}`).
2.  **Array containing zeros:** E.g., `{0, 2}`. Zero resets the product, but subsequent elements can start a new subarray product.
3.  **Single element array:** E.g., `{-5}`. The loop does not execute; returns `-5`. Correct.

---

## Common Mistakes
*   **Forgetting to track `minend`:** Only tracking the maximum product, which fails on double negatives.
*   **Incorrect update order:** Modifying `maxend` before calculating the new `minend` (using the updated `maxend` rather than the old `maxend`). In C++, using temporary variables `v1`, `v2`, `v3` solves this issue.

---

## Similar Questions
*   Maximum Subarray Sum (Kadane's Algorithm).
*   Product of Array Except Self.

---

## Interview Tips & Insights
*   **State transition representation:** When explaining this problem, mention that it's a dynamic programming problem where the state at step $i$ only depends on the state at step $i-1$, allowing us to optimize space to $\mathcal{O}(1)$.
*   **Zero handling:** Walk the interviewer through what happens when a `0` is encountered, showing that it correctly resets the trackers.

---

## Revision Notes (1-Minute Quick Check)
*   **Goal:** Find maximum contiguous subarray product.
*   **Key:** Track both `maxend` and `minend` to handle negative numbers multiplying to positive.
*   **Transition:**
    - `maxend = max({val, maxend * val, minend * val})`
    - `minend = min({val, maxend * val, minend * val})`
*   **Time:** $\mathcal{O}(N)$ | **Space:** $\mathcal{O}(1)$.

---

## Key Takeaways
1. Subarray problems with multiplication require tracking sign reversals (minimum negative products) because the sign flips on multiplying by a negative number.
2. Space optimization in DP can reduce standard linear storage to scalar variables if only the immediate predecessor's state is needed.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Find Symmetric Pairs in an Array](../016_Find_symmetric_)pair/README.md) | **Next:** None (Last) |
<!-- navigation -->
