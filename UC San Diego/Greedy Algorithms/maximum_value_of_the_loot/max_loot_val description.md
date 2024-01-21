# Problem Description: Fractional Knapsack Problem for a Spice Shop

In a spice shop, there are various items of spices available, each with its own weight and value. The shopkeeper wants to maximize the total value of spices they can take, given a limited capacity (in terms of weight) of their knapsack. However, the shopkeeper has the flexibility to take fractional parts of the spices, i.e., they can take a fraction of a spice item if it maximizes the total value.

The goal is to determine the optimal selection of spices to maximize the total value within the given capacity constraint. The spices have different values and weights, and the shopkeeper aims to prioritize items with higher value-to-weight ratios, as they contribute more to the total value relative to their weight.

## Key Components:

1. **Input:**
   - The number of spice items available (`n`).
   - The maximum capacity of the knapsack (`capacity`).
   - For each spice item:
     - Value of the spice (`values[i]`).
     - Weight of the spice (`weights[i]`).

2. **Algorithm:**
   - The algorithm uses a greedy approach, iterating through each spice item and selecting the one with the highest value-to-weight ratio at each step. This ensures that the shopkeeper prioritizes spices that contribute the most value relative to their weight.

3. **Fractional Selection:**
   - The algorithm allows the shopkeeper to take fractional parts of spice items, optimizing the total value within the capacity constraint.

4. **Output:**
   - The algorithm calculates and returns the maximum total value that the shopkeeper can obtain by selecting spices for their knapsack.

### Example:

Consider the following input:

```
3 50
60 20
100 50
120 30
```

- There are three spice items available.
- The knapsack capacity is 50.
- Spice 1: Value = 60, Weight = 20
- Spice 2: Value = 100, Weight = 50
- Spice 3: Value = 120, Weight = 30

The algorithm optimally selects Spice 3 (the highest value-to-weight ratio) and then takes a fraction of Spice 2 to fill the knapsack to its full capacity. The output would be the total value obtained, considering the fractional selection.

### Output:

```
240
```

This represents the maximum total value that the shopkeeper can obtain by selecting and fractionally filling the knapsack with the available spice items.