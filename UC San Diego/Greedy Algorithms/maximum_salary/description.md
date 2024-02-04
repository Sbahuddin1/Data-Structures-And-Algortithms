# Problem Description: Maximum Salary

## Problem

You are tasked with composing the largest number possible by concatenating a sequence of positive integers. The resulting number will represent your salary, so your goal is to maximize it. Given a sequence of positive integers, find the largest integer that can be obtained by concatenating them in some order.

### Input

The input consists of two lines:
1. The first line contains an integer `n` (1 ≤ n ≤ 100), representing the number of positive integers in the sequence.
2. The second line contains `n` space-separated integers a₁, ..., aₙ (1 ≤ aᵢ ≤ 10³) representing the positive integers in the sequence.

### Output

Print the largest number that can be composed by concatenating the given integers in some order.

### Example

#### Input
```
2
21 2
```
#### Output
```
221
```
Note: In this case, sorting the input in decreasing order results in the correct answer.

#### Input
```
5
9 4 6 1 9
```
#### Output
```
99641
```
Note: The input consists of single-digit numbers only, and sorting them in decreasing order produces the correct answer.

#### Input
```
3
23 39 92
```
#### Output
```
923923
```
Note: The algorithm producing the incorrect answer still results in the correct output for this case.

## Algorithm

To maximize the salary, sort the input integers with respect to a custom ordering. The custom ordering should prioritize the arrangement that produces the largest concatenated number. Ensure to define this ordering carefully, considering cases where the straightforward sorting of digits may not be sufficient.

## Constraints

1 ≤ n ≤ 100  
1 ≤ aᵢ ≤ 10³ for all 1 ≤ i ≤ n.