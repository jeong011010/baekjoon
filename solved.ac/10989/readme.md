
# 백준 10989 수 정렬하기 3
- 단순 정렬 알고리즘.

## 풀이
- algorithm 헤더를 이용하여 sort 함수를 사용해 풀기 시작하였음.
  * 단순하게 그냥 전부 벡터로 받은 후 정렬.

```C
int main(){
	int n, tmp;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)cout << v[i] << '\n';
	return 0;
}
```

- 자꾸 메모리 초과 오류가 나서 다시 문제를 확인해보니 메모리제한이 8MB이다.. ㅋㅋㅋㅋㅋㅋ
- stack이나 배열에 수를 저장하는것은 절대 안될 것이라 생각이 들었다.
- 그래서 입력 받을 수 있는 수의 최대 크기인 10000을 크기로 잡은 배열을 만들어서 입력 받은 수에 해당하는 배열에 1씩 더해주기로 했다.
- 이후 for문에서 배열이 0 이상이라면 그만큼 for문을 돌려 해당 수를 출력하게 하였다.

```C
int arr[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp] += 1;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++)
			cout << i<<'\n';
	}
	return 0;
}
```

- 이후 메모리 초과 오류는 잡을 수 있었지만, 시간초과 문제가 발생하였다.
- 예전 codeforce나 scpc 대회에서 이런 일이 자주 있었기에 입력 std 부분에서 시간 초과를 줄여줄 수 있는 코드를 사용하였다.
```C
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
```

##
- 문제를 풀 수록 다양한 제약이 자꾸만 생긴다.
- 오류가 발생했을 때, 해결 방안을 생각해내는 연습이 점점 필요해진다.
