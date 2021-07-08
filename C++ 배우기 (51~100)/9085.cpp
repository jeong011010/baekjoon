#include<iostream>
using namespace std;

int main() {
	int t, n, *sum, tmp;
	cin >> t;
	sum = new int[t];
	for (int i = 0; i < t; i++) {
		sum[i] = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			sum[i] += tmp;
		}
	}
	for (int i = 0; i < t; i++)
		cout << sum[i] << '\n';
}