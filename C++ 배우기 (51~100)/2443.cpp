#include<iostream>
using namespace std;

int main() {
	int n,j;
	cin >> n;
	for (int i = n; i > 0; i--) {
		for (j = n; j > i; j--)
			cout << ' ';
		for (j = (i) * 2; j > 1; j--)
			cout << '*';
		cout << '\n';
	}
	return 0;
}