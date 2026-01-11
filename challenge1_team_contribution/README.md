**Challenge 1: Team Contribution Multiplier**<br><br>

**Problem Overview**<br>
You are part of a software engineering team working on a group project.<br>
Each team member contributes a performance score, which may be positive, negative, or zero.<br>
Your task is to analyze the impact of each member by calculating the overall team performance if that particular member is excluded.<br><br>

**Problem Statement**<br>
You are given an integer array `contributions`, where:<br>
`contributions[i]` represents the contribution score of the i-th team member.<br>
Create a new integer array `impact` such that:<br>
`impact[i] = product of all contributions[j] where j ≠ i`<br><br>

**Function Requirement**<br>
Write a function that:<br>
Takes an integer array `contributions`<br>
Returns an integer array `impact`<br>
Each element of `impact` is the product of all elements of `contributions` except itself<br><br>

**Constraints**<br>
Division is not allowed<br>
Time complexity must be O(n)<br>
Extra space usage should be minimal<br>
All results fit within a 32-bit integer<br><br>

**Examples**<br>

**Example 1**<br>
**Input**<br>
`contributions = [1, 2, 3, 4]`<br>
**Output**<br>
`impact = [24, 12, 8, 6]`<br><br>

**Explanation**<br>
Excluding index 0 → 2 × 3 × 4 = 24<br>
Excluding index 1 → 1 × 3 × 4 = 12<br>
Excluding index 2 → 1 × 2 × 4 = 8<br>
Excluding index 3 → 1 × 2 × 3 = 6<br><br>

**Approaches**<br>

**1. Brute Force Approach**<br>

**Idea**<br>
For each index `i`, calculate the product of all elements except `contributions[i]`.<br>

**Steps**<br>
Initialize an empty array `impact`<br>
For each index `i`:<br>
Initialize `product = 1`<br>
Loop through the array again<br>
Multiply all elements except when index equals `i`<br>
Store the result in `impact[i]`<br>

**Time Complexity**<br>
O(n²)<br>

**Space Complexity**<br>
O(1) (excluding output array)<br>

**Drawback**<br>
Inefficient for large arrays due to nested loops<br><br>

**2. Optimized Approach (Prefix and Suffix Products)**<br>

**Idea**<br>
Instead of recomputing products repeatedly:<br>
Store the product of all elements to the left of each index<br>
Store the product of all elements to the right of each index<br>
Multiply both to get the final result<br>

**Step-by-Step Explanation**<br>
Create an output array `impact`<br>
First pass (Left Products):<br>
`impact[i]` stores the product of all elements before index `i`<br>
Second pass (Right Products):<br>
Maintain a variable `rightProduct`<br>
Multiply `impact[i]` by `rightProduct`<br>
Update `rightProduct` by multiplying with `contributions[i]`<br>

**Example**<br>
For:<br>
`contributions = [1, 2, 3, 4]`<br>
Left products → `[1, 1, 2, 6]`<br>
Right products applied → `[24, 12, 8, 6]`<br>

**Time Complexity**<br>
O(n)<br>

**Space Complexity**<br>
O(1) extra space (output array excluded)<br>

**Conclusion**<br>
The optimized prefix-suffix approach efficiently solves the problem within linear time and without using division.<br>
It is the recommended solution for production-level and interview-ready implementations.<br>
