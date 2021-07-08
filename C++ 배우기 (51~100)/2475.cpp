#include<iostream>
using namespace std;

int main() {
	int n, tmp=0;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		tmp += n * n;
	}

	cout << tmp%10;
	return 0;
}