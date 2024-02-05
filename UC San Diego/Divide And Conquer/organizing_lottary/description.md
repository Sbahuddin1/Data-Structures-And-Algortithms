## Organizing a Lottery

### Points and Segments Problem

You are organizing an online lottery where participants bet on a single integer. The lottery draws several segments of consecutive integers at random, and a participant's payoff is proportional to the number of segments that contain the participant's chosen number. Your goal is to compute the payoffs efficiently for all participants.

### Input

- The first line contains two non-negative integers **n** and **m**, representing the number of segments and the number of points on a line, respectively.
- The next **n** lines contain two integers **li** and **ri**, defining the **i-th segment [li, ri]**.
- The next line contains **m** integers **p1, ..., pm**, representing the points chosen by participants.

### Output

- **m** non-negative integers **k1, ..., km**, where **ki** is the number of segments that contain the corresponding point **pi**.

### Constraints

- **1 ≤ n, m ≤ 50000**
- **-10^8 ≤ li ≤ ri ≤ 10^8** for all **1 ≤ i ≤ n**
- **-10^8 ≤ pj ≤ 10^8** for all **1 ≤ j ≤ m**

### Examples

#### Sample 1
**Input:**
```
2 3
0 5
7 10
1 6 11
```
**Output:**
```
1 0 0
```
Explanation: There are two segments and three points. The first point lies only in the first segment, while the remaining two points are outside of all segments.

#### Sample 2
**Input:**
```
1 3
-10 10
-100 100 0
```
**Output:**
```
0 0 1
```
Explanation: There is one segment, and the third point (0) lies within it.

#### Sample 3
**Input:**
```
3 2
0 5
-3 2
7 10
1 6
```
**Output:**
```
2 0
```
Explanation: The first point lies in the first two segments, while the second point lies outside all segments.