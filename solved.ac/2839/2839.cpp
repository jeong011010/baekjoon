#include<iostream>
using namespace std;

int main() {
	int n, m, sum, tmp;
	cin >> n;
	m = n / 5;
	while (m >= 0) {
		sum = m;
		tmp = n - m * 5;
		if (tmp % 3 == 0) {
			sum += tmp / 3;
			tmp = 0;
			break;
		}
		else m--;
	}
	if (tmp != 0)cout << -1;
	else cout << sum;
}