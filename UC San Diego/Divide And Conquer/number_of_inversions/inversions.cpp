#include <iostream>
#include <vector>

using std::vector;

// Merge function to merge two sorted halves and count inversions
long long merge(vector<int>& a, vector<int>& b, size_t left, size_t ave, size_t right) {
    long long number_of_inversions = 0;

    size_t i = left, j = ave, k = left;

    // Merge the two sorted halves into the auxiliary array 'b'
    while (i < ave && j < right) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        }
        else {
            // If the element from the right subarray is smaller,
            // copy it to 'b' and count inversions
            b[k++] = a[j++];

            // Count inversions for each element in the left subarray
            // that is greater than the current element from the right
            number_of_inversions += ave - i;
        }
    }

    // Copy any remaining elements from the left subarray
    while (i < ave) {
        b[k++] = a[i++];
    }

    // Copy any remaining elements from the right subarray
    while (j < right) {
        b[k++] = a[j++];
    }

    // Copy the merged result back to the original array 'a'
    for (i = left; i < right; i++) {
        a[i] = b[i];
    }

    return number_of_inversions;
}

// Recursive function to split, sort, and count inversions
long long get_number_of_inversions(vector<int>& a, vector<int>& b, size_t left, size_t right) {
    long long number_of_inversions = 0;

    // Base case: If the subarray has one or zero elements, it's already sorted
    if (right <= left + 1) return number_of_inversions;

    // Calculate the midpoint of the subarray
    size_t ave = left + (right - left) / 2;

    // Recursively count inversions in the left and right halves
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);

    // Merge the sorted halves and count inversions during the merge
    number_of_inversions += merge(a, b, left, ave, right);

    return number_of_inversions;
}

int main() {
    int n;
    std::cin >> n;

    // Input sequence of integers
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }

    // Auxiliary array for merging
    vector<int> b(a.size());

    // Output the number of inversions
    std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';

    return 0;
}
