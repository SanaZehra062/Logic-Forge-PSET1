# Challenge 6 – Tower of Hanoi Algorithm<br>

## Problem Overview<br>
Tower of Hanoi is a classical mathematical puzzle involving three rods (A, B, and C) and N disks.<br>
All disks are initially placed on rod A in decreasing order of size, with the smallest disk on top.<br>
The goal is to move all disks from rod A to rod C while following the defined rules.<br><br>

## Rules<br>
- Only one disk can be moved at a time<br>
- A disk can only be moved if it is the top disk on a rod<br>
- A larger disk cannot be placed on top of a smaller disk<br><br>

## Function Requirement<br>
Write a function that:<br>
- Takes an integer N representing the number of disks<br>
- Prints all the moves required to transfer the disks from rod A to rod C using rod B as auxiliary<br><br>

## Example Case<br>
Input: 3<br><br>

Output:<br>
Disk 1 moved from A to C<br>
Disk 2 moved from A to B<br>
Disk 1 moved from C to B<br>
Disk 3 moved from A to C<br>
Disk 1 moved from B to A<br>
Disk 2 moved from B to C<br>
Disk 1 moved from A to C<br><br>

## Approaches<br>

### 1. Brute Force Approach (Recursive Simulation)<br>

#### Idea<br>
This approach directly simulates the problem by recursively trying all required moves.<br>
Each disk movement is explicitly generated according to the rules until the destination is reached.<br>

#### Steps<br>
- Move N-1 disks from source rod to auxiliary rod<br>
- Move the largest disk from source rod to destination rod<br>
- Move N-1 disks from auxiliary rod to destination rod<br>

#### Time Complexity<br>
O(2^N) — all possible required moves are generated<br>

#### Space Complexity<br>
O(N) — recursive call stack space<br>

#### Drawback<br>
This approach is not efficient for large values of N due to exponential growth in moves.<br>

### 2. Optimized Approach (Pattern-Based / Efficient Recursive Strategy)<br>

#### Idea<br>
Instead of treating the problem as random disk movements, this approach follows a fixed recursive pattern.<br>
The solution is built using divide-and-conquer, minimizing unnecessary checks and ensuring only valid moves are performed.<br>

#### Steps<br>
- Break the problem into smaller subproblems of size N-1<br>
- Solve each subproblem optimally using recursion<br>
- Combine results to move the largest disk efficiently<br>

#### Time Complexity<br>
O(2^N) — minimum number of moves required to solve the puzzle<br>

#### Space Complexity<br>
O(N) — recursion depth remains linear<br>

#### Advantage<br>
This approach ensures the minimum number of moves and avoids redundant or invalid operations.<br>

## Conclusion<br>
The Tower of Hanoi problem demonstrates the power of recursion and divide-and-conquer techniques.<br>
While the brute force approach simulates all moves directly, the optimized approach follows an efficient pattern that guarantees the optimal solution.<br>
Both approaches ultimately reach the same result but differ in clarity and efficiency of execution.<br>
