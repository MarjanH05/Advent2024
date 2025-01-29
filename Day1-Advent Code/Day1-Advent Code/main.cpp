#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	std::vector<int> a, b;
	for (int i = 0; i < 1000; i++) {
		int x, y;
		std::cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	int Total_Distance = 0;
	for (int x = 0; x < a.size(); x++) {
		Total_Distance += abs(a[x] - b[x]);
	}
	std::cout << Total_Distance;
}