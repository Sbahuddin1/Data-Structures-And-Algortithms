// This program Runs in time O(n^2)

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Function to find the majority element using a map for counting occurrences
int get_majority_element(vector<int>& a, int left, int right) {
    // If the range has no elements, return -1
    if (left == right) return -1;
    // If the range has only one element, return that element
    if (left + 1 == right) return a[left];

    // Create a map to store element counts, initialize with a dummy entry
    map<int, int> mp;
    mp[-1] = -1;

    // Calculate half the size of the range
    float size = (a.size()) / 2.0;

    // Iterate through the elements in the given range
    for (int i = left; i < right; i++) {
        // Iterate through the entries in the map
        for (auto& j : mp) {
            // Check if the element is already in the map
            if (j.first == a[i]) {
                // If yes, increment its count
                j.second += 1;
                // Check if the count is greater than half the size, indicating a majority candidate
                if (j.second > size) {
                    return 1;
                }
            }
            else {
                // If the element is not in the map, insert it with a count of 0
                mp.insert({ a[i], 0 });
            }
        }
    }

    // If no majority candidate is found, return -1
    return -1;
}

// Main function for user input and output
int main() {
    // Input the size of the array
    int n;
    cin >> n;

    // Input the elements of the array
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }

    // Check if there is a majority element and print the result
    cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';

    return 0;
}
