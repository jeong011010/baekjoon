#include<iostream>
using namespace std;


int main() {
	
	int t, n, q, p;

	cin >> t;
	int *s = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> s[i] >> n;
		for (int j = 0; j < n; j++) {
			cin >> q >> p;
			s[i] += q * p;
		}
	}
	for (int i = 0; i < t; i++)
		cout << s[i] << '\n';


	return 0;
}