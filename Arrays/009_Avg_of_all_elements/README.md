# Average of all Elements

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Accumulation`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Foundational reduction problem. Frequently used as a basic warm-up question or in real-world application scenarios where statistical aggregation is required.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Accumulation / Reduction** pattern.
*   **When to use:** When you need to aggregate all elements of a collection into a single scalar value.
*   **Core signature:** Maintain an accumulator state (like `sum`) and iterate through the collection to combine each element with the accumulator.

---

## Intuition
To find the average of an array of numbers:
1. Traverse the array and calculate the total sum of all elements.
2. Count the number of elements $N$.
3. Divide the total sum by $N$.
   * *Note:* Pay attention to the return type requirements (integer division vs. floating point). The standard code implementation uses integer division.

---

## Approaches

### 1. Documented Solution (Single-Pass Loop)
*   **Concept:** Loop through all elements, summing them up in an integer variable. Divide by the total size of the array.
*   **Time Complexity:** $\mathcal{O}(N)$ (linear scan of the array).
*   **Space Complexity:** $\mathcal{O}(1)$ (uses constant auxiliary space).

### 2. Alternative Optimized Approach (Using std::accumulate)
*   **Concept:** Leverage C++ STL algorithms for a cleaner, idiomatic implementation using `std::accumulate` from `<numeric>`.
*   **C++ Implementation:**
    ```cpp
    #include <numeric>
    #include <vector>

    int avg(const std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return sum / nums.size();
    }
    ```

---

## Algorithm (Documented Solution)
1. Initialize `sum` to `0`.
2. Iterate through each element in `nums` and add it to `sum`.
3. Obtain the size of the array `n`.
4. Calculate and return `sum / n`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 2, 3, 4, 5}`

| Step | Index ($i$) | Current Element (`nums[i]`) | Sum Operation | Running `sum` |
| :--- | :--- | :--- | :--- | :--- |
| Init | - | - | - | **0** |
| 1 | 0 | 1 | `0 + 1` | **1** |
| 2 | 1 | 2 | `1 + 2` | **3** |
| 3 | 2 | 3 | `3 + 3` | **6** |
| 4 | 3 | 4 | `6 + 4` | **10** |
| 5 | 4 | 5 | `10 + 5` | **15** |

*   **Size $N$:** `5`
*   **Average calculation:** `15 / 5` = `3`
*   **Output:** `3`

---

## Why This Works (Correctness)
The arithmetic mean is mathematically defined as the sum of all elements divided by the count of those elements. By visiting every element exactly once, we construct the correct sum, and dividing by $N$ yields the correct average.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — We traverse the array of size $N$ exactly once to calculate the sum.
*   **Space Complexity:** $\mathcal{O}(1)$ — No additional data structures are used.

---

## Edge Cases
1.  **Empty array:** The current code would cause a division by zero (`sum / 0`). In production, always check `if (n == 0)` or `if (nums.empty())` first.
2.  **Integer Overflow:** If elements are extremely large, their sum might exceed `INT_MAX`. Using `long long` for the sum avoids overflow.
3.  **Floating-point precision:** If the exact average is required (e.g., `2.5`), convert the sum or count to `double` before division: `(double)sum / n`.

---

## Common Mistakes
*   **Division by Zero:** Failing to check if the input array is empty.
*   **Truncation Error:** Using integer division when a floating-point average is expected.

---

## Similar Questions
*   Find the sum of all elements in an array.
*   Find the product of all elements in an array.
*   Calculate the weighted average of elements.

---

## Interview Tips & Insights
*   **Show Awareness of Overflow:** Point out that in real-world scenarios, summing large integers can cause overflow. Suggesting `long long` shows attention to detail.
*   **Float vs. Int:** Always ask the interviewer if they want integer division or a floating-point output.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Find the average of all array elements.
*   **Core Formula:** `sum / N`.
*   **Time:** $\mathcal{O}(N)$ | **Space:** $\mathcal{O}(1)$.
*   **Key Guard:** Guard against division by zero for empty inputs.

---

## Key Takeaways
1.  Summing and dividing is the optimal approach for finding the average, requiring linear time and constant space.
2.  Always clarify expected return types (integer vs float/double) during the interview.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Left Rotate Array by K Elements](../008_left_rotate/README.md) | **Next:** None (Last) |
| <!-- navigation -->
