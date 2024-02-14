def canSum(m):
    table = [None] * (m + 1)
    table[0] = 0
    numbers = [1, 3, 4]

    for i in range(m):
        for j in numbers:
            if (i + j) <= m:
                combo = table[i] + 1
                if  table[i + j] is None or combo < table[i + j]:
                    table[i + j] = combo

    return table[m]


m = int(input())
print(canSum(m))
