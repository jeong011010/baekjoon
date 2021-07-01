/*#include <iostream>
using namespace std;

int main() {
	int m, n, dp[10000];
	int sum = 0, min = 0;
	cin >> m >> n;
	for (int i = 1;i < n;i++)
		dp[i] = i * i;
	for (int i = 1;i < n;i++) {
		if (dp[i] >= m && dp[i] <= n)
		{
			if (min == 0)
				min = dp[i];
			sum += dp[i];
		}
	}
	if (min == 0)
		cout << "-1" << endl;
	else
		cout << sum << endl << min << endl;
	return 0;
}*/