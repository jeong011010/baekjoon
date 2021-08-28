# 백준 11723 집합
- 단순 구현 문제

## 풀이
- 정말 단순한 구현 문제였다.
- 다만 주의깊게 봐야할 부분은 메모리 조건이다. 메모리 제한이 4MB야;;
- 일단 문제에서 주어진 함수 전부 구현해준다.
- 메모리 제한을 넘지 않기 위해 bool 형으로 0과 1로 구현해줬다.
- 마지막으로 ios::sync_with_stdio(false); cin.tie(NULL); 사용해주니 맞았다.

```C
bool arr[21];

void add(int n) {arr[n] = 1;}
void remove(int n) {arr[n] = 0;}
int check(int n) {return arr[n] == 1 ? 1 : 0;}
void toggle(int n) {arr[n] == 1 ? arr[n] = 0 : arr[n] = 1;}
void all() { for (int i = 1; i <= 20; i++) arr[i] = 1; }
void empty() {for (int i = 1; i <= 20; i++) arr[i] = 0;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string command;
		int tmp;
		cin >> command;
		if (command == "add") { cin >> tmp; add(tmp); }
		else if (command == "remove") { cin >> tmp; remove(tmp); }
		else if (command == "check") { cin >> tmp; cout<<check(tmp)<<'\n'; }
		else if (command == "toggle") { cin >> tmp; toggle(tmp); }
		else if (command == "all") all();
		else if (command == "empty") empty();
	}
	return 0;
}
```

##
- 최대한 메모리 초과 안되게 하려고 머리를 좀 짜봤다.
- 이제 함수 구현은 디게 쉬운데 가끔 메모리 제한이나 시간 제한에 애를 먹는것 같다.
- 위 부분만 연습하면 이런 간단한 문제는 껌일듯!
