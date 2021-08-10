#include<iostream>
using namespace std;

int k, n, maximum=0;
long long len_line[10000];
int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> k >> n;
	int t=0;
	for (int i = 1; i <= k; i++) {
		cin >> len_line[i];
	}
	long long left = 0;
	long long right = 2147483647;
	while (left<=right) {
		long long mid = (left + right) / 2;
		int sum = 0;
		for (int i = 1; i <= k; i++) {
			sum+=len_line[i] / mid;
		}
		if (sum >= n) { left = mid + 1; maximum = max(maximum, mid); }
		else { right = mid - 1;}
	}
	cout << maximum;
}