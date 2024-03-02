import numpy as np

def gridTraveler(n, m, memo={}):
    # If the result for (n, m) is already computed, return it from memo
    if (n, m) in memo:
        return memo[(n, m)]
    
    # Base cases: when either n or m is 1, there's only one way to reach the end
    if n == 1 and m == 1:
        return 1
    # If either n or m is 0, there's no way to reach the end
    if n == 0 or m == 0:
        return 0
    
    # Compute the result recursively for (n-1, m) and (n, m-1)
    memo[(n, m)] = gridTraveler(n - 1, m, memo) + gridTraveler(n, m - 1, memo)
    
    # Return the computed result for (n, m)
    return memo[(n, m)]

# Example usage
print(gridTraveler(18, 18))
