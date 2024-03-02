### Grid Traveler

**Problem Introduction:**
In this problem, you're tasked with finding the number of ways to travel from the top-left corner to the bottom-right corner of a grid, while only being able to move either down or right at each step. 

**Problem Description:**
You are given a grid of size `n x m`, where `n` represents the number of rows and `m` represents the number of columns. Starting from the top-left corner, your goal is to reach the bottom-right corner of the grid. You can only move either down or right at each step.

**Input:**
- The input consists of two integers `n` and `m` separated by a space, representing the dimensions of the grid.
- Constraints: 1 ≤ `n`, `m` ≤ 100

**Output:**
- Output a single integer representing the number of possible ways to travel from the top-left corner to the bottom-right corner of the grid.

**Example:**
```
Input:
2 3

Output:
3

Explanation:
In a 2 x 3 grid, there are 3 possible ways to travel from the top-left corner to the bottom-right corner:
1. Right, Right, Down
2. Right, Down, Right
3. Down, Right, Right
```

**Approach:**
You can solve this problem using dynamic programming. Maintain a memoization table to store the number of ways to reach each cell in the grid. Start from the top-left corner and recursively explore all possible paths to reach the bottom-right corner. Use memoization to avoid redundant computations and improve efficiency.

**Time Complexity:**
The time complexity of this approach is O(n * m), where n is the number of rows and m is the number of columns in the grid. This is because you need to compute the number of ways to reach each cell in the grid exactly once.