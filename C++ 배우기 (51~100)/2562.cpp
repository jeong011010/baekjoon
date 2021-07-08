#include<iostream>
using namespace std;

int main() {
	int tmp, max, n=1;
	cin >> max;
	for (int i = 2; i < 10; i++) {
		cin >> tmp;
		if (tmp > max) {
			n = i;
			max = tmp;
		}
	}

	cout << max<<'\n'<<n;
	return 0;
}