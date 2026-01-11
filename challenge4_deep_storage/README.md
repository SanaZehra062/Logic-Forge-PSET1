# Challenge 4 – The Deep Storage Inventory Search

## Problem Overview
You are a Software Engineer at a massive automated warehouse. The warehouse stores crates in a square grid (`n x n`).<br>

- **The Sorting:** To save time, the warehouse robots always keep crates sorted: they get heavier as you move **Right** and heavier as you move **Down**.<br>
- **The Mission:** Your manager needs the **kᵗʰ lightest crate** in the entire warehouse to fulfill a priority order.<br>

## Technical Hurdle
You could pull all the crates out and sort them in a long line, but that takes too much memory (O(n²)).<br>
The warehouse computer is old—it needs a solution with **better memory efficiency**.<br>

## Problem Statement / Function Requirement
Write a function that:<br>
- Takes a 2D integer array `matrix` and an integer `k`<br>
- Returns the kᵗʰ smallest element in the matrix<br>

**Matrix properties:**<br>
- Each row is sorted in ascending order<br>
- Each column is sorted in ascending order<br>

## Example Case
- **Input:** `matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]], k = 8`<br>
- **Sorted List view:** `[1, 5, 9, 10, 11, 12, 13, 13, 15]`<br>
- **8th Smallest:** `13`<br>

## Approaches

### 1. Priority Queue Approach (The Multi-Line Merge)

**Idea**<br>
Treat each row as a sorted line. Use a Min-Heap to efficiently get the next smallest element without merging all rows.<br>

**Steps**<br>
1. Insert the first element of each row into a Min-Heap.<br>
2. Pop the smallest element from the heap.<br>
3. Replace it with the next element from the same row, if available.<br>
4. Repeat k times. The kᵗʰ element popped is the answer.<br>

**Time Complexity**<br>
O(k log n) — heap operations for k elements<br>

**Space Complexity**<br>
O(n) — heap stores at most one element from each row<br>

**Drawback**<br>
Slightly slower for very large k values compared to the binary search approach.<br>

### 2. Binary Search Approach (The Guess & Check)

**Idea**<br>
Instead of simulating positions, search the **value range** of the matrix and count how many elements are smaller than a candidate value.<br>

**Steps**<br>
1. Set `low` = matrix[0][0] (lightest crate), `high` = matrix[n-1][n-1] (heaviest crate).<br>
2. While `low` ≤ `high`:<br>
   - Compute `mid` = (low + high) // 2.<br>
   - Count how many elements in the matrix are ≤ `mid` using **staircase search**:<br>
     - Start at bottom-left, move up if value > mid, move right if value ≤ mid.<br>
   - If count < k → `low` = mid + 1<br>
   - Else → `high` = mid - 1<br>
3. When loop ends, `low` is the kᵗʰ smallest element.<br>

**Time Complexity**<br>
O(n log(max - min)) — n for counting in each iteration, log(max - min) for binary search<br>

**Space Complexity**<br>
O(1) extra space<br>

## Conclusion
Both approaches efficiently find the kᵗʰ smallest crate in a sorted warehouse matrix.<br>
- Use **Priority Queue** for simplicity and moderate-sized matrices.<br>
- Use **Binary Search** for large matrices or memory-constrained environments.<br>
