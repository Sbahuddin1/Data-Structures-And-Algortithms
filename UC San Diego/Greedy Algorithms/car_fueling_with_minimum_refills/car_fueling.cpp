#include <iostream>
#include <vector>
using namespace std;

// Function to compute the minimum refills needed to reach the destination
int compute_min_refills(int n, int tank, vector<int>& stops) {
    int refills = 0, current = 0, last = 0;

    // Loop until the destination is reached
    while (current < (n - 1)) {
        last = current;

        // Move to the next reachable stop
        while (current < (n - 1)) {
            if ((stops[current + 1] - stops[last]) <= tank)
                current++;
            else
                break;
        }

        // If no progress is made, it means the destination is unreachable
        if (current == last)
            return -1;

        // If not at the last stop, increment refills count
        if (current < (n - 1)) {
            refills++;
        }
    }
    return refills;
}

int main() {
    // Input the total distance, tank capacity, and number of stops
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    
    // Initialize a vector to store the distances of stops
    vector<int> stops(n+2);

    // Set the initial and final stops
    stops[n+1] = d;
    stops[0] = 0;

    // Input the distances of intermediate stops
    for (int i = 1; i <= n; i++)
        cin >> stops.at(i);

    // Output the minimum refills needed
    cout << compute_min_refills(n+2, m, stops) << "\n";
    return 0;
}
