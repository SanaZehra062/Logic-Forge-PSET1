# Challenge 2 – Password Recovery Window

## Problem Overview
You are given two strings:<br>
- `log` → a string representing system activity<br>
- `pattern` → characters required to recover a password<br>
Your task is to find the **smallest continuous substring of `log`** that contains **all characters of `pattern`**, including **duplicate characters**.<br>
If no such substring exists, return an empty string `""`.<br>

## Problem Statement
Given strings `log` and `pattern`, find the **minimum window substring** of `log` that contains all characters of `pattern`. If no valid window exists, return `""`.<br>

## Function Requirement
Write a function that:<br>
- Takes two strings: `log` and `pattern`<br>
- Returns the minimum window substring of `log` containing all characters of `pattern`<br>
- Returns `""` if no such window exists<br>

**Rules:**<br>
- The order of characters does **not** matter<br>
- The substring must be **continuous**<br>
- The answer will be **unique** if it exists<br>

## Examples

**Example 1**<br>
Input:  log = "ADOBECODEBANC", pattern = "ABC"<br>
Output: "BANC"<br>

**Example 2**<br>
Input:  log = "a", pattern = "a"<br>
Output: "a"<br>

**Example 3**<br>
Input:  log = "a", pattern = "aa"<br>
Output: ""<br>

## Constraints
- `1 ≤ len(log), len(pattern) ≤ 10⁵`<br>
- Strings contain uppercase and lowercase English letters<br>

## Hint
Use a **sliding window** approach:<br>
- Expand the window to include required characters<br>
- Shrink it to find the **minimum valid window**<br>
- Use character frequency counting<br>

**Target Complexity:** `O(m + n)`<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
Check every possible substring of `log` to see if it contains all characters of `pattern`.<br>

**Steps**<br>
- Initialize `minWindow` as empty or infinity-length string<br>
- Loop through all substrings of `log`<br>
- For each substring, count frequency of characters<br>
- Compare with `pattern` frequency<br>
- Update `minWindow` if substring is valid and smaller<br>

**Time Complexity**<br>
O(n³) in worst case (checking all substrings and character counts)<br>

**Space Complexity**<br>
O(n + m) for frequency counters<br>

**Drawback**<br>
Extremely inefficient for large strings<br>

### 2. Optimized Approach (Sliding Window)

**Idea**<br>
Use two pointers to maintain a sliding window that contains all required characters, and adjust window size to find minimum.<br>

**Step-by-Step Explanation**<br>
- Create a frequency map of `pattern`<br>
- Initialize `start`, `end` pointers and `formed` counter<br>
- Expand `end` to include characters<br>
- Shrink `start` to remove extra characters while keeping window valid<br>
- Update `minWindow` when a valid window is found<br>

**Time Complexity**<br>
O(n + m), where n = length of `log` and m = length of `pattern`<br>

**Space Complexity**<br>
O(n + m) for frequency maps<br>

## Conclusion
The optimized sliding window approach efficiently finds the minimum window substring containing all characters of `pattern` in linear time and minimal extra space.<br>
This is the recommended solution for production-level and interview-ready implementations.<br>
