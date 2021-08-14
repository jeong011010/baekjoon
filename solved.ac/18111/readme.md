
# 백준 18111 마인크래프트
- brute-force algorithm & sort를 이용한 구현 문제

## 풀이
- 크기가 500인 전역 배열 h를 만들어서 for문을 통해 높이를 입력받으면, 그 높이에 해당하는 배열을 1씩 더해주었다.
- 동시에 for문에서 max와 min을 비교하며 미리 구해둔다. (초기값 max:-1, min:501)
- 만약 max와 min이 같다면 시간이 들지 않으므로 예외처리.
- 벡터를 pair<int, int>로 선언하여 시간과 평지가 된 높이를 push해준다.
- k의 초깃값을 min으로 잡아준 뒤 max까지 1씩 더하며 for문 돌려준다
  * 입력받지 않은 높이가 정답이 될 수 있기 때문.
- k를 min부터 max사이에 존재하는 h[i]와 비교해준다.
- k가 i와 같다면 k의 높이에서 변화할 필요 없으므로 코드x
- k>i면 땅을 설치해야 하므로 time을 (k와 i의 차 * i 높이의 땅의 개수) 계산 해준다. block은 잃게 됨으로 뺴준다.
- k>i면 땅을 삭제해야 하므로 time을 (k와 i의 차 * i 높이의 땅의 개수 * 2) 계산 해준다. block은 얻게됨으로 더해준다.
- 이후 block의 총 개수가 0 이상이라면 앞서 만들어 둔 vector에 push해준다.
  * 이후 벡터를 오름차수 정렬할 떄, (time, k)로 정렬하게 되면 k부분에서 내림차수 정렬을 하지 못하게 되어서 -1을 곱해주어 오름차수 정렬을 second에 한해서 내림차수 정렬로 바꿀 수 있도록 만들어준다.
- 정렬 이후 첫번째 벡터를 출력해준다.


```C
if (max == min) cout << 0 << ' ' << max; //예외처리
else {
	vector<pair<int, int>> v;
	for (int k = min; k <= max; k++) {
		int time=0, block = b;
		for (int i = min; i <= max; i++) {
			if (h[i] != 0) {
				if (k > i) {
					time += (k - i) * h[i];
					block -= (k - i) * h[i];
				}
				else if (k < i) {
					time += (i - k) * h[i] * 2;
					block += (i - k) * h[i];
				}
			}
		}
		if (block >= 0) {
			v.push_back(make_pair(time,-1*k));
		}
	}
	sort(v.begin(), v.end());
	cout << v[0].first << ' ' << v[0].second * -1;
}
```

- 반례 없이 원트로 풀어버렸다.
- 다만 k와 i, h[] for문 만들 때 min이랑 max를 쓸대없이 계속 집어넣는 멍청한짓을 했다.

##
- 브루트 포스 이제 껌임!
- 왠만한 브루트 포스 문제는 아이디어나 구상이 대부분이라 조금만 더 연습하면 감 잡게 될듯
