# Problem Description:

Given a sequence of integers, the task is to compute the number of inversions in the sequence, where an inversion is defined as a pair of indices (i, j) such that ai > aj. The goal is to measure how close the sequence is to being sorted.

#### Input:

- The first line contains an integer n (1 ≤ n ≤ 30,000).
- The second line contains a sequence of n integers a1, ..., an (1 ≤ ai ≤ 1,000,000,000).

#### Output:

- The number of inversions in the sequence.

#### Example:

**Input:**

```
5
2 3 9 2 9
```

**Output:**

```
2
```

The two inversions here are (2, 4) (a2 = 3 > 2 = a4) and (3, 4) (a3 = 9 > 2 = a4).

## Explanation:

An inversion occurs when a larger element precedes a smaller one in the sequence. For example:

- (2, 4): The element at index 2 (3) is greater than the element at index 4 (2).
- (3, 4): The element at index 3 (9) is greater than the element at index 4 (2).

## Problem Analysis:

A naive algorithm would involve checking all possible pairs of indices, resulting in a time complexity of O(n^2). However, an optimized approach involves using the divide-and-conquer technique. The input array is split into two halves, and a recursive call is made on both halves. The key step is computing the number of inversions formed by two elements from different halves. If both halves are already sorted, this can be done in O(n) time.

## Exercise Break:

Modify the MergeSort algorithm to solve this problem efficiently.

### Constraints:

- 1 ≤ n ≤ 30,000
- 1 ≤ ai ≤ 1,000,000,000 (for all 1 ≤ i ≤ n)
