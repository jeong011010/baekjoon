#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int a, b, n;

	vector<int> tmp; //vector container

	for (int i = 0;; i++) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break; n = i+1;
		tmp.push_back(a + b);
	}
	for (int i = 0;i<n; i++) {
		cout << tmp[i] << '\n';
	}
	return 0;
}