# 백준 7662-이중 우선순위 큐

## 풀이
- 이중 우선순위 큐와 큐의 차이점을 알아야 한다.
  - queue는 선입선출로 push와 pop만 가능하지만
  - 이중 우선순위 queue는 우선순위가 높고 낮음에 따라 pop이 선택적으로 가능하다.
- 해당 이중 우선순위 queue를 구현하기 위해서는 일반적인 queue.pop 외에 stack.pop이 가능해야 한다.
- 일반적으로 heap의 구조와 맞아떨어지기에 heap이나 우선순위 queue로 풀지만 
- 우선 vector로 구현할 수 있을것 같아 해보았다.  

```C
vector<int> q;
int t;
long long k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) { //testcase
		cin >> k;
		for (int j = 0; j < k; j++) { //give command
			char c;
			long long n;
			cin >> c >> n; //n 받은 후
			if (c == 'I') {
				cin >> n;
				q.push_back(n); //Insert 경우 push (n)
				sort(q.begin(), q.end()); //sort로 정렬
			}
			else if (c == 'D') { //Delete 경우
				if (!q.empty()) { //q가 비어있지 않다면
					if (n == 1) {
						q.erase(q.begin() + q.size() - 1); //최대값 삭제시 q.size()-1의 배열 삭제
					}
					else if (n == -1) {
						q.erase(q.begin()); //최소값 삭제시 q.begin 삭제
					}
				}
			}
		}
		if (q.empty()) cout << "EMPTY\n";
		else cout << q[q.size() - 1] << ' ' << q[0] << '\n';
		q.clear();
	}
}
```

- 위 코드는 로직상 문제는 없었지만 시간 복잡도에 문제가 있었다.
- vector의 임의의 위치의 삽입 및 삭제는 vector의 size에 따라 시간 복잡도가 바뀌는데, 커질수록 O(n)에 가까워진다.
- O(logN)을 요구하는 문제를 만족시킬 수 없었기에, 시간복잡도가 O(logN)인 multiset STL을 한번 사용해봤다.

```C
#include<set>

int t;
long long k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) { //testcase
		cin >> k;
		multiset<int> q; //multiset 선언
		for (int j = 0; j < k; j++) { //give command
			char c;
			long long n;
			cin >> c >> n;
			if (c == 'I') {
				q.insert(n); // 이진 트리 구조에 삽입되므로 O(logN)의 시간복잡도. 자동으로 정렬 되어 추가됨.
			}
			else if (c == 'D') {
				if (!q.empty()) {
					if (n == 1) {
						auto tmp = q.end(); //마지막 배열 인덱스 -1에 넣어야하는데 주소값이므로 auto로 형변환 
						tmp--; //형변환 된 주소 값을 1 빼준 뒤
						q.erase(tmp); //해당 위치 인덱스 값 삭제
					}
					else if (n == -1) 
						q.erase(q.begin()); //첫 인덱스 값 삭제
		}}}
		if (q.empty()) cout << "EMPTY\n";
		else { 
			auto tmp = q.end();
			tmp--;
			cout << *tmp << ' ' << *q.begin() << '\n'; 
		}
	}
	return 0;
}
```

- set은 이진트리 구조로서 삽입, 삭제 할 때마다 자동으로 정렬이 된다.
- 삽입 : 정렬이 되어있으므로 logN의 시간복잡도
- 삭제 : 정렬된 트리구조이므로 logN의 시간복잡도

##
- set STL은 heap이나 priority queue와 비슷한 구조지만 라이브러리로 구현이 되어 있어 사용하기 편하다.
- 특정 배열에서 우선순위 기준 최댓값 최솟값을 구해야 할 때, 시간 복잡도가 O(logN)으로 매우 효율적이다.
