
# 백준 2606 바이러스
- dfs(depth first search) 응용 프로그램

## 풀이
- 그래프 탐색을 이용하여 1번 정점과 이어져있는 정점의 개수를 출력하면 된다.
- 이어져있지 않은 정점도 있을 수 있기 때문에 dfs를 사용했다. (사실 이게 제일 익숙해서..;;)
- 1번을 push 해준 후, stack이 비어있을 때 까지 아래 구문 반복
  - vector의 첫째나 두번째 인수에 현재 vector.top과 같은것이 있다면 그 외의 다른 인수가 check 배열에 true인지 검사.
  - false라면 true로 만들고 vector에 push해준 뒤 break; cnt++;
  - 모든 간선의 개수만큼 for문을 돌린 이후에도 연결된 간선이 없다면 마지막 정점이므로 pop.

```C
int dfs() {
	int cnt = 0;
	v.push(1);
	arr[1] = true;
	while (!v.empty()) {
		bool end = false;
		for (int i = 0; i < connect.size(); i++) {
			if (connect[i].first == v.top() && arr[connect[i].second] == false) {
				v.push(connect[i].second);
				arr[connect[i].second] = true;
				connect.erase(connect.begin() + i);
				end = true;
				break;
			}
			else if (connect[i].second == v.top() && arr[connect[i].first] == false) {
				v.push(connect[i].first);
				arr[connect[i].first] = true;
				connect.erase(connect.begin() + i);
				end = true;
				break;
			}
		}
		if (!end) v.pop();
		else cnt++;
	}
	return cnt;
}
```

##
- 그래프 탐색 이제 개껌인듯
