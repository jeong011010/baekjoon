#include<iostream>
using namespace std;

int main() {
	int n, x, tmp, count = 0;
	cin >> n >> x;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp < x)
			arr[count++]=tmp;
	}
	for (int i = 0; i < count; i++) {
		cout << arr[i] << ' ';
	}
}