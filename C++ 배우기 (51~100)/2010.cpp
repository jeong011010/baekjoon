#include<iostream>
using namespace std;


int main() {
	int n,j,sum=1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> j;
		sum += j;
	}
	cout<<sum-n;
	return 0;
}