# Calculate Sum of Elements

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Accumulate`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Finding the sum of elements is a fundamental arithmetic task on arrays. It is often requested directly or as a step to find the average, variance, or standard deviation of elements in TCS coding assessments.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Linear Scan / Accumulation** pattern.
*   **When to use:** Whenever you need to aggregate all values in a collection into a single representative value (such as sum, product, count).
*   **Core signature:** Initialize an accumulator variable (e.g., `sum = 0`), traverse the collection linearly, and apply the reduction operation (`sum += nums[i]`) at each step.

---

## Intuition
To find the total sum of a sequence of numbers, we start with a subtotal of zero and successively add each number from the sequence to our running subtotal. Once we have added the last number, the running subtotal holds the total sum.

---

## Approaches

### 1. Documented Solution (Linear Accumulation Loop)
*   **Concept:** Iterate through the array from index `0` to `N-1`. Maintain a local accumulator variable `sum = 0` and add each element `nums[i]` to it.
*   **Time Complexity:** $\mathcal{O}(N)$ (single traversal).
*   **Space Complexity:** $\mathcal{O}(N)$ auxiliary space (because the function parameter `vector<int> nums` is passed by value, copying the input array in memory).

### 2. Alternative Approach (Optimized Pass-by-Reference and `long long` Guard)
*   **Concept:**
    1. Pass the vector by reference `const vector<int>& nums` to avoid copying overhead ($\mathcal{O}(1)$ auxiliary space).
    2. Use `long long` for the accumulator variable to prevent **integer overflow** if the sum of elements exceeds the range of a standard 32-bit signed integer (`INT_MAX` $\approx 2 \times 10^9$).
*   **C++ Implementation:**
    ```cpp
    long long calculateSum(const vector<int>& nums) {
        long long sumVal = 0;
        for (int x : nums) {
            sumVal += x;
        }
        return sumVal;
    }
    ```

### 3. Alternative Approach (C++ STL Standard Library)
*   **Concept:** Use C++ `<numeric>` library function `std::accumulate`.
*   **C++ Implementation:**
    ```cpp
    #include <numeric>
    // inside function:
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    ```

---

## Algorithm (Documented Solution)
1. Define function `sum` taking vector `nums` by value.
2. Initialize variable `sum = 0`.
3. Loop through the array from index `i = 0` to `nums.size() - 1`:
   * Add `nums[i]` to `sum`.
4. Return `sum`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 2, 3, 4, 5}`

*   Initial State: `sum = 0`

| Index ($i$) | Current Element (`nums[i]`) | Addition | Running `sum` |
| :--- | :--- | :--- | :--- |
| - | - | - | **0** |
| 0 | 1 | `0 + 1` | **1** |
| 1 | 2 | `1 + 2` | **3** |
| 2 | 3 | `3 + 3` | **6** |
| 3 | 4 | `6 + 4` | **10** |
| 4 | 5 | `10 + 5` | **15** |

**Output:** `15`

---

## Why This Works (Correctness)
The accumulation invariant holds that at the end of iteration $i$, the variable `sum` stores the sum of all elements in the prefix `nums[0...i]`. By mathematical induction, when the loop terminates after inspecting index $N-1$, `sum` is guaranteed to contain the sum of the entire array.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — We visit each of the $N$ elements exactly once.
*   **Space Complexity:** $\mathcal{O}(N)$ — Due to pass-by-value, a copy of the input vector of size $N$ is created. (Optimizable to $\mathcal{O}(1)$ by passing by reference).

---

## Edge Cases
1.  **Empty array:** Loop does not run. Returns `0`. Correct.
2.  **All negative numbers:** E.g., `nums = {-1, -2, -3}`. Accumulates correctly to `-6`.
3.  **Integer Overflow:** If the array contains elements like `10^9` and `2 * 10^9`, the sum will exceed the capacity of a 32-bit signed integer, causing signed integer overflow (undefined behavior). In interviews, always mention using `long long` for accumulators to prevent this.

---

## Common Mistakes
*   **Integer Overflow:** Using `int` instead of `long long` when the problem states that array elements or the array length can be very large.
*   **Uninitialized Accumulator:** Declaring `int sum;` without initializing it to `0`, resulting in undefined behavior as it accumulates onto a random garbage memory value.

---

## Similar Questions
*   Find the average of all elements in an array.
*   Find the product of all elements in an array.
*   Calculate the prefix sum array.

---

## Interview Tips & Insights
*   **Key Question to Ask:** *"What is the range of the elements in the array and the maximum array size? Do we need to worry about integer overflow?"* This question instantly displays senior engineering logic to the interviewer.
*   **Variable Shadowing Note:** In C++, naming a local variable `sum` inside a function named `sum` is allowed but causes **variable shadowing**. It's clean practice to name the local accumulator differently (e.g., `total` or `sumVal`) to keep code readable.

---

## Revision Notes (1-Minute Quick Check)
*   **Formula:** `sum += nums[i]`.
*   **Initialization:** `sum = 0`.
*   **Watch out for:** Pass-by-reference to save copy space, and `long long` to prevent integer overflow.
*   **Complexity:** Time: $\mathcal{O}(N)$ | Space: $\mathcal{O}(N)$ copy (or $\mathcal{O}(1)$ if in-place).

---

## Key Takeaways
1.  Linear accumulation is optimal because we must read every element to compute the sum.
2.  Always guard against overflow and uninitialized values when implementing accumulators.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Rearrange Array in Increasing-Decreasing Order](../006_reaarange_asc_desc/README.md) | **Next:** None (Last) |
<!-- navigation -->
