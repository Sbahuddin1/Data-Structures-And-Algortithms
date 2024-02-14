#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
    vector<int> table(m + 1, -1); // Initialize table with -1, representing unreachable states
    table[0] = 0; // Base case: zero coins needed to make zero change
    int nums[] = { 1, 3, 4 }; // Available coin denominations

    // Loop over amounts from 0 to m
    for (int i = 0; i < m; ++i) {
        // Loop over available coin denominations
        for (int j : nums) {
            // If using coin j would not exceed the amount
            if (i + j <= m) {
                // Calculate number of coins needed for current amount
                int combo = table[i] + 1;
                // If current combination yields fewer coins than previous known combination
                if (table[i + j] == -1 || combo < table[i + j])
                    table[i + j] = combo; // Update with new combination
            }
        }
    }
    return table[m]; // Return minimum number of coins needed for amount m
}

int main() {
    int m;
    cin >> m; // Input amount
    cout << get_change(m) << '\n'; // Output minimum number of coins needed
    return 0;
}
