# Challenge 6 – Tower of Hanoi Algorithm

## Problem Overview
Tower of Hanoi is a mathematical puzzle where we have three rods (**A**, **B**, and **C**) and **N** disks.<br>
Initially, all the disks are stacked in decreasing value of diameter (the smallest disk is on top) on rod **A**.<br>
The objective is to move the entire stack to rod **C** while following these rules:<br>

- Only one disk can be moved at a time<br>
- Each move consists of taking the upper disk from one stack and placing it on top of another stack<br>
- No disk may be placed on top of a smaller disk<br>

## Function Requirement
Write a recursive function that:<br>
- Takes `N` (number of disks), `from_rod`, `to_rod`, and `aux_rod`<br>
- Prints the moves required to shift all disks from `from_rod` to `to_rod`<br>

## Examples

**Input:** 2<br>
**Output:**<br>
Disk 1 moved from A to B<br>
Disk 2 moved from A to C<br>
Disk 1 moved from B to C<br>

**Input:** 3<br>
**Output:**<br>
Disk 1 moved from A to C<br>
Disk 2 moved from A to B<br>
Disk 1 moved from C to B<br>
Disk 3 moved from A to C<br>
Disk 1 moved from B to A<br>
Disk 2 moved from B to C<br>
Disk 1 moved from A to C<br>

**Input:** 4<br>
**Output:**<br>
Disk 1 moved from A to B<br>
Disk 2 moved from A to C<br>
Disk 1 moved from B to C<br>
Disk 3 moved from A to B<br>
Disk 1 moved from C to A<br>
Disk 2 moved from C to B<br>
Disk 1 moved from A to B<br>
Disk 4 moved from A to C<br>
Disk 1 moved from B to C<br>
Disk 2 moved from B to A<br>
Disk 1 moved from C to A<br>
Disk 3 moved from B to C<br>
Disk 1 moved from A to B<br>
Disk 2 moved from A to C<br>
Disk 1 moved from B to C<br>

## Approach

### Recursive Solution

**Idea**<br>
Use recursion to move disks using the auxiliary rod.<br>

**Steps**<br>
1. Shift `N-1` disks from `from_rod` to `aux_rod`, using `to_rod` as helper<br>
2. Move the last disk from `from_rod` to `to_rod`<br>
3. Shift `N-1` disks from `aux_rod` to `to_rod`, using `from_rod` as helper<br>

**Function Definition**<br>
```python
def towerOfHanoi(N, from_rod, to_rod, aux_rod):
    if N == 1:
        print(f"Disk 1 moved from {from_rod} to {to_rod}")
        return
    towerOfHanoi(N-1, from_rod, aux_rod, to_rod)
    print(f"Disk {N} moved from {from_rod} to {to_rod}")
    towerOfHanoi(N-1, aux_rod, to_rod, from_rod)
