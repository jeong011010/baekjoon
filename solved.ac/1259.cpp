#include<iostream>
#include<vector>
using namespace std;

int main() {
	while (1) {
		vector<int> v;
		int check=0;
		string s;
		cin >> s;
		if (s == "0")
			break;
		for (int i = 0; i < s.size(); i++) v.push_back(s[i]);
		for (int i = 0; i < s.size() / 2; i++) {
			if (v[i] != v[s.size() - i - 1]) {
				check = 1;
				break;
			}
		}
		cout << (check == 1 ? "no" : "yes") << '\n';
	}

}