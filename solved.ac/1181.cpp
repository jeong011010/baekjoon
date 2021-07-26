#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main() {
	int t;
	vector<string> v;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if (find(v.begin(), v.end(), s) == v.end())
			v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}