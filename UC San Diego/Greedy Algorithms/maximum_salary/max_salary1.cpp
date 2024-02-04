#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Function to find the largest number by sorting strings
string largest_number(vector<string> a) {
    int n = a.size();  // Number of elements in the vector
    bool swapped;

    // Bubble sort to arrange strings in a way that results in the largest concatenated number
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            // Compare pairs of strings to determine the correct order for the largest number
            if (a[j] + a[j + 1] < a[j + 1] + a[j]) {
                swap(a[j], a[j + 1]);  // Swap if the concatenation of a[j] + a[j + 1] is lexicographically smaller
                swapped = true;
            }
        }
        if (swapped == false)
            break;  // If no swaps occurred, the array is already sorted
    }

    // Concatenate the sorted strings to form the largest number
    stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
        ret << a[i];
    }

    string result;
    ret >> result;  // Extract the result from the stringstream

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);  
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    // Output the largest number formed by the given strings
    cout << largest_number(a);
    return 0;
}
