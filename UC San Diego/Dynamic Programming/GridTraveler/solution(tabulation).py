import numpy as np

def gridTraveler(n,m):
    grid = np.zeros((m+1, n+1))    

    for i in range(1,m+1):
        for j in range(1,n+1):
            if grid[1][1] != 1 : grid[1][1] = 1
            grid[i][j] = grid[i-1][j] + grid[i][j-1]
                  
    return grid[n][m]
    
print(gridTraveler(18,18))