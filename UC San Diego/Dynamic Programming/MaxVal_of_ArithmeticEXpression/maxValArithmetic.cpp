#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using namespace std;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    }
    else if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        assert(0);
    }
}

long long get_maximum_value(const string& exp) {
    int n = (exp.size() + 1) / 2; // Number of digits
    vector<vector<long long>> max_values(n, vector<long long>(n, 0));
    vector<vector<long long>> min_values(n, vector<long long>(n, 0));

    // Initialize the diagonal of the tables with the initial values
    for (int i = 0; i < n; ++i) {
        max_values[i][i] = exp[2 * i] - '0';
        min_values[i][i] = exp[2 * i] - '0';
    }

    // Fill the tables diagonally
    for (int s = 1; s < n; ++s) {
        for (int i = 0; i < n - s; ++i) {
            int j = i + s;
            long long min_val = LONG_MAX;
            long long max_val = LONG_MIN;
            for (int k = i; k < j; ++k) {
                long long a = eval(max_values[i][k], max_values[k + 1][j], exp[2 * k + 1]);
                long long b = eval(max_values[i][k], min_values[k + 1][j], exp[2 * k + 1]);
                long long c = eval(min_values[i][k], max_values[k + 1][j], exp[2 * k + 1]);
                long long d = eval(min_values[i][k], min_values[k + 1][j], exp[2 * k + 1]);
                min_val = min(min_val, min(a, min(b, min(c, d))));
                max_val = max(max_val, max(a, max(b, max(c, d))));
            }
            min_values[i][j] = min_val;
            max_values[i][j] = max_val;
        }
    }

    return max_values[0][n - 1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
    return 0;
}
