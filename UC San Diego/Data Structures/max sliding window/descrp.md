## Maximum in Sliding Window

**Problem Introduction:**
Given a sequence 𝑎1, . . . , 𝑎𝑛 of integers and an integer 𝑚 ≤ 𝑛, find the maximum among {𝑎𝑖, . . . , 𝑎𝑖+𝑚−1} for every 1 ≤ 𝑖 ≤ 𝑛 − 𝑚 + 1. A naive 𝑂(𝑛𝑚) algorithm for solving this problem scans each window separately. Your goal is to design an 𝑂(𝑛) algorithm.

**Problem Description:**
- **Input Format:** 
  - The first line contains an integer 𝑛.
  - The second line contains 𝑛 integers 𝑎1, . . . , 𝑎𝑛 separated by spaces.
  - The third line contains an integer 𝑚.
- **Constraints:** 
  - 1 ≤ 𝑛 ≤ 10^5
  - 1 ≤ 𝑚 ≤ 𝑛
  - 0 ≤ 𝑎𝑖 ≤ 10^5 for all 1 ≤ 𝑖 ≤ 𝑛.
- **Output Format:** 
  - Output max{𝑎𝑖, . . . , 𝑎𝑖+𝑚−1} for every 1 ≤ 𝑖 ≤ 𝑛 − 𝑚 + 1.

**What to Do:**
- **Hint 1:**
  - Implement a queue using two stacks.
  - Use a queue data structure for sliding a window through a sequence.
  - For shifting a window one position to the right, pop the leftmost element of the queue and push a new element from the new window.
  - A queue can be implemented using two stacks such that each queue operation takes constant time on average.
  - Then, use your implementation of the stack with maximum.
  
- **Hint 2:**
  - Preprocess block suffixes and prefixes.
  - Partition the input sequence into blocks of length 𝑚 and precompute the maximum for every suffix and every prefix of each block.
  - Afterwards, the maximum in each sliding window can be found by considering a suffix and a prefix of two consecutive blocks.
  
- **Hint 3:**
  - Store relevant items in a dequeue.
  - Use a double-ended queue (dequeue) to store elements of the current window.
  - At the same time, store only relevant elements: before adding a new element drop all smaller elements.