**Problem Description: Binary Search with Duplicates**

Donald Knuth, author of The Art of Computer Programming, highlighted the complexity of binary search, especially when dealing with duplicates in a sorted array. This problem revolves around finding the index of the first occurrence of a key in a sorted array that may contain duplicates.

**Binary Search with Duplicates Problem:**

Given a sorted array of integers, potentially containing duplicates, and an integer query 'q,' your task is to find the index of the first occurrence of 'q' in the array. If 'q' is not present in the array, output "-1."

**Input:**
- The first line contains an integer 'n,' representing the size of the sorted array.
- The second line contains 'n' integers, the elements of the sorted array in non-decreasing order.
- The third line contains an integer 'm,' representing the number of queries.
- The fourth line contains 'm' integers, the queries you need to search for in the array.

**Output:**
For each query, output the index of the first occurrence of the query in the array. If the query is not present, output "-1."

**Constraints:**
- 1 ≤ n ≤ 3 · 10^4
- 1 ≤ m ≤ 10^5
- 1 ≤ array element ≤ 10^9
- 1 ≤ query ≤ 10^9

**Example:**
```
Input:
7
2 4 4 4 7 7 9
4
9 4 5 2

Output:
6 1 -1 0
```

**Explanation:**
- In the given example, the first occurrence indices for queries 9, 4, and 2 in the array are 6, 1, and 0, respectively. The query 5 is not present in the array, so the output for that query is -1.