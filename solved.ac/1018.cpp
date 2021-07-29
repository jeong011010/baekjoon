#include<iostream>
using namespace std;

int wb[8][8] = {
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'} };

int bw[8][8] = {
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'} };

int main() {
	int n, m, max=100000;
	string s;
	cin >> n >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}

	for (int count_x = 0; count_x < (n - 7); count_x++) {
		for (int count_y = 0; count_y < (m - 7); count_y++) {

			int count_wb = 0, count_bw = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (arr[i + count_x][j + count_y] != wb[i][j])
						count_wb++;
					else if (arr[i + count_x][j + count_y] != bw[i][j])
						count_bw++;
				}
			}

			int tmp = (count_wb < count_bw ? count_wb : count_bw);
			max = (max < tmp ? max : tmp);
		}
	}
	cout << max;
	return 0;
}