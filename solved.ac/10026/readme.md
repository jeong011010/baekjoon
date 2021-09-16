# 백준 10026 적록색약
- 그래프 탐색. dfs 문제

## 풀이
- 입력받은 문자를 배열에 숫자로 저장해준 뒤, 시간 초과를 막기 위해 한번 방문한 곳을 채크해주는 bool형 배열을 선언해준다.
- 방문한 곳의 위치를 stack에 쌓기 위해 pair로 stack을 선언해준다.
- 정상인이 구역을 나누는 경우와, 적록색약이 구역을 나누는 경우가 다르기 때문에 정상인 기준인 배열 상태에서 dfs 함수를 통해 구역 개수를 구한뒤, 현재 숫자로 저장된 배열에서 R과 G를 같은 수로 수정한 뒤 한번 더 dfs 함수를 실행해준다.
- dfs 함수는 처음에 방문한 곳의 색을 tmp에 저장해준 뒤, 상하좌우 구역을 전부 탐색하며 tmp와 같을 경우 해당 위치를 stack에 push해주고, dfs 함수를 재귀호출해준다.

```C
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
```

- 위와 같이 정상인이 보는 구역과 적록색약이 보는 구역을 따로 구하기 위해 두번 dfs 함수를 호출해준다.
- 두개의 호출 사이에는 bool(check)를 초기화 해주고 arr(r과 g)를 같게 만들어주는 작업을 해준다.
- 이후 전체 배열을 탐색하며 방문하지 않는 곳을 찾았을 때, 아래와 같은 dfs 함수를 호출해준다.

```C
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
```

- 위와 같이 코드를 짜서 첫 방문한 색과 같은 곳이 없을 때 까지 탐색하고 방문한 곳은 bool을 true로 바꿔주는 작업인 dfs 함수를 만들어준다.

```C
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
```

- 이후 메인 함수를 위와 같이 작성해주면 끝났다.

##
- 위 문제는 깊이 우선 탐색을 기본적으로 이용하여 풀 수 있는 문제였다.
- 이와 같은 문제는 이전에도 토마토나 미로 탐색같은 문제에서도 볼 수 있었다.
- 위와 같은 dfs문제와 다른 점은 정해진 한개의 배열을 이용해 다른 조건의 dfs 함수를 두번 돌리는 것이었다.

