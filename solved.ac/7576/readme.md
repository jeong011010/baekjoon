# 백준 7576 토마토
- bfs 알고리즘을 이용하여 풀어낸 문제

## 풀이
- queue, tuple을 이용하여 2차원 배열의 bfs를 구현하여 풀어낼 수 있었다.

- 처음에 계속 틀려서 집에서 자려고 누웠는데 갑자기 한 10분동안 생각나더니 풀이가 머릿속에 그려졌다 ㅋㅋㅋㅋ
- 원래는 vector랑 arr에 확인하고 먼저 추가한 후에, 다시 for문으로 선형탐색하여 1이면 push하고 재귀호출하는 이상한 로직을 사용했다.
- 아까 누워서 생각해보니까 queue에 tuple만 있으면 문제 풀이가 가능했다.(중복 방지를 위한 배열 한개와.)

- 총 몇일 지나야 전부 다 익는지, 또는 익지 못하는 경우를 출력해주는 bfs 함수를 만들어준다.
- queue를 tuple을 이용하여 선언해준다. tuple(x,y,cnt)
- arr 배열 하나를 선언해주어 중복 탐색이 되지 않도록 해준다. (탐색한 곳은 2로, 1만 탐색하도록)

- 처음 bfs를 시작할 정점을 찾아주기 위해 2중 for문을 돌려 배열이 1인 값인 위치를 push해준다.
- 만약 익은 토마토(1)이 없다면 queue가 비어있으므로 q.empty로 확인한 후 -1를 리턴해준다.

- queue가 비어있을 때 까지 아래를 반복한다.
  - x=q.front의 첫번째 인수. y=q.front의 두번째 인수, cnt=q.front의 세번쨰 인수
  - 배열상에서 x,y 기준 상하좌우가 모서리가 아니며 0이라면 2로 만들고 queue에 현제 cnt+1를 해주어 push 한다.
  - queue를 pop 해준다.

- 이후 다시 2중 for문을 통해 2차원 배열 전체를 선형탐색한다.
- 0이 있다면 길이 막혀있는 것이므로 -1를 리턴해준다.
- 아니면 마지막 카운트인 cnt를 리턴해준다.

```C
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
```

##
- 로직을 머릿속으로 직접 상상해본 뒤에 풀면 엄청 쉽게 풀린다.
- 무작정 해당 알고리즘을 때려넣을 것이 아니라, 로직부터 구상하는 훈련이 필요하다.
