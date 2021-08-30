# 백준 2667 단지번호붙이기
- 그래프탐색 문제 (bfs&dfs를 이용해 쉽게 풀 수 있다.)

## 풀이
- 위 문제는 그래프탐색을 활용하도록 만들어진 문제이다.
- 근데 1에서 사방의 1로 노선이 이어지는것을 확인하고 나타내는 것을 그래프 탐색으로 구현할 방법이 생각이 안났다.
- 그래서 bf로 무식하게 풀었다 히히
- 2중 for문을 이용하여 1을 찾은 후, 해당 좌표를 인수로 받아서 사방을 탐색하는 함수를 구현하였다.
  - 지금 보니까 dfs를 stack 없이 배열로 구현했다. 아마 난 천재..?

```C
int check(int i,int j) {
	ans++;
	arr[i][j] = 0;
	if (j < n && arr[i][j + 1] == 1) { check(i, j + 1); }
	if (i < n && arr[i + 1][j] == 1) { check(i + 1, j); }
	if (j > 1 && arr[i][j - 1] == 1) { check(i, j - 1); }
	if (i > 1 && arr[i - 1][j] == 1) { check(i - 1, j); }
	return ans;
}
```

- 이후 해당 함수가 몇번 재귀호출 되었는지 세어주는 ans와
- main 함수에서 해당 함수가 호출된 수 cnt를 세어준 후, ans를 오름차순으로 정렬하여 출력해준다.

```C
cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++)
			arr[i][j] = s[j-1]=='0'?false:true;
	}
	vector<int> v;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == 1) { ans = 0; cnt++; v.push_back(check(i, j)); }
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
```

##
- 최근 우연찮게 평소와 다른 방법으로 그래프 탐색 문제를 풀어내고 있다.
- 배열과 재귀 함수를 이용한 이번 dfs 함수 방식도 꽤 괜찮은 것 같다.
