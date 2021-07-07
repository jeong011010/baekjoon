#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n-i-1; j > 0; j--) {
			cout << ' ';
		}
		for (int j = 0; j < (i + 1)*2-1; j++) {
			cout << (j % 2 == 0 ? '*' : ' ');
		}
		cout << '\n';
	}
	return 0;
}