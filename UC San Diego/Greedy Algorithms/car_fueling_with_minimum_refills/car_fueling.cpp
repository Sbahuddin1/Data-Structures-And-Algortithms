#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int n, int tank, vector<int>& stops) {
    int refills = 0, current = 0, last = 0;

    while (current < (n - 1)) {
        last = current;
        while (current < (n - 1)) {
            if ((stops[current + 1] - stops[last]) <= tank)
                current ++;
            else
                break;
        }

        if (current == last)
            return -1;

        if (current < (n - 1)) {
            refills++;
        }
    }
    return refills;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    
    vector<int> stops(n+2);
    stops[n+1] = d;
    stops[0] = 0;

    for (int i = 1; i <= n; i++)
        cin >> stops.at(i);

    cout << compute_min_refills(n+2, m, stops) << "\n";
    return 0;
}

