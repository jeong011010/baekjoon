
# 백준 1260 나는야 포켓몬 마스터 이다솜
- 해시 탐색 알고리즘을 이용하여 풀어낸 문제

## 풀이
- vector<pair<string, int>>를 만들어서 전부 저장 후 선형 탐색을 시도하였다 (터무니 없는 시도...)
- 당연히 시간 초과 나왔고, 해당 문제는 문제에서 주어진 경우의 수 조건이 주어진 시간에 비해 터무니 없이 커서 해시 탐색을 사용해보았다.
- 마침 string과 int를 이용하여 해시를 사용해 볼 수 있는 해시 탐색 알고리즘에 딱 적당한 문제였음.

- 우선 string(이름)이 들어왔을 때, int(번호)를 출력해줄 수 있도록 map을 선언해준다. (해시 알고리즘)
- 숫자가 int(번호)가 들어왔을 떄, string(이름)을 출력해줄 수 있도록 string 배열을 선언.
- 이후 전부 insert 해준 뒤, string이 들어왔을 떄 map[string]을 통해 O(1)의 시간복잡도로 int를 출력하게 해준다.

```C
#include<iostream>
#include<map>
using namespace std;

map<string, int> pokemon;
string pokemon_s[100001];
int n, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		pokemon.insert(make_pair(s, i));
		pokemon_s[i] = s;
	}
	
	for (int i = 0; i < q; i++) {
		string tmp;
		cin >> tmp;
		if (tmp[0] > 64 && tmp[0] < 91) {
			cout<<pokemon[string(tmp)]<<'\n'; // 해당 포켓몬의 이름 string(key) 자체를 map의 인수에 넣음으로서 int(value)를 도출해준다.
		}
		else {
			int num = tmp[0]-48;
			for (int j = 1; j < tmp.size(); j++) {
				num *= 10;
				num += tmp[j] - 48;
			}
			cout << pokemon_s[num] << '\n';
		}
	}
}
```

##
- 약간 string을 배열 인수처럼 사용할 수 있는 그런 느낌이었다.
- 조금 적응만 되면 아주 유용할 듯.
