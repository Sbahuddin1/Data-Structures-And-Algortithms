#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());

    // Combine the start and end points into a single vector
    vector<std::pair<int, char>> combined_points;
    for (size_t i = 0; i < starts.size(); i++) {
        combined_points.emplace_back(starts[i], 'l');  // 'l' represents left endpoint
        combined_points.emplace_back(ends[i], 'r');    // 'r' represents right endpoint
    }

    // Combine the points to be counted into the same vector
    for (size_t i = 0; i < points.size(); i++) {
        combined_points.emplace_back(points[i], 'p');   // 'p' represents query point
    }

    // Sort the combined vector based on values
    std::sort(combined_points.begin(), combined_points.end());

    // Count segments for each point
    int open_segments = 0;
    for (const auto& point : combined_points) {
        if (point.second == 'l') {
            open_segments++;
        }
        else if (point.second == 'r') {
            open_segments--;
        }
        else {
            // 'p' represents a query point
            size_t index = std::find(points.begin(), points.end(), point.first) - points.begin();
            cnt[index] = open_segments;
        }
    }

    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        std::cin >> starts[i] >> ends[i];
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }

    vector<int> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }
}
