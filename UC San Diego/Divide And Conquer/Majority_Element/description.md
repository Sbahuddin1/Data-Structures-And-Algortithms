# Problem Description:

You are given an array representing votes in an election. Each element in the array represents a vote for a candidate, and your task is to determine if there is a majority candidate, i.e., a candidate who received more than half of the votes.

The program takes the size of the array `n` as input, where `n` is the number of votes. It then takes the actual votes in the form of an array `a`. The goal is to find whether there is a majority candidate.
If the any element in the array is repeated more than `n/2` times, return `1` otherwise `0`.

### Approach 1: Boyer-Moore Voting Algorithm

1. If the range of the array has only one element, return that element as a potential majority candidate.
2. Use Boyer-Moore Voting Algorithm to find a potential majority candidate.
3. After finding the potential candidate, count the actual occurrences of this candidate in the given range.
4. If the count of the candidate is greater than half the size of the range, it is considered the majority candidate.
5. If no majority candidate is found, return -1.

### Approach 2: Map-based Counting

1. If the range of the array has only one element, return that element as a potential majority candidate.
2. Use a map (`mp`) to keep track of the count of each unique element in the given range.
3. For each element in the array, check if it's already present in the map. If yes, increment its count; if not, add it to the map with a count of 1.
4. While updating the count of an element, check if it has become greater than half the size of the range. If yes, return 1, indicating the presence of a majority candidate.
5. If no majority candidate is found, return -1.

### Example:

**Input:**
```
5
3 3 4 2 3
```

**Output:**
```
1
```

**Explanation:**
In this example, both approaches correctly identify the presence of a majority candidate (`3`). After counting its occurrences, the result is `3`, which is greater than half the size of the array.

These problems are commonly encountered in scenarios where you want to determine if there is a clear winner in an election based on the majority of votes for a specific candidate. The approaches provide different strategies, one using Boyer-Moore Voting Algorithm and the other utilizing a map for efficient counting of occurrences.