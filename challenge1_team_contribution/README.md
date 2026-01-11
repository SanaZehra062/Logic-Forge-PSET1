# Challenge 1 – Team Contribution Multiplier

## Problem Overview
You are part of a software engineering team working on a group project.<br>
Each team member contributes a performance score, which may be positive, negative, or zero.<br>
Your task is to analyze the impact of each member by calculating the overall team performance if that particular member is excluded.<br>

## Problem Statement
You are given an integer array `contributions`, where:<br>
- `contributions[i]` represents the contribution score of the i-th team member<br>
Create a new integer array `impact` such that:<br>
- `impact[i] = product of all contributions[j] where j ≠ i`<br>

## Function Requirement
Write a function that:<br>
- Takes an integer array `contributions`<br>
- Returns an integer array `impact`<br>
- Each element of `impact` is the product of all elements of `contributions` except itself<br>

## Constraints
- Division is not allowed<br>
- Time complexity must be O(n)<br>
- Extra space usage should be minimal<br>
- All results fit within a 32-bit integer<br>

## Examples

**Example 1**<br>
Input:<br>
`contributions = [1, 2, 3, 4]`<br>
Output:<br>
`impact = [24, 12, 8, 6]`<br>

**Explanation**<br>
- Excluding index 0 → 2 × 3 × 4 = 24<br>
- Excluding index 1 → 1 × 3 × 4 = 12<br>
- Excluding index 2 → 1 × 2 × 4 = 8<br>
- Excluding index 3 → 1 × 2 × 3 = 6<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
For each index `i`, calculate the product of all elements except `contributions[i]`.<br>

**Steps**<br>
- Initialize an empty array `impact`<br>
- For each index `i`:<br>
  - Initialize `product = 1`<br>
  - Loop through the array again<br>
  - Multiply all elements except when index equals `i`<br>
  - Store the result in `impact[i]`<br>

**Time Complexity**<br>
O(n²)<br>

**Space Complexity**<br>
O(1) (excluding output array)<br>

**Drawback**<br>
Inefficient for large arrays due to nested loops<br>

### 2. Optimized Approach (Prefix and Suffix Products)

**Idea**<br>
Instead of recomputing products repeatedly:<br>
- Store the product of all elements to the left of each index<br>
- Store the product of all elements to the right of each index<br>
- Multiply both to get the final result<br>

**Step-by-Step E**
