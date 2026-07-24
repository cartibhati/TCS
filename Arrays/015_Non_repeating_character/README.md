# Find Non-Repeating Elements in an Array

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Hashing`, `Hash Map`, `Frequency Count`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** A classic variation of the repeating elements problem. Assessing how to filter elements based on specific frequency criteria (frequency $\le 1$ or exactly $1$) is standard in Ninja and Digital assessments.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Frequency Counting / Hashing** pattern.
*   **When to use:** When you need to isolate elements that occur unique times in an unsorted collection.
*   **Core signature:** Keep a hash map (`std::unordered_map` in C++) to store frequency counters for each element.

---

## Intuition
To find all elements that appear exactly once in an unsorted array:
1. Traverse the array and count the occurrences of each element, storing them in a hash map `f`.
2. Iterate through the hash map.
3. For each element `x`, if its frequency `x.second` is 1 (or less than or equal to 1), it is a non-repeating element. We append it to our result list `ans`.
4. *Note:* Similar to the repeating elements problem, `std::unordered_map` does not preserve original sequence order. If ordering matters, we can modify the loop to iterate over the original array `nums` and check if `f[num] == 1`.

---

## Approaches

### 1. Documented Solution (Frequency Counting with std::unordered_map)
*   **Concept:** Iterate through the array to populate the frequency map. Then, iterate through the map to collect keys with frequency $\le 1$.
*   **Time Complexity:** $\mathcal{O}(N)$ average time.
*   **Space Complexity:** $\mathcal{O}(N)$ auxiliary space (for the hash map).

### 2. Sorting-Based Approach (If Space must be O(1))
*   **Concept:** Sort the array. Iterate through, checking if the current element differs from both its left and right neighbors. If so, it is non-repeating.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to sorting).
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.

### 3. Brute Force (Double Loop)
*   **Concept:** For each element `nums[i]`, scan the rest of the array to count its occurrences. If the count is exactly 1, add it to the output.
*   **Time Complexity:** $\mathcal{O}(N^2)$.
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.

---

## Algorithm (Documented Solution)
1. Initialize an `unordered_map<int, int> f` and an empty vector `ans`.
2. For each element `x` in the input array `nums`:
   * Increment its count in the frequency map: `f[x]++`.
3. For each pair `x` in `f`:
   * If `x.second <= 1`:
     * Push `x.first` to `ans`.
4. Return `ans`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 2, -1, 1, 3, 1}`

1.  **Populate Frequency Map:**
    *   $1 \rightarrow 3$
    *   $2 \rightarrow 1$
    *   $-1 \rightarrow 1$
    *   $3 \rightarrow 1$
2.  **Filter Map Elements with Frequency <= 1:**
    *   Key `1`: Frequency is $3 > 1$ $\rightarrow$ Skip.
    *   Key `2`: Frequency is $1 \le 1$ $\rightarrow$ Add `2` to `ans`.
    *   Key `-1`: Frequency is $1 \le 1$ $\rightarrow$ Add `-1` to `ans`.
    *   Key `3`: Frequency is $1 \le 1$ $\rightarrow$ Add `3` to `ans`.
3.  **Result State (`ans`):** `{2, -1, 3}` (order can vary depending on hash map implementation).

**Output:** `2 -1 3`

---

## Why This Works (Correctness)
The frequency map accurately registers the number of times each integer appears in the array. Since non-repeating elements occur exactly once, selecting keys with a value of 1 correctly retrieves all unique elements.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ average time — We traverse the input array of size $N$ once to build the map, and then traverse unique entries of the map to select non-repeating elements.
*   **Space Complexity:** $\mathcal{O}(N)$ — The hash map stores at most $N$ elements.

---

## Edge Cases
1.  **All Elements Repeat:** E.g., `nums = {1, 1, 2, 2}`. No element has frequency 1; returns empty vector. Correct.
2.  **All Elements Unique:** E.g., `nums = {1, 2, 3}`. All frequencies are 1; returns all elements. Correct.
3.  **Empty Array:** Map is empty; returns empty vector. Correct.

---

## Common Mistakes
*   **Order preservation:** Assumed output order should match input order. To maintain input order, iterate over the original array `nums` in the second loop:
    ```cpp
    for (int x : nums) {
        if (f[x] == 1) {
            ans.push_back(x);
            f[x] = 0; // Prevent duplicates in output if any (though not strictly necessary since unique elements only appear once anyway)
        }
    }
    ```
*   **Using `std::map` instead of `std::unordered_map`:** Using `std::map` degrades lookup performance from $\mathcal{O}(1)$ average to $\mathcal{O}(\log N)$.

---

## Similar Questions
*   First non-repeating element in an array.
*   Find repeating elements in an array.
*   Single Number (where every element repeats twice except one).

---

## Interview Tips & Insights
*   **Time-Space Trade-off:** Be ready to talk about trade-offs. Using sorting allows $\mathcal{O}(1)$ space but costs $\mathcal{O}(N \log N)$ time. Hashing gives optimal $\mathcal{O}(N)$ time at the cost of $\mathcal{O}(N)$ space.
*   **Bitwise XOR Tip:** If the problem guarantees that *all* elements repeat exactly twice except *one* unique element, point out that you can use the XOR operator (`^`) to solve it in $\mathcal{O}(N)$ time and $\mathcal{O}(1)$ space without a hash map.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Find all elements that appear exactly once in an array.
*   **Strategy:** Hashing with `unordered_map` to count frequencies.
*   **Filter Condition:** `frequency == 1`.
*   **Complexity:** Time: $\mathcal{O}(N)$ average | Space: $\mathcal{O}(N)$.

---

## Key Takeaways
1.  Hashing is the most efficient general-purpose method to find unique elements in linear time.
2.  If input array properties are specific (e.g. all elements duplicate except one), bitwise operations can optimize space complexity to $\mathcal{O}(1)$.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Find Repeating Elements in an Array](../014_repeating_elements/README.md) | **Next:** None (Last) |
| <!-- navigation -->
