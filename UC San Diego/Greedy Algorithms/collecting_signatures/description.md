# Problem Description: Collecting Signatures

## Problem

You are responsible for collecting signatures from all tenants in a building. For each tenant, you know a period of time when he or she is at home. You would like to collect all signatures by visiting the building as few times as possible. For simplicity, we assume that when you enter the building, you instantly collect the signatures of all tenants that are in the building at that time.

Given a sequence of segments [l₁, r₁], ..., [lₙ, rₙ] on a line, find the minimum number of points needed to cover all segments. A point x is sufficient if there exists a point x such that li ≤ x ≤ ri for each segment [li, ri].

### Input

The input consists of two lines:
1. The first line contains the number n of segments.
2. Each of the following n lines contains two integers li and ri (separated by a space) defining the coordinates of endpoints of the i-th segment.

### Output

Print the minimum number k of points on the first line and the integer coordinates of k points (separated by spaces) on the second line. You can output the points in any order. If there are multiple such sets of points, you can output any of them.

### Example

#### Input
```
3
1 3
2 5
3 6
```
#### Output
```
1
3
```
All three segments [1,3], [2,5], [3,6] contain the point with coordinate 3.

#### Input
```
4
4 7
1 3
2 5
5 6
```
#### Output
```
2
3 6
```
The second and the third segments contain the point with coordinate 3 while the first and the fourth segments contain the point with coordinate 6. All segments cannot be covered by a single point, since the segments [1,3] and [5,6] do not overlap. Another valid solution in this case is the set of points 2 and 5.

## Algorithm

To minimize the number of points, sort the segments based on their ending points. Iterate through the sorted segments, and for each segment, add the ending point to the set of points. This ensures that the point selected will cover as many segments as possible. Repeat this process for all segments.

## Constraints

1 ≤ n ≤ 100  
0 ≤ li ≤ ri ≤ 10⁹ for all i.