#include <iostream>
#include <vector>
#include <string>

typedef unsigned long long number;

void solve(number N, number K, number& MaxS, number& MinS) {
	if (K == 1) {
		MaxS = N / 2;
		MinS = (N - 1) / 2;
	}
	else {
		if (K % 2) { // K odd
			solve((N - 1) / 2, K / 2, MaxS, MinS);
		}
		else {
			solve(N / 2, K / 2, MaxS, MinS);
		}
	}
}

int main() {

	int t;
	std::cin >> t;

	for (auto int i = 1; i <= t; i++) {

		number N, K;
		std::cin >> N >> K;

		number maxS, minS;
		solve(N, K, maxS, minS);

		std::cout << "Case #" << i << ": " << maxS << " " << minS << "\n";
	}

	return 0;

}
