// This program Runs in time O(n)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function to find the majority element using Boyer-Moore Voting Algorithm
int get_majority_element2(vector<int>& a, int left, int right) {
    // Base cases
    if (left == right) return -1;
    if (left + 1 == right) return a[left];

    // Initialize candidate and count
    int candidate = a[left];
    int count = 1;

    // Find potential candidate using Boyer-Moore Voting Algorithm
    for (int i = left + 1; i < right; i++) {
        if (count == 0) {
            candidate = a[i];
            count = 1;
        }
        else if (a[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    // Reset count to find the actual count of the candidate
    count = 0;

    // Count the occurrences of the candidate in the given range
    for (int i = left; i < right; i++) {
        if (a[i] == candidate) {
            count++;
        }
    }

    // Calculate half the size of the range
    float size = (right - left) / 2.0;

    // If the count of the candidate is greater than half the size, it is considered the majority element
    if (count > size) {
        return 1;
    }

    // If no majority element is found, return -1
    return -1;
}

int main() {
    // Input the size of the array
    int n;
    std::cin >> n;

    // Input the elements of the array
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }

    // Check if there is a majority element and print the result
    std::cout << (get_majority_element2(a, 0, a.size()) != -1) << '\n';

    return 0;
}
