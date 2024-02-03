#include <iostream>
#include <vector>

using std::vector;

// Function to calculate optimal summands for a given total
vector<int> optimal_summands(int n) {
    vector<int> summands;
    int i = 1;

    // Greedy algorithm to find optimal summands
    while (i <= n) {
        if (n >= i) {
            n = n - i;
            summands.push_back(i);
        }
        if (n < i) {
            break;
        }
        i++;
    }

    // Adjust the last summand to include the remaining value
    summands[summands.size() - 1] += n;

    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n'; 

    // Output each summand
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }

    return 0;
}
