# 백준 11279 최대 힙
- priority queue를 이용해 풀어낸 문제

## 풀이
- 힙을 구현하는 문제이다.
- 이 문제를 풀기 전에 이중 우선순위 큐를 풀고왔는데, 거기서 multiset을 사용한 후여서 바로 사용해봤다.
  - 하지만 위 문제는 우선순위가 하나만 있기에 multiset을 쓸 필요가 없었다.
- 시간초과가 나기도 하고 priority queue로 풀어보고 싶어서 한번 사용해봤다.

- 우선순위 큐도 힙과 구조가 같다.
- 완전 이진 트리 형태로 이루어져있으며, 자료를 넣으면 바로 이진 탐색 트리로 인해 자동으로 정렬된다.
- 위 기능을 이용하여 최대값, 최소값을 구할 수 있다 (동시에 둘다 구하고싶으면 위에 언급한 multiset을 사용하자.

```C
cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty()) {
				cout <<"0\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(tmp);
	}
```

- queue처럼 push랑 pop 똑같이 해준다.
- 다만 priority queue는 pop 할시 우선순위에 따라 값이 도출된다!

##
- 우선순위 큐를 통해 heap의 구조를 거의 완벽하게 이해해간다.
- 다음엔 heap 자체를 구현해볼 생각이다.

- 그리고 가끔 시간초과 나올 때
```C
cin.sync_with_stdio(0);
cin.tie(0);
```
- 사용하면 해결될 때가 다반사다. 코드 기억하자.
