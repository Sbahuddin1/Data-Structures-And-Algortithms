#include <iostream>
#include <vector>
using namespace std;

int get_change(int money) {
	int coins = 0;
	vector<int> coinArr;
	while (money > 0) {
		if (money >= 10) {
			money -= 10;
			coinArr.push_back(10);
		}
		else if (money >= 5) {
			money -= 5;
			coinArr.push_back(5);
		}
		else {
			money -= 1;
			coinArr.push_back(1);
		}
		coins++;
	}

	cout << "[ ";
	for (int i = 0; i < coinArr.size();i++) {
	cout << coinArr[i] << ",";
	}
	cout << " ]" << endl;

	return coins;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
