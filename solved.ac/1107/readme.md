
# 백준 1107 리모컨 문제
-brute-force algorithm 활용하기 좋은 문제.

* 처음에는 수학적으로 풀기 시작.
  * check(int n, int size)함수. 받아온 수를 한자리씩 끊어(tmp) 읽어들인 후, 그 수가 고장난지 판단.
  * 0에서 tmp까지(max), 9에서 tmp까지(min) for문 후 max와 min 중 tmp와 가까운 수 채택
    * 같을 시, min 사용
  * 채택 후 click_num(클릭한 숫자)에 저장, click(클릭한 횟수)++;
  * 1자리가 될 때까지 재귀함수로 반복 후, 1자리가 되면 return;
  * main함수로 돌아와서 click을 save(int)에 저장후 1000일 경우 999처럼 3자리가 빠를 수 있으므로 정해진 size에서 1자리를 빼고 9로 채운 수로 check();
  * 서로 비교한 후 작은 수를 click에 저장.
  * 100에서 뺴거나 더한것이 작을 경우를 대비하여 n-100과 100-n 계산하여 click과 비교 후 작은 것 click에 저장 후 출력.

```C
#include<iostream>
using namespace std;
int arr[10] = { 0 };
int n, m, i, click_num = 0, click = 0;
void check(int num, int s) {
click++;
int tmp=num, max=10, min=-1, size=1;
for (int i = 0; i < s - 1; i++) { size *= 10; tmp /= 10; }
//while (tmp > 9) { tmp /= 10; size*=10; }
for (int i = 0; i <= tmp; i++) {
if (arr[i] == 0) max = i;
}
	for (int i = 9; i >= tmp; i--) {
		if (arr[i] == 0) min = i;
	}
	if (max == min && min == tmp) click_num += tmp;
	else {
		if (tmp - max <= min - tmp) click_num += max;
		else if (max == 10) click_num += min;
		else if (min == -1) click_num += max;
		else click_num += min;
	}
	if (s > 1) {
		click_num *= 10;
		if (click_num == 0) click--;
		check(num % size,s-1);
	}
	else {
		
		if (n > click_num) click += n - click_num;
		else click += click_num - n;
		return;
	}
	return;
}

int main() {
	int tmp,size=0,save;
	cin >> n >> m;
	tmp = n;

	while (tmp > 0) {
		size ++;
		tmp /= 10;
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp; 
		arr[tmp] = 1;
	}

	if (n == 100) cout << 0;
	else if (n == 101 || n == 99) cout << 1;
	else if (n == 102 || n == 98) cout << 2;
	else{
		if (m != 10) {
			check(n, size);
		}
			int save_n = n;
		if (n > 9) {
			save = click;
			click = 0;
			click_num = 0;
			n = 0;
			for (int i = 0; i < size - 1; i++) { n *= 10; n += 9; }
			check(n, size - 1);
			click += save_n - click_num;
			if (save < click) { cout << click << ' ' << save << '\n'; click = save; }
		}

		if (save_n < 999 && save_n>100 && save_n - 100 <= click) cout << save_n - 100;
		else if (save_n >= 0 && save_n < 100 && 100 - save_n <= click) cout << 100 - save_n;
		else cout << click;
	}
}
```

  * 하지만 여러가지 반례 발생
    * https://www.acmicpc.net/board/view/46120

* 여러 블로그 참고 후, brute-force algorithm을 사용하여 코드 수정
  * min 함수를 만들어 비교 간편하게 만듬.
  * abs 함수를 사용하여 100에서 +,-로 이동할 때 간편하게 판단 가능
  * 시간 초과 하기엔 시간이 여유가 있으므로 0~1000007까지 전부 실행해보며 가능한지 판단(possible 함수).
  * 가능하다면 check 함수에서 i의 수를 몇번 눌러야하는지 to_string으로 변환하여 tmp에 length 저장 후 i와 n 차이 더하기(+, -)
  * 그 후 min 함수를 통해 비교.

```C
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int arr[10] = { 0 };
int inf = 1000007;
int n, m, i, click_num = 0, click = 0;

int min(int a, int b) {
	return a < b ? a : b;
}

bool possible(int k) {
	if (k == 0)
		return arr[0] ? false : true;
	while (k) {
		if (arr[k % 10] == 1)
			return false;
		k /= 10;
	}
	return true;
}

int check(int n) {
	int hun = abs(n - 100);
	int button_min = inf;
	int tmp;
	for (int i = 0; i <= inf; i++) {
		if (possible(i)) {
			tmp = to_string(i).length();
			tmp += abs(i - n);
			button_min = min(button_min, tmp);
		}
	}
	return min(hun, button_min);
}

int main() {
	int n, m, tmp;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		arr[tmp] = 1;
	}
	cout << check(n) << '\n';
	return 0;
}
```
브루트 포스 알고리즘을 이해하는데 적합한 문제였다.

문제를 풀 때, 무조건 생각나는대로 아이디어로 무작정 풀기보단 이 문제가 무슨 알고리즘에 해당하는지 확인하고 푸는 것이 훨씬 효율적임.
알고리즘 공부의 필요성을 더욱 느낌.
