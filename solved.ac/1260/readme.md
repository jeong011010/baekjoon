
# 백준 1260 dfs bfs 문제
- dfs, bfs 탐색 algorithm 활용 문제.

* dfs와 bfs 둘다 사용해본적이 없어서 일단 검색부터 해보았다.
  * dfs(깊이 탐색) : stack 또는 재귀함수 사용
  * bfs(너비 탐색) : queue 사용
* dfs
  * stack을 이용하여 검색할 정점을 push 후, for문을 통해 vector<pair<int,int>>에서 top과 같은 부분이 있으면 쌍을 이루는 다른 점을 push. 반복.
  * 만약 없으면 pop, 그 다음 수 탐색
* bfs
  * queue를 이용하여 검색할 정점을 push 후, for문을 통해 vector<pair<int,int>>에서 front와 같은 부분이 있으면 쌍을 이루는 다른 점을 push. 반복.
  * 만약 없으면 pop, front 탐색

```C
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
		//if (a > b) swap(a, b);
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
```

  * 여러가지 반례 발생
    * https://www.acmicpc.net/board/view/43543

  * 반례 참고하여 확인한 결과 sort를 통해 정렬한 경우 (2,1) (1,3)인 경우 1,3부터 실행하여 dfs가 잘못 실행됨.

```if(a>b) swap(a,b); 추가```

dfs와 bfs algorithm을 직접 구상하며 구현해볼 수 있는 기회였다.

stack과 queue와 같은 자료구조를 이용하여 이와 같이 탐색을 구현할 수 있음이 신기했다.
