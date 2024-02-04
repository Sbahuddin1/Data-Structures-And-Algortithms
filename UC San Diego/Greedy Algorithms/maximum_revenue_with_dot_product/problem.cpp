#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int max_dot_product(vector<int> a, vector<int> b) {
  int result = 0;
  // write your code here


  for (size_t i = 0; i < a.size(); i++) {
    result += ((int) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
