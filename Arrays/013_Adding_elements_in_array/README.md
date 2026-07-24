# Adding Elements in an Array

## Problem Metadata
*   **Difficulty:** Easy
*   **Topic:** Arrays
*   **Tags:** `Arrays`, `Vector Insertion`, `TCS NQT`
*   **Common Target Companies:** TCS, Accenture, Wipro, Capgemini, Infosys

---

## TCS NQT Relevance & Appearance Info
*   **Relevance:** Foundational array manipulation question. Tests understanding of basic memory layout, element shifting, and C++ vector API options (like `insert` and `push_back`).
*   **Frequency:** Very Frequent
*   **Reported Years:** 2021, 2022, 2023, 2024
*   **Verification Status:** Community-reported.

---

## Pattern Recognition
This problem belongs to the **Array Insertion and Shifting** pattern.
*   **When to use:** When you need to add elements at different positions (beginning, end, or specific indices) in a sequential collection.
*   **Core signature:** Inserting at the end is cheap ($\mathcal{O}(1)$), while inserting at the beginning or at an arbitrary position $K$ requires shifting elements, leading to $\mathcal{O}(N)$ time.

---

## Intuition
When inserting elements in a dynamic array (like a `std::vector` in C++):
1. **Beginning:** Inserting at index 0 requires shifting all existing elements one position to the right to make room. This takes $\mathcal{O}(N)$ operations.
2. **Ending:** Inserting at the end simply appends the element. This requires no shifting and takes $\mathcal{O}(1)$ amortized time.
3. **Position $K$:** Inserting at index $K$ requires shifting all elements from index $K$ to the end of the array one position to the right. This takes $\mathcal{O}(N)$ operations.

---

## Approaches

### 1. Documented Solution (C++ STL Vector APIs)
*   **Concept:** Use `v.insert(v.begin(), n)` to insert at the beginning, `v.push_back(n)` or `v.insert(v.end(), n)` for the end, and `v.insert(v.begin() + k, n)` to insert at position `k`.
*   **Time Complexities:**
    *   **At Beginning:** $\mathcal{O}(N)$
    *   **At Ending:** $\mathcal{O}(1)$ amortized
    *   **At Position $K$:** $\mathcal{O}(N)$
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (modification is done directly on the vector).

### 2. Manual Shifting Approach (For Static/Fixed-Size Arrays)
*   **Concept:** If using static arrays, we must manually shift elements using loops before placing the new element.
*   **C++ Implementation (For Static Arrays):**
    ```cpp
    // Insert at beginning of static array of size n (with capacity > n)
    void insertBeginningStatic(int arr[], int& n, int element) {
        for (int i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        n++;
    }
    ```

---

## Algorithm (Documented Solution)

### Insert at Beginning:
1. Call `v.insert(v.begin(), n)`.

### Insert at Ending:
1. Call `v.push_back(n)`.

### Insert at Position $K$:
1. Call `v.insert(v.begin() + k, n)`.

---

## Dry Run (Documented Solution)
**Input:** `nums = {1, 2, 3, 4, 5}`

1.  **Insert 6 at the beginning:**
    *   Result: `{6, 1, 2, 3, 4, 5}`
2.  **Insert 7 at the end:**
    *   Result: `{6, 1, 2, 3, 4, 5, 7}`
3.  **Insert 8 at index 4:**
    *   The element at index 4 (which was `4`) and all elements to its right are shifted.
    *   Result: `{6, 1, 2, 3, 8, 4, 5, 7}`

**Output:** `6 1 2 3 8 4 5 7`

---

## Why This Works (Correctness)
Under the hood, C++ `std::vector` is a contiguous block of memory. When we insert an element, the vector moves all subsequent elements to the right to maintain contiguity. This behavior ensures that the elements are correctly positioned at the specified indexes.

---

## Complexity Analysis (Documented Solution)
*   **Time Complexity:**
    *   **Insert at Beginning:** $\mathcal{O}(N)$ — Every element must be shifted right by one position.
    *   **Insert at Ending:** $\mathcal{O}(1)$ amortized — No shifting is required; the element is appended to the end.
    *   **Insert at Position $K$:** $\mathcal{O}(N)$ — In the worst case (when $K = 0$), it takes $\mathcal{O}(N)$ time. On average, it requires shifting $N - K$ elements.
*   **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The vector dynamically resizes if it exceeds its capacity, which takes temporary $\mathcal{O}(N)$ space during reallocation, but the overall auxiliary space is constant.

---

## Edge Cases
1.  **Index Out of Bounds:** Inserting at position $K$ when $K > \text{size}$ causes undefined behavior or runtime exceptions. In production, check `if (k >= 0 && k <= v.size())` before inserting.
2.  **Empty Array:** Inserting at beginning, end, or position 0 on an empty array works correctly and leaves the array with exactly 1 element.
3.  **Large scale insertions:** Frequent insertions at the beginning of a vector are inefficient. If this is a primary requirement, consider using a double-ended queue (`std::deque`) or a linked list (`std::list`) instead.

---

## Common Mistakes
*   **Off-by-one errors:** Inserting at `v.begin() + k` when $K$ is larger than the vector size.
*   **Inefficient loops:** Manually shifting elements using loops when standard library features like `v.insert` are cleaner and highly optimized.

---

## Similar Questions
*   Delete an element from an array (beginning, end, or index $K$).
*   Rotate an array by $K$ elements.
*   Implement a dynamic array from scratch.

---

## Interview Tips & Insights
*   **Discuss Shifting Cost:** Always mention that inserting at the beginning of an array is an $\mathcal{O}(N)$ operation. This shows you understand the underlying contiguous memory layout of arrays.
*   **Propose std::deque if needed:** If the interviewer mentions that insertion/deletion at both ends is frequent, suggest using `std::deque` which allows $\mathcal{O}(1)$ insertions at both ends.

---

## Revision Notes (1-Minute Quick Check)
*   **Objective:** Insert elements at the beginning, end, or index $K$ of a vector.
*   **Beginning:** `v.insert(v.begin(), val)` — $\mathcal{O}(N)$ time.
*   **Ending:** `v.push_back(val)` — $\mathcal{O}(1)$ time.
*   **Position K:** `v.insert(v.begin() + k, val)` — $\mathcal{O}(N)$ time.
*   **Complexity:** Space is $\mathcal{O}(1)$ auxiliary.

---

## Key Takeaways
1.  Inserting in sequential contiguous containers like vectors incurs a shifting cost proportional to the number of elements after the insertion index.
2.  Append operations (`push_back`) are optimal and run in constant time.

---

## Navigation
<!-- navigation -->
| Links | Navigation |
| :--- | :--- |
| [🏛️ Repository Dashboard](../../README.md) | [📂 Arrays Index](../../README.md#arrays) |
| **Prev:** [← Prev: Remove Duplicates from Unsorted Array](../012_remove_dup_unsorted_array/README.md) | **Next:** None (Last) |
| <!-- navigation -->
