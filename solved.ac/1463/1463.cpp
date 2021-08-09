#include<iostream>
using namespace std;

int DP[1000001];

int main() {
	int x;
	cin >> x;
	for (int i = 2; i <= x; ++i) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0)DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0)DP[i] = min(DP[i], DP[i / 3] + 1);
	}
	cout << DP[x] << '\n';
	return 0;
}