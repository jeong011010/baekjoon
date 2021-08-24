# 백준 2178 미로 탐색
- bfs 알고리즘을 이용하여 풀어낸 문제

## 풀이
- 미로 탐색 문제는 bfs&dfs로 풀어낼 수 있다.
  - 위 문제는 미로의 경로를 탐색하여 가장 짧은 경로를 알아내야 하는 문제이므로 dfs는 적절하지 않다.
- bfs를 이용하여 queue를 사용해 문제를 풀 수 있다.
- 우선 배열을 선언하여 해당 좌표로 갈 수 있는지 없는지 (막혀있거나 이미 방문했던 곳) 확인할 수 있도록 해준다.
- queue에 행, 열, cnt를 넣을 수 있도록 tuple 헤더를 선언해준 뒤, queue를 선언해준다.
- maze에 벽과 길을 저장해준 뒤, bfs() 함수를 호출한다.

```C
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m;
int maze[101][101];
queue<tuple<int,int,int>> q;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			maze[i][j] = s[j-1]-48;
	}

	q.push(make_tuple(1, 1, 1));
	maze[1][1] = 2;

	cout << bfs();
}
```

- bfs() 함수를 선언해준다.
  - queue의 front 첫번쨰 인수와 두번째 인수를 도착지점과 비교하여 다르면 아래 while문을 반복
    - 해당 q를 pop 해준 뒤 상하좌우에 길이 있는지 확인해준다.
    - 길이 있다면 해당 좌표와 cnt+1를 push 해준다.
    - 만약 pop한 이후의 queue의 front가 도착지점과 같다면 return 해준다.
    - x와 y, cnt를 현제 queue의 front로 초기화 해준다.

```C
int bfs() {
	int x = 1, y = 1, cnt = 1;
	while ((x != n && y != m) || !q.empty()) {
		q.pop();
		if (maze[x][y + 1] == 1) { q.push(make_tuple(x, y + 1, cnt + 1)); maze[x][y + 1] = 2; }
		if (maze[x + 1][y] == 1) { q.push(make_tuple(x + 1, y, cnt + 1)); maze[x + 1][y] = 2; }
		if (maze[x][y - 1] == 1) { q.push(make_tuple(x, y - 1, cnt + 1)); maze[x][y - 1] = 2; }
		if (maze[x - 1][y] == 1) { q.push(make_tuple(x - 1, y, cnt + 1)); maze[x - 1][y] = 2; }
		if (get<0>(q.front()) == n && get<1>(q.front()) == m) { return get<2>(q.front()); }
		x = get<0>(q.front()), y = get<1>(q.front()), cnt = get<2>(q.front());
	}
}
```

##
- 초반부터 엄청 해매었던 문제다.
- 다음날 자고 일어나서 함수 싹 지우고 다시 푸니까 굉장히 쉬운 문제였다.
- 2차원 좌표와 cnt를 pair에 담으려고 했던 나 자신을 원망한다. tuple을 이용하도록 하자
