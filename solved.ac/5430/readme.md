# 백준 5430 AC
- deque를 이용해 풀어낸 문제

## 풀이
- deque의 성질인 앞뒤로 queue가 통하는 것을 이용하여 풀어낼 수 있었다.
- string을 통하여 명령과 '[' ',' ']'가 포함된 숫자를 구분하여 수를 dq에 저장해준다.

- 이 문제는 queue로 풀 수 있다고 생각했지만, reverse 명령어를 구현해주기 위해 deque를 사용했다.

- 이후 cmd string에 저장된 명령어를 순서대로 dq에서 실행시킨 뒤 출력해준다.
- reverse의 유무에 신경을 써야하는 문제였다.

```C
int tmp = 0;
dq.clear();
cin >> cmd >> n >> num;
for (int i = 1; i < num.size(); i++) { // 대괄호와 쉼표가 포함된 수를 구분하여 dq에 push_back
	if (num[i] == ']') { 
		if (tmp == 0) break;
		tmp /= 10; dq.push_back(tmp);  break; 
	}
	else if (num[i] == ',') { tmp /= 10; dq.push_back(tmp); tmp = 0; }
	else { tmp += (int)num[i] - 48; tmp *= 10; }
}

bool rev = false;
bool err = false; 

for (int i = 0; i < cmd.size(); i++) {
	if (cmd[i] == 'R') rev = !rev; //reverse 명령어 사용시 bool rev를 뒤집어준다.
	else {
		if (dq.empty()) { err = true; break; } //dq가 비어있을 때 delete 명령어 사용시 error 출력
		if (rev) dq.pop_back(); //rev = true일 경우 뒤를 pop 해준다.
		else dq.pop_front(); //rev = false일 경우 앞을 pop 해준다.
	}
}
if (err) cout << "error\n";
else {
	cout << '['; 
	if (!dq.empty()) { //dq가 비어있을 때는 '[]'만 출력되야 하므로 비어있는 경우도 추가해준다.
		if (rev) cout << dq[dq.size() - 1]; //rev=true인 경우
		else cout << dq[0]; //rev=false인 경우를 구분하여 따로 구현해준다.
	}
	for (int i = 1; i < dq.size(); i++) {
		cout << ',';
		if (rev) cout << dq[dq.size() - i - 1];
		else cout << dq[i];
	}
	cout << ']'<<'\n';
}
```

- deque는 queue와 같지만 뒤로 pop과 push가 가능한 (내 생각에는 queue와 stack의 성질을 합친듯한 느낌이다.)것으로 두개의 성질이 필요할 때 사용하면 유용할 것 같다.

##
- 너무 안풀려서 한참 생각하다가 놀다가 오늘 집중해서 문제 자체를 패드에 쓰면서 정리한 뒤에 구현했다.
- 문제가 안풀릴 때는 우선 패드에 그림이나 코드를 써보며 우선 구현을 해본 뒤, 코드로 옮겨보자** 매우 도움이 된다.
