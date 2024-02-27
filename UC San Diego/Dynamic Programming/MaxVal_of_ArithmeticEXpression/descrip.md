## Maximum Value of an Arithmetic Expression

#### Problem Description
Given an arithmetic expression consisting of digits, plus, minus, and multiplication signs, the task is to parenthesize the expression in order to maximize its value.

For example, for the expression `(3 + 2 × 4)`, there are two ways of parenthesizing it: `(3 + (2 × 4)) = 11` and `((3 + 2) × 4) = 20`.

#### Input
The input consists of a single line containing a string `s` of length `2n + 1` for some `n`, where:
- Each symbol at an even position of `s` is a digit (an integer from 0 to 9).
- Each symbol at an odd position of `s` is one of the three operations from {+, -, *}.

#### Output
The output should be the maximum value of the given arithmetic expression among all possible orders of applying arithmetic operations.

#### Constraints
- 0 ≤ n ≤ 14 (hence the string contains at most 29 symbols).

#### Example
Input:
```
5-8+7*4-8+9
```

Output:
```
200
```

Explanation:
```
200 = (5 − ((8 + 7) × (4 − (8 + 9))))
```

#### Approach
This problem can be efficiently solved using dynamic programming, specifically the tabulation approach. We'll construct a table to store the maximum and minimum values of subexpressions and fill it iteratively considering all possible splits of the expression into subexpressions and all possible operations between them. Finally, we return the maximum value of the entire expression.

### Implementation Details
The implementation is provided in [this repository](link_to_code).