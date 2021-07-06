#include<iostream>
using namespace std;


int main() {
	int n,i,j;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < i + 1; j++)
			cout << '*';
		for (j = i*2; j < (n-1) * 2; j++)
			cout << ' ';
		for (j = 0; j < i + 1; j++)
			cout << '*';
		cout << '\n';
	}
	for (i = n-1; i > 0; i--) {
		for (j = 0; j < i; j++)
			cout << '*';
		for (j = i * 2; j < (n ) * 2; j++)
			cout << ' ';
		for (j = 0; j < i; j++)
			cout << '*';
		cout << '\n';
	}
	return 0;
}