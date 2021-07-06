#include<iostream>
using namespace std;

long long arr[1000];

long long dp(long long n) {
	int sum;
	arr[0] = 0;
	arr[1] = 3;
	for (int i = 2; i <= n; i++) {
		sum = 0;
		for (int j = i; j <= i * 2; j++)
			sum += j;
		arr[i] = arr[i - 1] + sum;
	}
	return arr[n];
}

int main() {
	int n;
	cin >> n;
	cout<<dp(n);
}