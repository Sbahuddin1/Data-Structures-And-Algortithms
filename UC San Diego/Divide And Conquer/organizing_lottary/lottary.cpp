#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());

    // Sort the starts and ends
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    for (size_t i = 0; i < points.size(); ++i) {
        int point = points[i];
        // Count the number of starts that are less than or equal to the point
        // Subtract the number of ends that are less than the point
        // The difference represents the number of segments containing the point
        cnt[i] = upper_bound(starts.begin(), starts.end(), point) - starts.begin();
        cnt[i] -= lower_bound(ends.begin(), ends.end(), point) - ends.begin();
    }

    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        cin >> starts[i] >> ends[i];
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        cin >> points[i];
    }

    vector<int> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        cout << cnt[i] << ' ';
    }

    return 0;
}
