#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int binary_search(const vector<int>& a, int x) {
    int left = 0, right = (int)a.size();
    int lm = INT_MAX;
    while (right >= left) {
        int middle = floor((left + right) / 2);
        if (a[middle] == x) {
            if (lm > middle) {
                lm = middle;
            }
        }
        if (a[middle] >= x) {
            right = middle - 1;
        }
        if (a[middle] < x)
            left = middle + 1;
    }
    if (lm != INT_MAX) {
        return lm;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < b.size(); ++i) {
        std::cin >> b[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
