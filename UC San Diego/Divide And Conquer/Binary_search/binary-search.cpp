#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

 long long binary_search(vector<long long>& a, long long x) {
    long long left = 0, right = (long long)a.size() - 1;

    while (right >= left) {
        long long middle = floor((left + right) / 2);
        if (a[middle] == x) {
            return middle;
        }
        else if (a[middle] > x) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<long long> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<long long> b(m);
    for (int i = 0; i < b.size(); ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
