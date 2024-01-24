#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the maximum dot product of two arrays after sorting them
unsigned long long max_dot_product(vector<int> a, vector<int> b) {

    unsigned long long result = 0;

    // Sort array 'a' in ascending order
    sort(a.begin(), a.end());

    // Sort array 'b' in ascending order
    sort(b.begin(), b.end());

    // Calculate the dot product of the sorted arrays
    for (size_t i = 0; i < a.size(); i++) {
        result += ((unsigned long long)a[i]) * b[i];
    }

    return result;
}

int main() {
    size_t n;

    // Input the size of the arrays
    std::cin >> n;

    // Input the elements of array 'a'
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Input the elements of array 'b'
    vector<int> b(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    // Output the maximum dot product of the arrays
    std::cout << max_dot_product(a, b) << std::endl;

    return 0;
}
