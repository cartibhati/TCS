# Find Median of the Array

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Sorting`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Finding the median of a sequence is a standard arithmetic challenge. Often asked to test sorting capability, handling of even vs. odd size conditions, and type conversion.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Sorting / Order Statistics** pattern.
*   **When to use:** When you need to retrieve an element at a specific ranked position (like the median, $K$-th smallest/largest) in an unsorted collection.
*   **Core signature:** Sort the collection to bring elements into sequential order, then access the index corresponding to the target statistic.

---

## Intuition
The median is the middle element in a sorted, ascending or descending list of numbers:
1. Since the input array is unsorted, we must first sort the array to establish order.
2. In the documented solution, the median is taken directly at index `n / 2`.
3. *Note:* Mathematically, the median behaves differently based on whether the number of elements $N$ is odd or even. 
   * If $N$ is odd, the median is the single middle element: `nums[n / 2]`.
   * If $N$ is even, the median is typically the average of the two middle elements: `(nums[n / 2 - 1] + nums[n / 2]) / 2.0`. The current implementation simplifies this by always returning the element at `nums[n / 2]`.

---

## Approaches

### 1. Documented Solution (Sorting & Midpoint Selection)
*   **Concept:** Sort the vector using `std::sort` in-place, then return the element at index `n / 2`.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to sorting).
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (in-place modification of the parameter vector passed by reference).

### 2. Standard Mathematical Median (Even/Odd Check)
*   **Concept:** Sort the array. Check if the size $N$ is even or odd, and compute the median accordingly to support decimal values for even sizes.
*   **C++ Implementation:**
    ```cpp
    double findTrueMedian(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        if (n % 2 != 0) {
            return nums[n / 2];
        }
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
    ```

### 3. Optimal Approach (Quickselect using `std::nth_element`)
*   **Concept:** Instead of sorting the entire array which takes $\mathcal{O}(N \log N)$, use C++'s standard `std::nth_element` to find the middle element. This rearranges the array so that the element at the midpoint is the one that would be in that position if the array were fully sorted.
*   **Time Complexity:** $\mathcal{O}(N)$ average time.
*   **Space Complexity:** $\mathcal{O}(1)$.
*   **C++ Implementation:**
    ```cpp
    #include <algorithm>
    #include <vector>

    int medianQuickselect(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        std::nth_element(nums.begin(), nums.begin() + mid, nums.end());
        return nums[mid];
    }
    ```

---

## Algorithm (Documented Solution)
1. Define the function `median` which takes a reference to a vector of integers `nums`.
2. Find the size of the vector `n = nums.size()`.
3. Sort the vector: `sort(nums.begin(), nums.end())`.
4. Calculate the midpoint index `mid = n / 2`.
5. Return `nums[mid]`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {2, 4, 1, 3, 5}`

1.  **Size $N$:** `5`
2.  **Sorting step:** `nums` becomes `{1, 2, 3, 4, 5}`.
3.  **Mid index calculation:** `mid = 5 / 2 = 2`.
4.  **Median retrieval:** `nums[2]` = `3`.
5.  **Output:** `3`

---

## Why This Works (Correctness)
Sorting the array groups all elements smaller than the median to its left, and all elements larger than the median to its right. Thus, the item situated at index `n / 2` represents the sorted center, which is the definition of the median for an odd-sized dataset.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N \log N)$ — Dominated by `std::sort` which uses IntroSort (a hybrid of Quicksort, Heapsort, and Insertion Sort).
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space — Sorting is performed in-place. (Note: Depending on the implementation of `std::sort`, it may use $\mathcal{O}(\log N)$ call stack space for recursion).

---

## Edge Cases
1.  **Even-sized Array:** E.g., `nums = {1, 2, 3, 4}`. `n / 2` calculates as `2`. Returning `nums[2]` yields `3` instead of the mathematical median `2.5`. Check problem guidelines to see if integer truncation or a floating-point average is requested.
2.  **Single-element Array:** E.g., `nums = {7}`. Sorted sequence is `{7}`, `mid = 0`, returns `7`. Correct.
3.  **Duplicate Elements:** E.g., `nums = {1, 3, 3, 3, 5}`. The center element is correctly resolved as `3`.

---

## Common Mistakes
*   **Forgetting to Sort:** Attempting to retrieve `nums[n / 2]` directly from the unsorted array, which returns the element that happened to be in the middle, not the median.
*   **Pass-by-value vs. Pass-by-reference:** If you want to avoid mutating the original input array, pass by value or make a copy. If efficiency is priority and mutation is allowed, pass by reference.

---

## Similar Questions
*   Find the mean, median, and mode of an array.
*   Find the $K$-th smallest/largest element in an unsorted array (Quickselect).
*   Find the running median of a data stream (Two Heaps pattern).

---

## Interview Tips & Insights
*   **Propose std::nth_element:** Proposing `std::nth_element` demonstrates high familiarity with C++ STL and optimal complexity algorithms ($\mathcal{O}(N)$ average time).
*   **Address even/odd cases:** Always ask the interviewer how to handle even-length arrays. This shows thoroughness and proactive communication.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Find the median value of an array.
*   **Approach:** Sort the array and return the value at the center index `n / 2`.
*   **Time:** $\mathcal{O}(N \log N)$ | **Space:** $\mathcal{O}(1)$.
*   **Key Optimization:** `std::nth_element` offers a linear average time $\mathcal{O}(N)$ solution.

---

## Key Takeaways
1.  Sorting is the standard, simplest way to find order statistics like the median.
2.  Make sure to confirm requirements for even-length lists (whether to return the upper-mid element or average the two middle values).

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Average of all Elements](../009_Avg_of_all_elements/README.md) | **Next:** None (Last) |
| <!-- navigation -->
