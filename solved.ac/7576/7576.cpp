#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int m, n;
int arr[1001][1001];
queue<tuple<int, int, int>> q;

int bfs() {
	int cnt;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) q.push(make_tuple(i, j, 0));
		}
	if (q.empty()) return -1;
	while (!q.empty()) {
		int x = get<0>(q.front()), y = get<1>(q.front());
		cnt = get<2>(q.front());
		if (x < n) if(arr[x + 1][y] == 0) { arr[x + 1][y] = 2; q.push(make_tuple(x + 1, y, cnt + 1)); }
		if (y < m) if(arr[x][y + 1] == 0) { arr[x][y + 1] = 2; q.push(make_tuple(x, y + 1, cnt + 1)); }
		if (x > 1) if(arr[x - 1][y] == 0) { arr[x - 1][y] = 2; q.push(make_tuple(x - 1, y, cnt + 1)); }
		if (y > 1) if(arr[x][y - 1] == 0) { arr[x][y - 1] = 2; q.push(make_tuple(x, y - 1, cnt + 1)); }
		q.pop();
	}/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == 0) return -1;
	}
	return cnt;
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	cout<< bfs();
}