# Speeding-up RandomizedQuickSort

## Problem Description

Your task is to modify the RandomizedQuickSort algorithm to achieve an expected running time of O(nlogn) even on sequences containing many repeated elements. The original RandomizedQuickSort algorithm works efficiently when all elements of the array are distinct, but it becomes slow when there are duplicates.

Right now the naive algorithm runs with time complexity O(n^2).
The faster algorithm is the solution, first try solving it on your own.

The goal is to implement a modification of RandomizedQuickSort that efficiently handles sequences with duplicate elements.

## Input

The input consists of two lines:
1. The first line contains an integer `n` (1 ≤ n ≤ 10^5), representing the number of elements in the sequence.
2. The second line contains a sequence of `n` integers `a0, a1, ..., an-1` (1 ≤ ai ≤ 10^9), representing the elements of the sequence.

## Output

Output the sorted sequence in non-decreasing order.

## Constraints

- 1 ≤ n ≤ 10^5
- 1 ≤ ai ≤ 10^9 for all 0 ≤ i < n

## Sample

### Input

```
5
2 3 9 2 2
```

### Output

```
2 2 2 3 9
```

## Explanation

In the given example, the modified RandomizedQuickSort algorithm efficiently handles the sequence with repeated elements and produces the sorted output [2, 2, 2, 3, 9].
