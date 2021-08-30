#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, cnt;
bool arr[26][26];

int check(int i,int j) {
	ans++;
	arr[i][j] = 0;
	if (j < n && arr[i][j + 1] == 1) { check(i, j + 1); }
	if (i < n && arr[i + 1][j] == 1) { check(i + 1, j); }
	if (j > 1 && arr[i][j - 1] == 1) { check(i, j - 1); }
	if (i > 1 && arr[i - 1][j] == 1) { check(i - 1, j); }
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++)
			arr[i][j] = s[j-1]=='0'?false:true;
	}
	vector<int> v;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == 1) { ans = 0; cnt++; v.push_back(check(i, j)); }
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
}