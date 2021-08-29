# 백준 11724 연결 요소의 개수
- dfs, bfs 활용 문제

## 풀이
- 각 정점과 노선이 주어졌을 때, 총 노선이 몇개인지 출력하는 문제이다.
- dfs 함수를 구현하여 dfs가 끝날때 마다 cnt++를 하는 식으로 구상했다.
- 늘 하던대로 stack<pair<int,int>>를 하여 u,v를 대입하는 식으로 구현했지만 시간복잡도가 너무 길었다.
- 하루동안 못풀다가 인터넷의 도움을 받아 새롭고 간단한 dfs 함수 방법을 알아냈다.

```C
vector<int> vec[1001];
bool arr[1001];

void dfs(int n) {
	arr[n] = true;
	for (int i = 0; i < vec[n].size(); i++) {
		int next = vec[n][i];
		if (!arr[next]) {
			dfs(next);
		}
	}
}
```

- 원래는 vector<pair<int,int>>로 내가 처음 dfs를 구현할 때 직접 구상해 사용한 방식을 계속 사용해왔지만, 이 코드를 사용해본 후 다시 보니 정말 비효율적이다.
- 위 코드는 vector를 배열 형식으로 선언 후, bool 배열에 해당 정점을 방문했는지 확인하도록 한다.
- 이후 방문하지 않았다면, 해당 vector에 들어가있는, 즉 연결되어 있는 다른 정점을 재귀함수의 인수로 호출한다.
- 이렇게하면 stack도 사용할 필요 없는 아주 간단한 dfs 함수가 완성이 된다.
- 항상 vector<pair<int,int>>로 받았던 나는 dfs 함수에서도 
- ```Cif(vector[n].first == i) else if(vector[n].second == i)```
- 이런식으로 사용해 매우 불편했었는데 위 코드는 vector를 배열로 선언하고 main 함수에서
- ```Cvec[u].push_back(v), vec[v].push_back(u)```
- 를 하여 해당 정점의 vector의 배열에 이어진 정점을 전부 넣는 방식인 것이다.(물론 방향이 없는 그래프에 한해서이다.)

```C
cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int cnt=0;
	for (int i = 1; i <= n; i++) {
		if (!arr[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
```

- 이후 메인 함수를 위와 같이 작성해주면 끝났다.

##
- 항상 그래프 탐색 문제를 풀 때, 구현이 너무 힘들고 코드가 길기도 해서 귀찮았는데
- 이번에 새로운 방식을 알게 되면서 그나마 머리속에 dfs, bfs 이해가 된것 같다.
