## Maximum Amount of Gold

### Problem Description
You are a treasure hunter exploring a cave filled with gold bars of various weights. You have a backpack that can hold at most W pounds of gold. Your goal is to maximize the total weight of gold bars you can carry out of the cave.

#### Input
The input consists of:
- An integer W (capacity of the backpack), representing the maximum weight your backpack can hold.
- An integer n (number of gold bars), representing the total number of gold bars available in the cave.
- A line containing n integers w1, w2, ..., wn, where wi represents the weight of the ith gold bar.

#### Output
The output should be the maximum weight of gold bars that fits into the backpack of capacity W.

#### Constraints
- 1 ≤ W ≤ 10^4
- 1 ≤ n ≤ 300
- 0 ≤ wi ≤ 10^5

### Example
Input:
```
10 3
1 4 8
```
Output:
```
9
```
### Explanation
You have a backpack with a capacity of 10 pounds. There are three gold bars available in the cave with weights 1, 4, and 8 pounds respectively. The maximum weight of gold bars that fits into the backpack without exceeding its capacity is 9 pounds. One possible combination is to take the first and third gold bars, which have weights 1 and 8 pounds respectively, resulting in a total weight of 9 pounds.

### Approach
This problem can be efficiently solved using dynamic programming. We'll use a bottom-up tabulation approach to fill a table where each cell (i, w) represents the maximum weight of gold bars that can be placed in a backpack of capacity w using the first i gold bars. By iteratively considering whether to include each gold bar in the backpack, we can compute the maximum weight that can be carried out of the cave.