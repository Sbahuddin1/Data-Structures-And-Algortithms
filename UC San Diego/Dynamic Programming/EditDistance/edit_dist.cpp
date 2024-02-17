#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill dp[][] in bottom-up manner
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            //fill first row with numbers 1 to m
            if (i == 0)
                dp[i][j] = j;
            //fill first colum with numbers 1 to n
            else if (j == 0)
                dp[i][j] = i;

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min({ dp[i][j - 1],        // Insert
                                    dp[i - 1][j],        // Remove
                                    dp[i - 1][j - 1] }); // Replace
        }
    }

    return dp[m][n];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}