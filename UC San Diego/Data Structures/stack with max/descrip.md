## Extending Stack Interface

**Problem Introduction:**
A stack is an abstract data type supporting the operations `Push()` and `Pop()`. It is possible to implement these operations such that they work in constant time. In this problem, the goal is to implement a stack that also supports finding the maximum value, while ensuring that all operations still work in constant time.

**Problem Description:**
Your task is to implement a stack supporting the operations `Push()`, `Pop()`, and `Max()`.

**Input Format:**
- The first line of the input contains the number 𝑞 of queries.
- Each of the following 𝑞 lines specifies a query of one of the following formats: push v, pop, or max.

**Constraints:**
- 1 ≤ 𝑞 ≤ 400,000
- 0 ≤ 𝑣 ≤ 10^5

**Output Format:**
- For each max query, output (on a separate line) the maximum value of the stack.

**Time Limits:**
- C, C++, Java: 1 second
- Python: 1.5 seconds
- C#: 5 seconds
- Haskell: 1.5 seconds
- JavaScript, Ruby: 2 seconds
- Scala: 5 seconds

**Memory Limit:** 512MB

**Sample Input and Output:**

Input:
```
5
push 2
push 1
max
pop
max
```

Output:
```
2
2
```

Explanation:
After the first two push queries, the stack contains elements 1 and 2. After the pop query, the element 1 is removed.

Input:
```
3
push 1
push 7
pop
```

Output:
```
```

Explanation:
The output is empty since there are no max queries.

**Starter Files:**
The starter solutions in C++, Java, and Python3 process the queries naively: for each max query they scan the current contents of the stack to find the maximum value. Hence the max query has running time proportional to the size of the stack. Your goal is to modify it so that its running time becomes constant. For other programming languages, you need to implement a solution from scratch.

**What to Do:**
Think about using an auxiliary stack.