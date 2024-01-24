**Problem Description: Efficient Car Refueling**

You are planning a road trip from point A to point B, and your car has a limited fuel tank capacity. Along the way, there are multiple gas stations, each located at different distances from each other. Your goal is to minimize the number of refills needed to reach your destination, ensuring you never run out of fuel.

Write a program that takes the following inputs:

- The total distance from point A to point B (d).
- The maximum distance the car can travel with a full tank (tank).
- The number of gas stations between A and B (n).
- Distances between each gas station and the starting point A.

The program should output the minimum number of refills required to reach point B.

**Algorithm:**

The program uses a greedy approach to efficiently plan refuels. It iterates through the gas stations, selecting the farthest station reachable with the current fuel level. This ensures that the car refuels optimally to minimize the number of stops.

**Input:**

- Total distance from A to B (d).
- Maximum distance the car can travel with a full tank (tank).
- Number of gas stations between A and B (n).
- Distances from each gas station to the starting point A.

**Output:**

The program calculates and outputs the minimum number of refills required to reach point B while avoiding running out of fuel.

**Example:**

```
Input:
500          // Total distance from A to B
200          // Maximum distance with a full tank
4            // Number of gas stations
100 200 300 400  // Distances from each gas station to A

Output:
2            // Minimum number of refills needed
```

Note: The program efficiently plans refuels to minimize stops, ensuring a successful journey from point A to point B.