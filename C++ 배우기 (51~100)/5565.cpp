#include<iostream>
using namespace std;

int main() {
	int sum=0, price[10];

	cin >> price[0];
	for (int i = 1; i < 10; i++) {
		cin >> price[i];
		sum += price[i];
	}
	cout << price[0] - sum;
	return 0;
}