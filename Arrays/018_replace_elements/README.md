# Replace Elements by their Rank

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Sorting`, `Hashing`, `Hash Map`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Cognizant

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** A fundamental array coordination and mapping problem. It tests the ability to sort data, map distinct values to ranks, and restore the original order of elements using a hash map lookup.
*   **Frequency:** Very Frequent
*   **Reported Years:** 2020, 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Sorting with Auxiliary Mapping** pattern.
*   **When to use:** When you need to transform the values of an array to their relative positions or ranks while preserving the original relative order.
*   **Core signature:** Create a sorted copy of the array to find relative order, use a hash map to associate each unique value with its rank (handling duplicates correctly), and map back to the original array.

---

## Intuition
To find the rank of each element (where the smallest element gets rank 1, the next smallest gets rank 2, etc.):
1. If we sort the array, the elements will naturally be arranged in ascending order.
2. In this sorted copy, the first element (which is the smallest) will have rank 1. Each subsequent *distinct* element will get an incremented rank.
3. We store these mappings in a hash map (`rank[value] = assigned_rank`) to prevent duplicate elements from receiving different ranks.
4. Finally, we iterate through the original array and replace each element with its mapped rank from the hash map.

---

## Approaches

### 1. Documented Solution (Sorting + Hash Map)
*   **Concept:** Clone the array and sort it. Iterate through the sorted array, assigning consecutive ranks to unique elements using an `unordered_map`. Replace the original array elements with their rank using the map.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ due to sorting. The subsequent map lookups are $\mathcal{O}(N)$ on average.
*   **Space Complexity:** $\mathcal{O}(N)$ to store the array copy and the hash map.

### 2. Alternative Approach (Using `std::map` or `std::set`)
*   **Concept:** Instead of sorting a full copy, insert all elements into a balanced BST-based set (`std::set` in C++), which automatically stores unique elements in sorted order. Then traverse the set to assign ranks, and finally map the original elements.
*   **Time Complexity:** $\mathcal{O}(N \log N)$ (since insertion of $N$ elements into a set takes $\mathcal{O}(N \log N)$).
*   **Space Complexity:** $\mathcal{O}(N)$ to store set elements and rank mapping.

---

## Algorithm (Documented Solution)
1. Copy the input array `nums` to a temporary array `temp`.
2. Sort the `temp` array in ascending order.
3. Create a hash map `rank` and initialize `currentRank = 1`.
4. Iterate through `temp`:
   * If `temp[i]` is not present in `rank`, add it: `rank[temp[i]] = currentRank`.
   * Increment `currentRank` by 1.
5. Iterate through the original `nums` array and replace `nums[i] = rank[nums[i]]`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {20, 15, 26, 2, 98, 6}`

### Step 1 & 2: Clone and Sort
*   `temp = {2, 6, 15, 20, 26, 98}`

### Step 3 & 4: Populate Map
*   `currentRank = 1`
*   `temp[0] = 2`: not in map $\rightarrow$ `rank[2] = 1`, `currentRank` becomes 2.
*   `temp[1] = 6`: not in map $\rightarrow$ `rank[6] = 2`, `currentRank` becomes 3.
*   `temp[2] = 15`: not in map $\rightarrow$ `rank[15] = 3`, `currentRank` becomes 4.
*   `temp[3] = 20`: not in map $\rightarrow$ `rank[20] = 4`, `currentRank` becomes 5.
*   `temp[4] = 26`: not in map $\rightarrow$ `rank[26] = 5`, `currentRank` becomes 6.
*   `temp[5] = 98`: not in map $\rightarrow$ `rank[98] = 6`, `currentRank` becomes 7.

### Step 5: Replace Original Elements
*   `nums[0] = rank[20] = 4`
*   `nums[1] = rank[15] = 3`
*   `nums[2] = rank[26] = 5`
*   `nums[3] = rank[2] = 1`
*   `nums[4] = rank[98] = 6`
*   `nums[5] = rank[6] = 2`

**Output:** `nums = {4, 3, 5, 1, 6, 2}`

---

## Why This Works (Correctness)
Sorting the array groups identical elements together and places all elements in relative numerical order. The hash map ensures that duplicate values in the array receive the same rank (since we only assign a rank to a value if it has not been registered in the map).

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N \log N)$ — Sorting the temporary array takes $\mathcal{O}(N \log N)$ time. Populating the map and rebuilding the original array takes $\mathcal{O}(N)$ time.
*   **Space Complexity:** $\mathcal{O}(N)$ — We use $\mathcal{O}(N)$ space for the copy of the array and the map of ranks.

---

## Edge Cases
1.  **Duplicate Elements:** E.g., `nums = {10, 8, 10, 12}`.
    - Sorted `temp = {8, 10, 10, 12}`.
    - Map: `rank[8] = 1`, `rank[10] = 2`. The second `10` is skipped. `rank[12] = 3`.
    - Output: `{2, 1, 2, 3}`. Correct (both `10`s share rank 2).
2.  **Already Sorted:** E.g., `nums = {1, 2, 3}`. Correctly returns `{1, 2, 3}`.
3.  **Reverse Sorted:** E.g., `nums = {3, 2, 1}`. Correctly returns `{3, 2, 1}`.

---

## Common Mistakes
*   **Incorrectly incrementing rank for duplicates:** Incrementing the rank counter when encountering a duplicate element, which causes gaps in rank values (e.g., assigning ranks 1, 2, 4 instead of 1, 2, 3).
*   **Modifying elements on the fly:** Trying to find rank without a map or copy, leading to quadratic time complexity $\mathcal{O}(N^2)$.

---

## Similar Questions
*   Relative Sort Array.
*   Find all elements in an array that are greater than all elements to their right (Leaders in an Array).

---

## Interview Tips & Insights
*   **Duplicate handling is key:** Highlight how you handle duplicates in your code (using the `find() == end()` check on the map) as this is what interviewers specifically check.
*   **Unordered Map vs Map:** Make sure to explain that `std::unordered_map` is used for constant $\mathcal{O}(1)$ average lookups, whereas `std::map` takes logarithmic time.

---

## Revision Notes (1-Minute Quick Check)
*   **Goal:** Replace elements with their sorted position rank (1-indexed).
*   **Approach:** Clone array $\rightarrow$ Sort clone $\rightarrow$ Map unique elements to rank $\rightarrow$ Replace original values.
*   **Time:** $\mathcal{O}(N \log N)$ | **Space:** $\mathcal{O}(N)$.

---

## Key Takeaways
1. Creating a sorted copy allows for relative ranking without losing the original element positions.
2. A conditional lookup check prevents duplicate elements from advancing the rank counter unnecessarily.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Maximum Product Subarray](../017_max_product_subarray/README.md) | **Next:** None (Last) |
<!-- navigation -->
