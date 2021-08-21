#include<iostream>
using namespace std;

int stair[301];
int arr[301];

int max(int a, int b) { return a > b ? a : b; }

int dp(int end) {
	arr[1] = stair[1];
	arr[2] = arr[1] + stair[2];

	for (int i = 3; i <= end; i++) {
		arr[i] = max(arr[i - 2] + stair[i] , arr[i - 3] + stair[i - 1] + stair[i]);
		cout << arr[i]<<' ';
 	}

	return arr[end];
}

int main() {
	int n, tmp;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	cout<<dp(n);

}