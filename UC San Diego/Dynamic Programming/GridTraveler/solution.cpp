#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

// Function to compute the number of ways to travel in a grid
// Parameters:
//   - n: Number of rows in the grid
//   - m: Number of columns in the grid
//   - mp: Memoization table
// Returns:
//   - Number of ways to travel from top-left to bottom-right corner
size_t gridTraveler(int n, int m, unordered_map<string, double> &mp) {
    // Create a string representation of the current position
    stringstream convert;
    convert << m << ',' << n;
    string str;
    convert >> str;

    // If result for current position is computed, return it
    if (mp.count(str)) return mp[str];

    // Base cases
    if (m == 1 && n == 1) return 1;
    if (n == 0 || m == 0) return 0;

    // Compute number of ways recursively and store result
    mp[str] = gridTraveler(n - 1, m, mp) + gridTraveler(n, m - 1, mp);
    
    // Return computed result
    return mp[str];
}

int main() {
    unordered_map<string, double> mp;
    // Test cases
    cout << gridTraveler(1, 1, mp) << endl;
    cout << gridTraveler(2, 3, mp) << endl;
    cout << gridTraveler(3, 2, mp) << endl;
    cout << gridTraveler(3, 3, mp) << endl;
    cout << gridTraveler(18, 18, mp) << endl;

    return 0;
}
