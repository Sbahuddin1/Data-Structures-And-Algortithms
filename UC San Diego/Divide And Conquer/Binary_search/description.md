**Problem Description: Binary Search on Sorted Array**

You are given a sorted array `a` of integers. Your goal is to implement a program that performs binary search on this array efficiently. The program should find the index of each target value in a second array `b` within the sorted array `a`.

Write a program that takes the following inputs:

- The size of the first array `a` (n).
- The elements of the sorted array `a`.
- The size of the second array `b` (m).
- The elements of array `b`.

The program should output the index of each element from array `b` within array `a`. If an element is not found in array `a`, it should output -1.

**Algorithm:**

The program uses a binary search algorithm to efficiently locate each element from array `b` within the sorted array `a`. The binary search narrows down the search space in each iteration, ensuring a logarithmic time complexity.

**Input:**

- Size of the first array `a` (n).
- Elements of the sorted array `a`.
- Size of the second array `b` (m).
- Elements of array `b`.

**Output:**

The program outputs the indices of the elements from array `b` within the sorted array `a`. If an element is not found in array `a`, it outputs -1.

**Example:**

```
Input:
5            // Size of array a
1 2 3 4 5    // Elements of sorted array a
3            // Size of array b
2 4 6        // Elements of array b

Output:
1 3 -1       // Indices of elements from array b within array a
```

Note: The program efficiently performs binary search to find the positions of elements from array `b` in the sorted array `a`. If an element is not present, it outputs -1.