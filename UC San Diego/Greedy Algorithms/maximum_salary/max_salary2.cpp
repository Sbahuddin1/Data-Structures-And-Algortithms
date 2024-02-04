#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Custom comparison function for concatenating strings
bool compareStrings(const string& a, const string& b) {
    return a + b > b + a;
}

string largest_number(vector<string> a) {
    sort(a.begin(), a.end(), compareStrings);

    stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
        ret << a[i];
    }

    string result;
    ret >> result;
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);

    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }

    cout << largest_number(a);
    return 0;
}