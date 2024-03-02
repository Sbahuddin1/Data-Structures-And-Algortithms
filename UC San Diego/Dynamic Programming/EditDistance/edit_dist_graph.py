'''
This program gives the extensive graph for the edit distance instead of just the distance,
it can give you a better understanding of how things actually work
'''

def edit_distance(str1, str2):
    m = len(str1)
    n = len(str2)

    # Create a 2D table to store results of subproblems
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # Fill dp[][] in bottom-up manner
    for i in range(m + 1):
        for j in range(n + 1):
            # Fill first row with numbers 1 to m
            if i == 0:
                dp[i][j] = j
            # Fill first column with numbers 1 to n
            elif j == 0:
                dp[i][j] = i

            # If last characters are same, ignore last char
            # and recur for remaining string
            elif str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            # If last character are different, consider all
            # possibilities and find minimum
            else:
                dp[i][j] = 1 + min(dp[i][j - 1],      # Insert
                                  dp[i - 1][j],      # Remove
                                  dp[i - 1][j - 1])  # Replace

    return dp

# Main function
if __name__ == "__main__":
    str1 = input("Enter the first string: ")
    str2 = input("Enter the second string: ")
    print("Edit distance graph for", str1, "and", str2, "is:", edit_distance(str1, str2))
