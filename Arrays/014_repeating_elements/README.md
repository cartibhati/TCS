# Find Repeating Elements in an Array

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Hashing`, `Hash Map`, `Frequency Count`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Finding duplicate or repeating elements is a core competency tested during placement rounds. It assesses understanding of frequency counting, hashing vs. sorting, and space-time optimization.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Frequency Counting / Hashing** pattern.
*   **When to use:** When you need to count how many times each element appears in a collection to filter elements based on their count (e.g. finding repeating elements, unique elements, or elements appearing exactly $K$ times).
*   **Core signature:** Keep a hash map (`std::unordered_map` in C++) mapping elements to their frequency counts.

---

## Intuition
To find all elements that appear more than once in an unsorted array:
1. We can traverse the array and build a frequency dictionary/map that registers the occurrences of each element.
2. After populating this map, we iterate through it.
3. For every key-value pair, if the frequency (value) is greater than 1, the key represents a repeating element. We append it to our result list `ans`.
4. Note: Because `std::unordered_map` does not guarantee any order of elements, the order of elements in `ans` may differ from their first appearance or sorted order. If a specific order is required, we can sort the result or use alternative techniques.

---

## Approaches

### 1. Documented Solution (Frequency Counting with std::unordered_map)
*   **Concept:** Perform a first pass to build the frequency map. In a second pass, iterate through the map and extract elements with frequency $> 1$.
*   **Time Complexity:** $\mathcal{O}(N)$ average time.
*   **Space Complexity:** $\mathcal{O}(N)$ auxiliary space (to store the frequency map).

### 2. Sorting-Based Approach (If Order/Space Constraints Differ)
*   **Concept:** Sort the array in ascending order. Iterate through the sorted array, checking if `nums[i] == nums[i+1]`. If so, it is a duplicate. We must take care not to add duplicates multiple times to our results.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (due to sorting).
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (if done in-place).

### 3. Brute Force (Double Loop)
*   **Concept:** For each element, search the rest of the array to see if it appears again. Use a tracking array or set to avoid adding the same element multiple times to the output.
*   **Time Complexity:** $\mathcal{O}(N^2)$.
*   **Space Complexity:** $\mathcal{O}(N)$ or $\mathcal{O}(1)$ depending on duplicate tracking.

---

## Algorithm (Documented Solution)
1. Initialize an `unordered_map<int, int> f` and an empty vector `ans`.
2. For each element `x` in the input array `nums`:
   * Increment its count in the frequency map: `f[x]++`.
3. For each pair `x` (consisting of `first` as key and `second` as frequency) in `f`:
   * If `x.second > 1`:
     * Push `x.first` to `ans`.
4. Return `ans`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 1, 2, 3, 4, 4, 5, 2}`

1.  **Populate Frequency Map:**
    *   $1 \rightarrow 2$
    *   $2 \rightarrow 2$
    *   $3 \rightarrow 1$
    *   $4 \rightarrow 2$
    *   $5 \rightarrow 1$
2.  **Filter Map Elements with Frequency > 1:**
    *   Key `1`: Frequency is $2 > 1$ $\rightarrow$ Add `1` to `ans`.
    *   Key `2`: Frequency is $2 > 1$ $\rightarrow$ Add `2` to `ans`.
    *   Key `3`: Frequency is $1$ $\rightarrow$ Skip.
    *   Key `4`: Frequency is $2 > 1$ $\rightarrow$ Add `4` to `ans`.
    *   Key `5`: Frequency is $1$ $\rightarrow$ Skip.
3.  **Result State (`ans`):** `{1, 2, 4}` (order can vary depending on hash map implementation).

**Output:** `1 2 4`

---

## Why This Works (Correctness)
A frequency map correctly stores the exact occurrences of each element in the array. Since every duplicate must appear at least twice, checking if the count is strictly greater than 1 guarantees that we identify all repeating elements.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ average time — We iterate through the array of size $N$ once to build the map, and then iterate through the unique keys in the map (at most $N$ keys) to build the output. Hash map operations take $\mathcal{O}(1)$ average time.
*   **Space Complexity:** $\mathcal{O}(N)$ — The map stores at most $N$ unique elements.

---

## Edge Cases
1.  **No Repeating Elements:** E.g., `nums = {1, 2, 3}`. All frequencies are 1; returns empty vector. Correct.
2.  **All Elements Repeating:** E.g., `nums = {1, 1, 2, 2}`. Frequencies are $> 1$; returns `{1, 2}`. Correct.
3.  **Empty Array:** Map is empty; returns empty vector. Correct.

---

## Common Mistakes
*   **Adding Duplicate Elements Multiple Times:** If using brute force or linear scanning, make sure you don't add the same repeating element multiple times to the output. The frequency map naturally avoids this since keys are unique.
*   **Using `std::map` instead of `std::unordered_map`:** `std::map` will sort the keys and cost $\mathcal{O}(N \log N)$ time, whereas `std::unordered_map` is faster on average ($\mathcal{O}(N)$ time).

---

## Similar Questions
*   Find the first repeating element in an array.
*   Find the non-repeating (unique) elements in an array.
*   Find duplicate elements within $K$ distance of each other.

---

## Interview Tips & Insights
*   **Mention Unordered Map vs. Map:** Explicitly state that you are using `std::unordered_map` for $\mathcal{O}(1)$ average time lookup/insertion to show optimization awareness.
*   **Mention order of output:** Point out that because `unordered_map` is unordered, the output order is not guaranteed. If a sorted output is desired, sorting the resulting array takes $\mathcal{O}(D \log D)$ where $D \le N$ is the number of duplicate elements.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Find all elements that appear more than once in an array.
*   **Strategy:** Hashing with `unordered_map` to count frequencies.
*   **Filter Condition:** `frequency > 1`.
*   **Complexity:** Time: $\mathcal{O}(N)$ average | Space: $\mathcal{O}(N)$.

---

## Key Takeaways
1.  Frequency counting using hash maps is the most efficient way to isolate repeating/non-repeating elements in linear time.
2.  Be mindful of ordering requirements on the output, as hash maps do not preserve sequence order.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Adding Elements in an Array](../013_Adding_elements_in_array/README.md) | **Next:** [Next: Find Non-Repeating Elements in an Array →](../015_Non_repeating_character/README.md) |
| <!-- navigation -->
