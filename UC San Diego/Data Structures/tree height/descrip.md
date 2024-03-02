## Problem Description

In this problem, you are given a description of a rooted tree, and your task is to compute and output its height. Recall that the height of a rooted tree is the maximum depth of a node, or the maximum distance from a leaf to the root.

### Input Format

The input consists of two lines:
1. The first line contains an integer 𝑛, the number of nodes in the tree.
2. The second line contains 𝑛 space-separated integers representing the parent indices of the nodes. If the 𝑖-th integer is -1, it means that the 𝑖-th node is the root. Otherwise, it indicates the 0-based index of the parent of the 𝑖-th node.

### Constraints

- 1 ≤ 𝑛 ≤ 10^5

### Output Format

Output the height of the tree.

### Examples

Input
```
5
4 -1 4 1 1
```

Output
```
3
```

Explanation:
The input describes a tree with 5 nodes. The second line indicates the parent indices for each node. Node 1 is the root, and its children are nodes 3 and 4. Node 4 has children nodes 0 and 2. The height of this tree is 3, as the longest path from the root to a leaf node has 3 edges.

---

Input
```
5
-1 0 4 0 3
```

Output
```
4
```

Explanation:
The input describes another tree with 5 nodes. The root node is node 0, and its children are nodes 1 and 3. Node 3 has a child node 4, which has a child node 2. The height of this tree is 4, as the longest path from the root to a leaf node has 4 edges.

### Implementation Approach

To solve this problem, you need to implement an algorithm to compute the height of the given tree. One approach is to traverse the tree in a bottom-up manner, starting from the leaf nodes and gradually moving towards the root. You can use dynamic programming to store the height of each node and then compute the height of the tree. Additionally, you can take advantage of the fact that the labels for each tree node are integers in the range 0 to 𝑛−1, allowing you to store each node in an array for efficient access.