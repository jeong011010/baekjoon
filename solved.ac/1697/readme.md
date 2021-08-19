
# 백준 1697 숨바꼭질
- bfs(breadth first search) 응용 프로그램

## 풀이
- queue를 이용해 bfs를 구현.
- 현재 위치 n에서 k를 찾을 떄 까지 n-1, n+1, nx2로 너비 우선 탐색
- queue에 pair를 사용하여 위치와 몇번 갔는지 cost push.
- +1, -1, x2 할떄마다 cost++ 해주기.
- 이미 갔던곳은 체크하지 않기 위해 check[100001] bool형 배열 만들어 체크해주기

```C
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
```

##
- bfs를 구현하며 문제에 맞게 맞추는 연습이 필요하다.

