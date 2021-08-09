#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, v;
stack<int> s;
queue<int> q;
vector<pair<int, int>> vec, vec2;
int arr[1001];
int arr2[1001];

void dfs() {
	while(!s.empty()) {
		int c=0;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].first == s.top()) {
				if (arr[vec[i].second] == 0) {
					arr[vec[i].second] = 1;
					s.push(vec[i].second);
					vec.erase(vec.begin() + i);
					cout << ' ' << s.top();
					c = 1;
					break;
				}
			}
			else if (vec[i].second == s.top()) {
				if (arr[vec[i].first] == 0) {
					arr[vec[i].first] = 1;
					s.push(vec[i].first);
					vec.erase(vec.begin() + i);
					cout << ' ' << s.top();
					c = 1;
					break;
				}
			}
		}
		if (c == 0) { s.pop(); }
	}
}

void bfs() {
	for (int j = 0; j < n; j++) {
		int i = 0;
		if (!q.empty()) {
			while (i < m) {
				if (vec2[i].first == q.front()) {
					if (arr2[vec2[i].second] == 0) {
						q.push(vec2[i].second);
						arr2[q.back()] = 1;
						cout << ' ' << q.back();
					}
				}
				else if (vec2[i].second == q.front()) {
					if (arr2[vec2[i].first] == 0) {
						q.push(vec2[i].first);
						arr2[q.back()] = 1;
						cout << ' ' << q.back();
					}
				}
				i++;
			}
			q.pop();
		}
	}
}

int main() {
	cin >> n >> m >> v;
	s.push(v);
	q.push(v);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		vec.push_back(make_pair(a, b));
		vec2.push_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	sort(vec2.begin(), vec2.end());
	arr[v] = 1;
	cout << v;
	dfs();
	cout << '\n';
	arr2[v] = 1;
	cout << v;
	bfs();
}