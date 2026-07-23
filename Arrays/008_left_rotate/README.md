# Left Rotate Array by K Elements

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Two Pointers`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Rotating an array is a classic problem asked frequently in TCS Ninja and Digital coding rounds. It tests array indexing, boundary conditions, and spatial reasoning.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Reversal Algorithm** pattern.
*   **When to use:** Whenever you need to rotate a linear collection (array, string, vector) by $K$ positions left or right in-place with $\mathcal{O}(1)$ auxiliary space.
*   **Core signature:** Split the collection into two parts at index $K$ (or $N-K$), reverse each part independently, and then reverse the entire collection.

---

## Intuition
Consider the array `{1, 2, 3, 4, 5}` and we want to left-rotate it by $K = 2$ places. The desired output is `{3, 4, 5, 1, 2}`.
1. Split the array into two sub-arrays: `A = {1, 2}` (first $K$ elements) and `B = {3, 4, 5}` (remaining $N-K$ elements).
2. Reverse `A` to get `A_rev = {2, 1}`.
3. Reverse `B` to get `B_rev = {5, 4, 3}`.
4. Merge them back: `{2, 1, 5, 4, 3}`.
5. Reverse the entire combined array: `{3, 4, 5, 1, 2}`.
This gives the exact left-rotated array!

---

## Approaches

### 1. Documented Solution (In-Place Reversal Algorithm)
*   **Concept:** Reverses `nums[0...k-1]`, then `nums[k...n-1]`, and finally the entire array `nums[0...n-1]`. Uses `k %= n` to handle cases where $K \ge N$.
*   **Time Complexity:** $\mathcal{O}(N)$ (each element is swapped at most twice).
*   **Space Complexity:** $\mathcal{O}(1)$ (all operations done in-place using standard `std::reverse`).

### 2. Alternative Approach (Using a Temporary Array)
*   **Concept:** Copy the first $K$ elements to an auxiliary array. Shift the remaining $N-K$ elements to the left by $K$ positions. Copy the elements from the auxiliary array back to the end of the original array.
*   **Time Complexity:** $\mathcal{O}(N)$
*   **Space Complexity:** $\mathcal{O}(K)$ (requires temporary storage for $K$ elements).
*   **Drawback:** Not in-place; uses extra memory.

---

## Algorithm (Documented Solution)
1. Define function `leftrotatebyk` taking vector `nums` by reference and rotation count `k`.
2. Compute array size `n = nums.size()`.
3. Normalize `k` using modulo operator: `k %= n`.
4. Reverse the first `k` elements: `reverse(nums.begin(), nums.begin() + k)`.
5. Reverse the remaining elements from index `k` to the end: `reverse(nums.begin() + k, nums.end())`.
6. Reverse the entire array: `reverse(nums.begin(), nums.end())`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 2, 3, 4, 5}`, `k = 2` (Size $N = 5$)

1.  **Normalization:** `k = 2 % 5 = 2`.
2.  **Reverse First K Elements (`reverse(nums.begin(), nums.begin() + 2)`):**
    *   Reverses range `[0, 1]`.
    *   State: `{2, 1, 3, 4, 5}`
3.  **Reverse Remaining Elements (`reverse(nums.begin() + 2, nums.end())`):**
    *   Reverses range `[2, 4]`.
    *   State: `{2, 1, 5, 4, 3}`
4.  **Reverse Whole Array (`reverse(nums.begin(), nums.end())`):**
    *   Reverses range `[0, 4]`.
    *   State: `{3, 4, 5, 1, 2}`

**Output:** `3 4 5 1 2`

---

## Why This Works (Correctness)
Let the array be represented as $A B$, where $A$ has length $K$ and $B$ has length $N-K$. Left rotating by $K$ shifts the elements such that the result is $B A$.
Using the properties of reversal:
*   $\text{Reverse}(A) = A^T$
*   $\text{Reverse}(B) = B^T$
*   Combining them gives $A^T B^T$.
*   $\text{Reverse}(A^T B^T) = (B^T)^T (A^T)^T = B A$.
Since $(X^T)^T = X$, reversing the partitioned parts and then reversing the whole array mathematically translates the subsegments into the correct left-rotated positions.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — We perform three reverse operations:
    1. First part of size $K$: $K/2$ swaps.
    2. Second part of size $N-K$: $(N-K)/2$ swaps.
    3. Whole array of size $N$: $N/2$ swaps.
    Total swaps = $N$, which is linear time $\mathcal{O}(N)$.
*   **Space Complexity:** $\mathcal{O}(1)$ — Swapping is done in-place, requiring no auxiliary structures.

---

## Edge Cases
1.  **$K$ is a multiple of $N$ (e.g. $K = 0$ or $K = N$):** `k % n` evaluates to `0`. Reversals of size 0 do nothing, returning the original array. Correct.
2.  **$K > N$:** E.g., rotating size 5 by 7 is equivalent to rotating by $7 \% 5 = 2$ positions. The modulo operator normalizes this safely. Correct.
3.  **Array of size 1:** Loop boundary handles safely. Correct.

---

## Common Mistakes
*   **Missing Modulo Operator:** Failing to do `k %= n`. If $K \ge N$, `nums.begin() + k` will point beyond `nums.end()`, leading to a segmentation fault or undefined behavior.
*   **Symmetric Confusion:** Confusing left rotation with right rotation.
    *   *Left Rotate:* reverse first $K$, reverse remaining $N-K$, reverse all.
    *   *Right Rotate:* reverse remaining $N-K$, reverse last $K$ (or vice versa depending on indexing), reverse all.

---

## Similar Questions
*   Right rotate array by K elements.
*   Rotate a matrix by 90 degrees.
*   Rotate a string by K positions.

---

## Interview Tips & Insights
*   **Space Constraint:** The naive shifting approach or temp array approach is easy to write but wastes memory. Interviewers love the reversal algorithm because it works in-place ($\mathcal{O}(1)$ space). Always propose it first.
*   **Modulo Explanation:** Explain clearly why `k %= n` is necessary to save operations and prevent out-of-bounds pointer invalidation.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Shift elements to the left by $K$ places.
*   **Formula:**
    1. `k %= n`
    2. `reverse(0, k-1)`
    3. `reverse(k, n-1)`
    4. `reverse(0, n-1)`
*   **Complexity:** Time: $\mathcal{O}(N)$ | Space: $\mathcal{O}(1)$ (in-place).

---

## Key Takeaways
1.  Reversal algorithm is a powerful, space-optimal pattern for circular translations of linear segments.
2.  Modulo normalization is essential when shifts exceed sequence lengths.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Calculate Sum of Elements](../007_sum_of_elements/README.md) | **Next:** None (Last) |
<!-- navigation -->
