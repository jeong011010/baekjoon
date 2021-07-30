#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int main() {
	vector<tuple<int,int, string>> v;
	int n, tmp;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> tmp >> s; v.push_back(make_tuple(tmp,i, s)); }
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)cout << get<0>(v[i]) << ' ' << get<2>(v[i]) << '\n';
}