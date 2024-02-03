## Problem Description:

You are organizing a competition for children, and you have a certain number of candies (n) to distribute as prizes. The objective is to distribute these candies among the top places in the competition, with the condition that higher places receive a larger number of candies. To maximize the number of happy children, your task is to find the largest value of `k` for which it is possible to represent `n` as the sum of `k` pairwise distinct positive integers.

### Approach:

1. Find the maximum value of `k` such that `n` can be represented as the sum of `k` distinct positive integers.
2. Output the value of `k`.
3. Output `k` pairwise distinct positive integers that sum up to `n`. If there are multiple valid representations, any of them can be output.

### Example:

**Input:**
```
6
```

**Output:**
```
3
1 2 3
```

**Explanation:**
For the input value of `6`, the maximum `k` is `3`, and the pairwise distinct positive integers are `1 + 2 + 3`.

### Example:

**Input:**
```
8
```

**Output:**
```
3
1 2 5
```

**Explanation:**
For the input value of `8`, the maximum `k` is `3`, and the pairwise distinct positive integers are `1 + 2 + 5`. Multiple valid representations exist; this is just one possible solution.

These examples illustrate how the program determines the maximum number of pairwise distinct positive integers (`k`) for a given number of candies (`n`) and outputs a valid distribution to make as many children happy as possible in a competition.