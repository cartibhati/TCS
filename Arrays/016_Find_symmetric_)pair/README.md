# Find Symmetric Pairs in an Array

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Hashing`, `Hash Map`, `Pairs`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Cognizant

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** A classic problem testing hashing and pair manipulation. It demonstrates how to optimize a quadratic brute-force approach to linear time using a hash map.
*   **Frequency:** Frequent
*   **Reported Years:** 2020, 2021, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Hashing / Look-up Table** pattern.
*   **When to use:** When you need to find elements or pairs of elements that satisfy a specific relationship (like symmetric, inverse, or target sum) and want to avoid nested loops.
*   **Core signature:** Store previously seen elements in a hash map/set to allow $\mathcal{O}(1)$ average look-up time for the complement/symmetric pair.

---

## Intuition
A pair $(a, b)$ is symmetric to another pair $(c, d)$ if $a = d$ and $b = c$. 
If we process the array sequentially, for each pair $(a, b)$, we want to check if we have already seen its symmetric counterpart $(b, a)$.
1. We can maintain a hash map where the key is the first element of the pair and the value is the second element.
2. For each pair $(first, second)$, we check if $second$ is already present as a key in our map.
3. If it is present, and the mapped value of $second$ equals $first$, then we have found a symmetric pair: $(second, first)$ and $(first, second)$. We print or store this pair.
4. If not, we store the current pair in our map: `mp[first] = second` so that it can be matched with any future symmetric pairs.

---

## Approaches

### 1. Documented Solution (Hash Map / Hashing)
*   **Concept:** Use an `unordered_map<int, int>` to store the pairs as we traverse. For every pair `(first, second)`, look up `second` in the map. If `mp[second] == first`, we print the symmetric pair. Otherwise, insert `mp[first] = second`.
*   **Time Complexity:** $\mathcal{O}(N)$ on average (since hash map lookups are $\mathcal{O}(1)$ on average).
*   **Space Complexity:** $\mathcal{O}(N)$ to store the pairs in the hash map.

### 2. Brute Force (Nested Loops)
*   **Concept:** For each pair at index `i`, run a nested loop from `i+1` to `N-1` to find a pair at index `j` such that `arr[i].first == arr[j].second` and `arr[i].second == arr[j].first`.
*   **Time Complexity:** $\mathcal{O}(N^2)$ (due to two nested loops).
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
*   **Drawback:** Inefficient for larger arrays ($N > 10^4$).

---

## Algorithm (Documented Solution)
1. Initialize an empty hash map `mp`.
2. Iterate through each pair `p` in the array `arr`:
   * Set `first = p.first`, `second = p.second`.
   * Check if `second` exists in `mp` and `mp[second] == first`.
   * If both conditions are met, output the symmetric pair: `(second, first)` and `(first, second)`.
   * Else, store the current mapping: `mp[first] = second`.

---

## Dry Run (Documented Solution)
**Input:** `arr = {{1, 2}, {3, 4}, {2, 1}, {5, 4}, {4, 5}}`

| Step | Pair `p` | `first` | `second` | Condition: `mp.count(second) && mp[second] == first` | Action | Map State `mp` | Output |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `{1, 2}` | 1 | 2 | `mp[2]` exists? No. | Store `mp[1] = 2` | `{1: 2}` | - |
| 2 | `{3, 4}` | 3 | 4 | `mp[4]` exists? No. | Store `mp[3] = 4` | `{1: 2, 3: 4}` | - |
| 3 | `{2, 1}` | 2 | 1 | `mp[1]` exists? Yes (`mp[1] == 2`). Match! | Print symmetric pair | `{1: 2, 3: 4}` | `(1,2),(2,1)` |
| 4 | `{5, 4}` | 5 | 4 | `mp[4]` exists? No. | Store `mp[5] = 4` | `{1: 2, 3: 4, 5: 4}` | - |
| 5 | `{4, 5}` | 4 | 5 | `mp[5]` exists? Yes (`mp[5] == 4`). Match! | Print symmetric pair | `{1: 2, 3: 4, 5: 4}` | `(5,4),(4,5)` |

---

## Why This Works (Correctness)
By mapping `first -> second` for every visited pair, we keep track of all potential candidates. When we later process a pair where the components are reversed, the lookup in the map will succeed because the first element of the new pair matches the second element of the stored pair, and the second element of the new pair matches the first element of the stored pair.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:** $\mathcal{O}(N)$ — We traverse the list of pairs of size $N$ exactly once. Hash map lookups and insertions take $\mathcal{O}(1)$ average time.
*   **Space Complexity:** $\mathcal{O}(N)$ — In the worst case (where no symmetric pairs exist), we store all $N$ pairs in the hash map.

---

## Edge Cases
1.  **No symmetric pairs:** E.g., `arr = {{1, 2}, {3, 5}}`. No matches will be found. The program completes without outputting anything. Correct.
2.  **Multiple duplicate pairs:** E.g., `arr = {{1, 2}, {2, 1}, {1, 2}, {2, 1}}`. Will correctly identify multiple symmetric pairs.
3.  **Self-symmetric pairs (e.g., `{2, 2}`):** E.g., `arr = {{2, 2}}`. The map lookup `mp[2]` doesn't exist initially, so it gets stored. If another `{2, 2}` appears later, it matches.

---

## Common Mistakes
*   **Using a hash set incorrectly:** A simple set of integers or pairs is not enough unless you map `first` to `second`. Using a map allows directly verifying that the symmetric pair values match.
*   **Not checking the value matching:** Just checking if `second` exists in the map as a key is insufficient; you must also verify `mp[second] == first`.

---

## Similar Questions
*   Find two numbers in an array that sum up to a target (Two Sum).
*   Find all unique pairs in an array with a given sum.

---

## Interview Tips & Insights
*   **Hash Map Selection:** In C++, `std::unordered_map` is preferred over `std::map` because it offers $\mathcal{O}(1)$ average time complexity for lookups/insertions compared to $\mathcal{O}(\log N)$ for `std::map`.
*   **Explain Trade-offs:** Always mention the space complexity trade-off ($\mathcal{O}(N)$ space) when optimizing the time complexity from $\mathcal{O}(N^2)$ to $\mathcal{O}(N)$.

---

## Revision Notes (1-Minute Quick Check)
*   **Goal:** Find pairs $(a, b)$ and $(b, a)$.
*   **Data Structure:** `unordered_map<int, int> mp`.
*   **Check Condition:** `mp.find(second) != mp.end() && mp[second] == first`.
*   **Time:** $\mathcal{O}(N)$ average | **Space:** $\mathcal{O}(N)$.

---

## Key Takeaways
1. Hashing converts a quadratic search problem into a linear check by trading memory for execution speed.
2. Checking both existence and exact value match prevents false positives when matching keys.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Find Non-Repeating Elements in an Array](../015_Non_repeating_character/README.md) | **Next:** None (Last) |
<!-- navigation -->
