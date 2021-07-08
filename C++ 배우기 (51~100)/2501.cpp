#include<iostream>
using namespace std;

int solution(int n, int k) {
	for (int i = 1; i <= n; i++) {
		if ((n % i) == 0) {
			k--;
			if (k == 0) return i;
			}
		}
	return 0;
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << solution(n, k);
	return 0;
}