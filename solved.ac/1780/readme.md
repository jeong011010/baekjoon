# 백준 1780 종이의 개수
- 재귀함수, 분할 정복 알고리즘 활용 문제

## 풀이
- dac(divide and conquer)함수 호출
- for문을 이용하여 전체 배열을 첫번째 배열과 비교.
- 비교중 다른 값이 있을 시, 재귀 함수 {dac(divide and conquer)함수} 호출
- dac 함수:
  - 첫번째 배열을 tmp에 저장후 size x size만큼 for문을 이용해 서로 비교.
  - 비교 값이 다를 시, for문을 총 9번
    - 재귀 함수 호출(size/3, k x size / 3 + x, l x size / 3 + y)
  - 호출 후, 재귀 함수를 호출하지 않은 경우 tmp의 값에 따라서 a, b, c중 하나를 ++해줌.  

```C
void dac(int size, int x, int y) {
	int tmp = paper[x][y];
	bool check = false;
	for (int i = x; i < size + x; i++) {
		for (int j = y; j < size + y; j++) {
			if (tmp != paper[i][j]) {
				check = true;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						dac(size / 3, k * size / 3 + x, l * size / 3 + y);
					}
				}
				goto a;
			}
		}
	}
	a:
	if (check == false) {
		if (tmp == -1) a++;
		else if (tmp == 0) b++;
		else if (tmp == 1) c++;
	}
}
```

##
- 분할 정복 알고리즘을 이용하여 문제를 풀 수 있었음.
- 재귀 함수 호출할 때, 인수를 넣을 때 이중 for문을 이용하여 (k,l) x size / 3 + (x,y)를 하는 부분에 고민이 많았음.
- 분할 정복 알고리즘을 따로 공부하여 정리해야겠음.
