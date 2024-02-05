#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Segment {
    int start, end;
};

// Function to find the optimal points to cover segments
vector<int> optimal_points(int n, vector<Segment>& segments) {
    vector<int> points;

    // Sort segments based on their end points in ascending order
    sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
        return a.end < b.end;
        });

    int i = 0;
    while (i < segments.size()) {

        points.push_back(segments[i].end);

        // Move to the next segment that doesn't overlap with the current one
        int j = i + 1;
        while (j < segments.size() && segments[j].start <= segments[i].end) {
            j++;
        }

        // Update the index to the next non-overlapping segment
        i = j;
    }

    return points;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        cin >> segments[i].start >> segments[i].end;
    }  
    vector<int> points = optimal_points(n, segments);

    // Output the number of points and the points themselves
    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }

    return 0;
}
