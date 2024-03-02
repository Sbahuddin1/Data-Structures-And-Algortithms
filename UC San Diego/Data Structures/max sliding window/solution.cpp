#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::deque;

// Function to find maximum elements in sliding windows
void max_sliding_window_optimized(const vector<int>& A, int w) {
    deque<int> window; // Deque to store indices of elements

    // Process the first window
    for (int i = 0; i < w; ++i) {
        // Remove elements smaller than the current one from the back of the deque
        while (!window.empty() && A[i] >= A[window.back()])
            window.pop_back();
        window.push_back(i); // Add current index to the deque
    }

    // Process the rest of the windows
    for (int i = w; i < A.size(); ++i) {
        // Print the maximum element of the current window
        cout << A[window.front()] << " ";

        // Remove elements outside the current window from the front of the deque
        while (!window.empty() && window.front() <= i - w)
            window.pop_front();

        // Remove elements smaller than the current one from the back of the deque
        while (!window.empty() && A[i] >= A[window.back()])
            window.pop_back();

        window.push_back(i); // Add current index to the deque
    }

    // Print the maximum element of the last window
    cout << A[window.front()] << " ";
}

// Main function
int main() {
    int n = 0;
    cin >> n; // Input size of array

    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i]; // Input array elements

    int w = 0;
    cin >> w; // Input window size

    max_sliding_window_optimized(A, w); // Find maximum elements in sliding windows

    return 0;
}
