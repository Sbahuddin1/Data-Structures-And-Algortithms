#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
    std::vector<int> sequence_lengths(n + 1, 0);
    sequence_lengths[1] = 0;  // Length for 1 is 0

    for (int i = 2; i <= n; ++i) {
        sequence_lengths[i] = sequence_lengths[i - 1] + 1; // Initialize with sequence ending in i - 1 and adding 1 step
        if (i % 2 == 0)
            sequence_lengths[i] = std::min(sequence_lengths[i], sequence_lengths[i / 2] + 1); // Check if dividing by 2 yields shorter sequence
        if (i % 3 == 0)
            sequence_lengths[i] = std::min(sequence_lengths[i], sequence_lengths[i / 3] + 1); // Check if dividing by 3 yields shorter sequence
    }

    vector<int> sequence;
    while (n > 1) {
        sequence.push_back(n);
        if (n % 3 == 0 && sequence_lengths[n / 3] == sequence_lengths[n] - 1)
            n /= 3;
        else if (n % 2 == 0 && sequence_lengths[n / 2] == sequence_lengths[n] - 1)
            n /= 2;
        else
            n -= 1;
    }
    sequence.push_back(1); // Add 1 at the end
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
