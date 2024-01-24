#include <iostream>
#include <vector>
using namespace std;

// Function to compute the minimum refills needed to reach the destination
int compute_min_refills(int distance, int tank, vector<int>& stops) {
    int refills = 0;
    int covered = 0;
    int n = stops.size();
    int i = 0;
    int total_tank = tank;

    // Loop until the destination is covered or until we iterate over all stops
    while (covered < distance && i < n + 1) {

        // For the first stop
        if (i == 0) {
            tank = tank - stops[0];
            covered = stops[0];
            
            // If the tank becomes empty, refuel and reset the tank
            if (tank <= 0) {
                refills++;
                tank = total_tank;
            }
        }

        // For intermediate stops
        if (i > 0 && i < n + 1) {
            // If the remaining tank capacity is not enough to reach the next stop
            if (tank - (stops[i] - stops[i - 1]) < 0) {
                refills++;
                tank = total_tank;
            }
            // Update tank capacity and covered distance
            tank = tank - (stops[i] - covered);
            covered = stops[i];
        }

        // Check conditions for unreachable destination or next stop
        if (i < n - 1) {
            if (distance - stops[n - 1] > total_tank || stops[i + 1] - stops[i] > total_tank || stops[0] > total_tank) {
                return -1;
            }
        }
        i++;
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
    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;
}
