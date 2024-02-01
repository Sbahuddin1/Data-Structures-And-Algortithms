#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

// Partition function for Randomized QuickSort
int partition2(vector<int>& a, int l, int r) {
    // Choose the pivot as the first element of the array
    int pivot = a[l];
    // Count of elements smaller than or equal to the pivot
    int count = 0;

    // Count elements smaller than or equal to the pivot
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= pivot) {
            count++;
        }
    }

    // Calculate the correct position of the pivot
    int correctPivotIndex = l + count;
    // Swap the pivot to its correct position
    swap(a[correctPivotIndex], a[l]);

    // Two-pointer approach to partition the remaining elements
    int i = l, j = r;
    while (i < correctPivotIndex && j > correctPivotIndex) {
        // Move i to find an element greater than the pivot
        while (a[i] <= pivot) {
            i++;
        }
        // Move j to find an element smaller than or equal to the pivot
        while (a[j] > pivot) {
            j--;
        }

        // Swap elements to maintain the partition
        if (i < correctPivotIndex && j > correctPivotIndex) {
            swap(a[i++], a[j--]);
        }
    }

    // Return the correct position of the pivot
    return correctPivotIndex;
}

// Randomized QuickSort function
void randomized_quick_sort(vector<int>& a, int l, int r) {
    // Base case: If the subarray has one element or is empty, it is already sorted
    if (l >= r) {
        return;
    }

    // Partition the array and get the correct position of the pivot
    int m = partition2(a, l, r);

    // Recursively sort the subarrays before and after the pivot
    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);
}

int main() {
    // Input: Number of elements in the array
    int n;
    std::cin >> n;

    // Input: Array of integers
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }

    // Sort the array using Randomized QuickSort
    randomized_quick_sort(a, 0, a.size() - 1);

    // Output: Sorted array
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }

    return 0;
}
