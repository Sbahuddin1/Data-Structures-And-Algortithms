## Primitive Calculator Problem

You are given a primitive calculator that can perform only three operations on a positive integer \( x \):

1. Add 1 to \( x \).
2. Multiply \( x \) by 2.
3. Multiply \( x \) by 3.

Your task is to find the minimum number of operations needed to obtain a given positive integer \( n \) starting from the number 1.

**Input:**
- An integer \( n \) (\( 1 \leq n \leq 10^6 \)).

**Output:**
- The minimum number of operations required to obtain \( n \) from 1.
- A sequence of intermediate numbers. The sequence should contain positive integers \( a_0, a_1, \ldots, a_k \) such that \( a_0 = 1 \), \( a_k = n \), and for all \( 1 \leq i \leq k \), \( a_i \) is equal to either \( a_{i-1} + 1 \), \( 2 \times a_{i-1} \), or \( 3 \times a_{i-1} \).

**Constraints:**
- \( 1 \leq n \leq 10^6 \)

**Examples:**
```
Input:
1
Output:
0
1

Input:
96234
Output:
14
1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234
```

Given a positive integer \( n \), your task is to determine the minimum number of operations needed to obtain \( n \) starting from 1 and provide a sequence of intermediate numbers that achieves this minimum.