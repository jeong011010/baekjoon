# 백준 1654 랜선 자르기 문제
- 이분 탐색 알고리즘 활용 문제.

처음에는 brute-force algorithm을 이용하여 풀었음.
랜선 길이를 모두 더한 후, 랜선 길이에서 나눈 후 전부 더한 것이 n이 될 때 멈추도록 하였음.
하지만 알고리즘 구조상 문제가 많았기도 하고 여러가지 오류 발생.

```C
#include<iostream>
using namespace std;

int k, n, maximum=1;
long long len_line[10001];
int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> k >> n;
	int t=0;
	for (int i = 1; i <= k; i++) {
		cin >> len_line[i];
		t += len_line[i];
	}
	t /= n;
	int sum, j=t;
	while (1) {
		sum = 0;
		for (int i = 1; i <= k; i++) {
			sum+=len_line[i] / j;
		}
		if (sum == n) {
			maximum = max(maximum, j);
			break;
		}
		else if (sum > n) break;
		j--;
	}
	cout << maximum;
}
```

위 코드를 돌려본 결과 시간초과가 나오기도 하고, 효율성으로도 이분 탐색 알고리즘이 훨씬 효율적이었음.
* left(0)와 right(long long_max), mid((left+right) / 2)를 사용하여 풀었음
  * left가 right보다 커질 때 까지 mid와 비교하며 절반씩 나눠가며 대입. 

```C
#include<iostream>
using namespace std;

int k, n, maximum=0;
long long len_line[10001];
int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> k >> n;
	int t=0;
	for (int i = 1; i <= k; i++) {
		cin >> len_line[i];
	}
	long long left = 0;
	long long right = 2147483647;
	while (left<=right) {
		long long mid = (left + right) / 2;
		int sum = 0;
		for (int i = 1; i <= k; i++) {
			sum+=len_line[i] / mid;
		}
		if (sum >= n) { left = mid + 1; maximum = max(maximum, mid); }
		else { right = mid - 1;}
	}
	cout << maximum;
}
```

오로지 이분탐색으로만 풀 수 있는 간단한 문제였다.
아직도 이론은 알지만 활용을 못하는 문제가 너무 많다. 다양한 알고리즘을 여러가지 문제를 통해 알고리즘 활용의 유연성을 길러야겠다.
