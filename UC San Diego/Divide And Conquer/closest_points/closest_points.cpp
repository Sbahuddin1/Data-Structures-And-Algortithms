#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

// Define a structure to represent a point with x and y coordinates
struct Point {
    int x, y;
};

// Comparator function to sort points based on their x-coordinate
bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

// Comparator function to sort points based on their y-coordinate
bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

// Function to calculate the Euclidean distance between two points
double euclideanDistance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find the closest distance between points in the strip
double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;

    // Sort points in the strip based on their y-coordinate
    sort(strip.begin(), strip.end(), compareY);

    // Iterate through each point in the strip to find the closest pair
    for (size_t i = 0; i < strip.size(); ++i) {
        // Compare each point with the next points within the distance 'd'
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            // Update 'minDist' if a closer pair is found
            minDist = min(minDist, euclideanDistance(strip[i], strip[j]));
        }
    }

    return minDist;
}

// Recursive function to find the closest pair of points in a given range
double closestUtil(vector<Point>& points, size_t start, size_t end) {
    // Base case: If the number of points is small, calculate distance directly
    if (end - start <= 3) {
        double minDist = numeric_limits<double>::max();
        // Iterate through each pair of points to find the closest pair
        for (size_t i = start; i < end; ++i) {
            for (size_t j = i + 1; j < end; ++j) {
                minDist = min(minDist, euclideanDistance(points[i], points[j]));
            }
        }
        return minDist;
    }

    // Divide the points into two halves and recursively find the closest distances
    size_t mid = (start + end) / 2;
    Point midPoint = points[mid];

    double dl = closestUtil(points, start, mid);
    double dr = closestUtil(points, mid, end);

    // Find the minimum distance among the left and right halves
    double d = min(dl, dr);

    // Create a strip of points within 'd' distance from the midPoint along x-axis
    vector<Point> strip;
    for (size_t i = start; i < end; ++i) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    // Find the closest pair of points in the strip and update 'd' if necessary
    return min(d, stripClosest(strip, d));
}

// Function to find the minimal distance between points
double minimal_distance(vector<int> x, vector<int> y) {
    // Create a vector of points from the given x and y coordinates
    vector<Point> points(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        points[i] = { x[i], y[i] };
    }

    // Sort the points based on their x-coordinate
    sort(points.begin(), points.end(), compareX);

    // Call the closestUtil function to find the minimal distance
    return closestUtil(points, 0, points.size());
}

int main() {
    // Read the number of points
    size_t n;
    cin >> n;
    // Read the x and y coordinates of each point
    vector<int> x(n);
    vector<int> y(n);
    for (size_t i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    // Output the minimal distance with 9 decimal places precision
    cout << fixed;
    cout << setprecision(9) << minimal_distance(x, y) << "\n";
    return 0;
}
