#include<iostream>
#include<stack>
#include<string>
using namespace std;

int arr[101][101]; //R=0, G=1, B=2
bool check[101][101];
stack<pair<int,int>> s;
int n;
int tmp;

void st() {
	if (!s.empty())
	{
		int y = s.top().first, x = s.top().second;
		if (!check[y][x]) {
			s.pop();
			check[y][x] = true;
			if (arr[y][x + 1] == tmp && x < n - 1) { s.push(make_pair(y, x + 1)); st(); }
			if (arr[y + 1][x] == tmp && y < n - 1) { s.push(make_pair(y + 1, x)); st(); }
			if (arr[y][x - 1] == tmp && x > 0) { s.push(make_pair(y, x - 1)); st(); }
			if (arr[y - 1][x] == tmp && y > 0) { s.push(make_pair(y - 1, x)); st(); }
		}
	}
	else return;
}

void f() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				tmp = arr[i][j];
				s.push(make_pair(i, j));
				st();
				cnt++;
			}
		}
	}
	cout << cnt << ' ';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) arr[i][j] = 1;
			check[i][j] = false;
		}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				tmp = arr[i][j];
				s.push(make_pair(i, j));
				st();
				cnt++;
			}
		}
	}
	cout << cnt;
}

int main() {
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'R') arr[i][j] = 0;
			else if (s[j] == 'G') arr[i][j] = 1;
			else arr[i][j] = 2;
		}
	}

	f();
}