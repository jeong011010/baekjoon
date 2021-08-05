#include<iostream>
using namespace std;

int arr[50][50];
int n, m, st, sum;

void check(int x, int y) {
	arr[x][y] = 2;
	if (x > 0)
		if (arr[x - 1][y] == 1)
			check(x - 1, y);
	if (x < n)
		if (arr[x + 1][y] == 1)
			check(x + 1, y);
	if (y > 0)
		if (arr[x][y - 1] == 1)
			check(x, y - 1);
	if (y < m)
		if (arr[x][y + 1] == 1)
			check(x, y + 1);
}

int main() {
	int t, k, x, y;
	cin >> t;
	for (int testcase = 0; testcase < t; testcase++) {
		sum = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = 0;

		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				st= 0;
				if (arr[i][j] == 1) {
					check(i, j);
					sum++;
				}
			}

		cout << sum << '\n';
	}
}