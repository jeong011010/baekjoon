#include<iostream>
using namespace std;

int a=0, b=0, c=0;
int paper[2187][2187];

void dac(int size, int x, int y) {
	int tmp = paper[x][y];
	bool check = false;
	for (int i = x; i < size + x; i++) {
		for (int j = y; j < size + y; j++) {
			if (tmp != paper[i][j]) {
				check = true;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						dac(size / 3, k * size / 3 + x, l * size / 3 + y);
					}
				}
				goto a;
			}
		}
	}
	a:
	if (check == false) {
		if (tmp == -1) a++;
		else if (tmp == 0) b++;
		else if (tmp == 1) c++;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	dac(n, 0, 0);
	cout << a << '\n' << b << '\n' << c;
}