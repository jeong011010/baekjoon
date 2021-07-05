#include<iostream>
using namespace std;

long long memo[90];

//DP (dynamic programming)

/*long long fib(long long n) {
	if (n == 1 || n == 2)
		return 1;
	if (memo[n])
		return memo[n];
	memo[n] = fib(n - 1) + fib(n-2);
	return memo[n];
}*/ //top-down, memoization

long long fib(long long n) {
	memo[0] = 0;
	memo[1] = 1;
	for(int i=2;i<=n;i++)
		memo[i] = memo[i - 1] + memo[i - 2];
	return memo[n];
} //bottom-up

int main() {
	int n;
	cin >> n;

	cout << fib(n);
	return 0;
}