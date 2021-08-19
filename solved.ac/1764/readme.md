# 백준 1764 듣보잡
- 문자열 정렬, 이분탐색 알고리즘 응용 문제

## 풀이
- 듣지 못한 인원을 받은 후 보지 못한 인원을 받으며 같다면 push 후, 정렬하여 출력
- 두개의 문자열을 비교할 때, 시간초과 주의.
- 듣지 못한 인원 n명을 받은 후 v1에 push.

- 처음엔 for문을 이용하여 m개의 보지 못한 인원을 받을 때 마다, n개의 이중 for문을 사용하여 전부 비교하여 있다면 v2에 push해주는 비효율적인 코드를 구상.

```C
int n, m;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) { //듣지 못한 n명 push 후,
		cin >> s;
		v1.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) { //2중 for문으로 전부 비교
			if (s == v1[j]) {
				v2.push_back(s);
				break;
			}
		}
	}
	sort(v2.begin(), v2.end());
```

- 역시나 시간 초과가 났음.
- 문제 알고리즘 분류에는 hash 알고리즘이라고 쓰여 있었지만, 아직 hash는 접근조차 해보지 못한 상태.
- 시간 초과를 줄일 수 있는 방법중 이분탐색이 떠올라 시도해보았음.
- 이분 탐색을 하는 과정에서 듣지 못한 v1이 사전순으로 정렬이 되어있을 때, 현재 비교할 문자열과 사전순으로 비교해야 하기 때문에, compare이라는 함수를 사용하였음.
  * compare 함수: string 헤더파일에 속해있는 함수.
  * (string)a.compare((string)b)을 하여 0보다 작다면 a가 b보다 사전순으로 앞에 있음.
  * 0보다 작다면 b가 a보다 사전순으로 앞에 있으며, 같다면 문자열이 서로 같음.

```C
sort(v1.begin(), v1.end());
	for (int i = 0; i < m; i++) {
		cin >> s;
		int left = 0, right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (s == v1[mid]) {
				v2.push_back(s);
				break;
			}
			else if (s.compare(v1[mid]) < 0)
				right = mid - 1;
			else if (s.compare(v1[mid]) > 0)
				left = mid + 1;
		}
	}
```

- 이분 탐색이 의외로 유용하게 쓰인다. 
- 문자열 비교를 할 때 compare 함수를 사용할 수 있음을 알았다.

##
- 구상한 알고리즘에서 문제가 발생하였을 때, 해당 문제를 또 다른 알고리즘으로 해결할 수 있는 센스가 필요함을 느낌.
