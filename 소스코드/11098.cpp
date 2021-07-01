/*#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, p, c=0, tmp_c;
	string name[100], tmp_n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> p;
		for (int j = 0;j < p;j++) {
			cin >> tmp_c >> tmp_n;
			if (c < tmp_c) {
				c = tmp_c;
				name[i] = tmp_n;
			}
		}
		c = 0;
	}
	for (int i = 0;i < n;i++)
		cout << name[i] << endl;
	return 0;
}*/