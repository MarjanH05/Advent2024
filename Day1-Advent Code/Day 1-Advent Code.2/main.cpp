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
	int Similarity_Score = 0;

	for (int x = 0; x < a.size(); x++) {
		int count = 0;
		count = std::count(b.begin(), b.end(), a[x]);
		Similarity_Score += a[x] * count;
	}

	std::cout << Similarity_Score;
}