#include<iostream>
using namespace std;

bool dec(int n){
	if (n == 0 || n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;

}

int main() {
	int m, n, sum = 0, min = 0;
	cin >> m >> n;		
	for (int i = m; i <= n; i++) {
		if (dec(i)) {
			if (min == 0)
				min = i;
			sum += i;
		}
	}
	if (min != 0)
		cout << sum << '\n' << min;
	else
		cout << -1;
	return 0;
}