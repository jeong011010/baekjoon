#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int arr[10] = { 0 };
int inf = 1000007;
int n, m, i, click_num = 0, click = 0;

int min(int a, int b) {
	return a < b ? a : b;
}

bool possible(int k) {
	if (k == 0)
		return arr[0] ? false : true;
	while (k) {
		if (arr[k % 10] == 1)
			return false;
		k /= 10;
	}
	return true;
}

int check(int n) {
	int hun = abs(n - 100);
	int button_min = inf;
	int tmp;
	for (int i = 0; i <= inf; i++) {
		if (possible(i)) {
			tmp = to_string(i).length();
			tmp += abs(i - n);
			button_min = min(button_min, tmp);
		}
	}
	return min(hun, button_min);
}

int main() {
	int n, m, tmp;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		arr[tmp] = 1;
	}
	cout << check(n) << '\n';
	return 0;

}