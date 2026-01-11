# Challenge 5 – Fix the Broken Expression

## Problem Overview
You are given a string `expr` containing:<br>
- Lowercase letters<br>
- Parentheses `'('` and `')'`<br>

Some parentheses may be **misplaced**.<br>
A string is valid if every opening `'('` has a matching closing `')'` in the correct order.<br>
Your task is to remove the **minimum number of parentheses** so that the resulting string is **valid**.<br>
Return **all unique valid strings** that can be formed with the **minimum removals**.<br>
You may return the answers in **any order**.<br>

## Problem Statement / Function Requirement
Write a function that:<br>
- Takes a string `expr`<br>
- Returns a list of all valid strings with minimum parentheses removals<br>

## Examples

**Example 1**<br>
Input:  `"()())()"`<br>
Output: `["(())()", "()()()"]`<br>

**Example 2**<br>
Input:  `"(a)())()"`<br>
Output: `["(a())()", "(a)()()"]`<br>

**Example 3**<br>
Input:  `")("`<br>
Output: `[""]`<br>

**Example 4**<br>
Input:  `"()"`<br>
Output: `["()"]`<br>

**Example 5**<br>
Input:  `"abc"`<br>
Output: `["abc"]`<br>

**Example 6**<br>
Input:  `"((("`<br>
Output: `[""]`<br>

## Constraints
- `1 ≤ length of expr ≤ 25`<br>
- At most **20 parentheses**<br>
- Letters must remain unchanged<br>

## Hint
- First, count how many `'('` and `')'` must be removed<br>
- Then try removing parentheses step by step while keeping the string valid<br>
- Stop once **minimum removals** are reached<br>
- Avoid duplicate results<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
Generate all possible strings by removing parentheses and check for validity.<br>

**Steps**<br>
- Generate all combinations of removals<br>
- Check each string for balanced parentheses<br>
- Keep only those with minimum removals<br>
- Remove duplicates<br>

**Time Complexity**<br>
Exponential in the number of parentheses: O(2^p), where p = number of parentheses<br>

**Space Complexity**<br>
O(2^p) to store all candidate strings<br>

**Drawback**<br>
Very slow for strings with many parentheses<br>

### 2. Optimized Approach (BFS / DFS with Pruning)

**Idea**<br>
Use BFS or DFS to explore only valid removal paths and stop once minimum removals are reached.<br>

**Steps**<br>
- Count extra `'('` and `')'` to remove<br>
- Recursively try removing parentheses<br>
- Skip invalid paths early (prune)<br>
- Use a set to avoid duplicates<br>
- Collect all strings that reach **balanced state** with minimum removals<br>

**Time Complexity**<br>
Much faster than brute force; depends on number of valid paths<br>

**Space Complexity**<br>
O(number of valid strings) for result set<br>

## Conclusion
Using BFS or DFS with pruning efficiently finds all valid strings with minimum parentheses removals.<br>
This approach avoids unnecessary computation and ensures uniqueness of results.<br>
It is suitable for small to moderate-sized input strings and aligns with the problem constraints.<br>
