#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int testcase, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tmp;
	string n;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n.size(); i++)
		v.push_back(n[i]-48);

	sort(v.begin(), v.end());

	for (int i = 0; i < n.size(); i++) {
		cout << v[n.size()-i-1];
	}

	return 0;
}