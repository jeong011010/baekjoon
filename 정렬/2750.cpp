#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int testcase, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, tmp;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';

	return 0;
}