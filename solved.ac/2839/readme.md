# 2839 설탕 배달 문제
- greedy algorithm 활용 문제

처음으로 greedy algorithm을 사용해본 문제.
* greedy algorithm?
  당장 시점에서만 봤을 때, 가장 최적인 답을 도출해내는 문제.
  이러한 성질 때문에, 최적 부분 구조에서는 강점을 띄지만 전체적으로 봤을 때 더 효율적인 답을 도출해내지는 못할 수 있음.
  
설탕 배달 문제는 3kg, 5kg 봉지를 나눠 들 수 있는 상황에서 가장 적은 봉지를 들 수 있는 경우를 찾아내는 문제로, greedy algorithm에 최적화된 문제.

```C
#include<iostream>
using namespace std;

int main() {
	int n, m, sum, tmp;
	cin >> n;
	m = n / 5;
	while (m >= 0) {
		sum = m;
		tmp = n - m * 5;
		if (tmp % 3 == 0) {
			sum += tmp / 3;
			tmp = 0;
			break;
		}
		else m--;
	}
	if (tmp != 0)cout << -1;
	else cout << sum;

	return 0;
}
```

1. 우선 주어진 무게를 가장 큰 무게인 5로 나눈 후(m), 그만큼 반복.
2. 나눈 수만큼을 5를 곱한 후 전체 수에서 빼면, 5로 나누지 못하는 무게가 도출됨.
3. 나머지 무게를 3으로 나누어 보고, 나누어지지 않는다면 m--;후 while문 반복

greedy algorithm이 마시멜로 이론과 같이 당장의 상황에서 최적의 답을 도출한다는 걔념은 알고 있었지만, 처음 사용할 떄 어떻게 응용할 지 막막했었음.
그리디 알고리즘을 사용할 때는, 전체적이지 않고 단편적 상황에서 최적의 답을 도출하는 경우의 문제에서 점점 줄여가며 알맞는 답이 도출될 때 반복문을 종료하는 구조로 사용하면 될 것 같다.
