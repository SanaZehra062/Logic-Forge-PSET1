# Challenge 3 – Balanced Performance Score

## Problem Overview
Two student teams worked on the **same coding lab**, but their scores were recorded **separately** and are already **sorted**.<br>
You are given:<br>
- `scoresA` → sorted scores of Team A<br>
- `scoresB` → sorted scores of Team B<br>
Your task is to find the **median score** after considering **both teams together**.<br>
You are **not allowed to fully merge** the two lists.<br>

## Problem Statement / Function Requirement
Write a function that:<br>
- Takes two sorted integer arrays: `scoresA` and `scoresB`<br>
- Returns the median value as a floating-point number<br>

The solution must run in:<br>
> O(m + n) time<br>

## Examples

**Example 1**<br>
Input:  scoresA = [1, 3], scoresB = [2]<br>
Output: 2.0<br>

**Example 2**<br>
Input:  scoresA = [1, 2], scoresB = [3, 4]<br>
Output: 2.5<br>
Explanation: Total elements = 4 (even), median = average of two middle values<br>

## Notes
- If the total number of elements is **odd**, the median is the **middle value**<br>
- If **even**, the median is the **average of the two middle values**<br>

## Constraints
- `0 ≤ m, n ≤ 1000`<br>
- `1 ≤ m + n ≤ 2000`<br>
- Arrays are already **sorted**<br>
- Values range from `-10⁶` to `10⁶`<br>

## Hint
Use **two-pointer traversal** approach:<br>
- Start with one pointer at the beginning of each array<br>
- Move the pointer with the smaller current value<br>
- Keep a count of how many elements have been seen<br>
- Stop when you reach the median position<br>
You do **not** need to store the merged array. You may simulate merging using indices, but must not create a merged array.<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
Merge the two arrays fully and then find the median directly.<br>

**Steps**<br>
- Merge `scoresA` and `scoresB` into a new array<br>
- If total elements is odd, return middle element<br>
- If even, return average of two middle elements<br>

**Time Complexity**<br>
O(m + n) for merging<br>

**Space Complexity**<br>
O(m + n) for merged array<br>

**Drawback**<br>
Extra space is required; not allowed by problem constraints<br>

### 2. Optimized Approach (Two-Pointer Traversal)

**Idea**<br>
Simulate merging using two pointers without actually creating a merged array.<br>

**Step-by-Step Explanation**<br>
- Initialize two pointers at the start of `scoresA` and `scoresB`<br>
- Count how many elements have been traversed<br>
- Keep track of the last one or two elements needed to compute median<br>
- Move the pointer with the smaller current value at each step<br>
- Stop when you reach the median position<br>
- Compute median based on total number of elements being odd/even<br>

**Time Complexity**<br>
O(m + n) — each element is visited at most once<br>

**Space Complexity**<br>
O(1) extra space<br>

## Conclusion
The two-pointer traversal efficiently finds the median of two sorted arrays without fully merging them.<br>
It satisfies linear time and minimal space requirements, making it ideal for production-level and interview scenarios.<br>
