#include<iostream>

using namespace std;

int main() {
	int t, h, w, n;
	cin >> t;
	for (int testcase=0; testcase < t; testcase++) {
		int num=1;
		cin >> h >> w >> n;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++,num++) {
				if (num == n) {
					cout << j+1 <<' ';
					if (i < 9)cout << '0' << i+1;
					else cout << i+1;
					cout << '\n';
				}
			}
		}
	}
	return 0;
}