#include<iostream>
#include<queue>
using namespace std;

int n, k;
bool check[100001];

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	check[n] = true;
	while (!q.empty()) {
		int loc = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (loc == k) {
			return cost;
		}
		if (loc - 1 >= 0 &&!check[loc - 1]) {
			q.push(make_pair(loc - 1, cost + 1));
			check[loc - 1] = true;
		}
		if (loc + 1 < 100001 && !check[loc + 1]) {
			q.push(make_pair(loc + 1, cost + 1));
			check[loc + 1] = true;
		}
		if (loc * 2 < 100001 && !check[loc * 2]) {
			q.push(make_pair(loc * 2, cost + 1));
			check[loc * 2] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	cout << bfs();
}