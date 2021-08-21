#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<pair<int,int>> connect;
stack<int> v;
bool arr[101];
int computer, n;

int dfs() {
	int cnt = 0;
	v.push(1);
	arr[1] = true;
	while (!v.empty()) {
		bool end = false;
		for (int i = 0; i < connect.size(); i++) {
			if (connect[i].first == v.top() && arr[connect[i].second] == false) {
				v.push(connect[i].second);
				arr[connect[i].second] = true;
				connect.erase(connect.begin() + i);
				end = true;
				break;
			}
			else if (connect[i].second == v.top() && arr[connect[i].first] == false) {
				v.push(connect[i].first);
				arr[connect[i].first] = true;
				connect.erase(connect.begin() + i);
				end = true;
				break;
			}
		}
		if (!end) v.pop();
		else cnt++;
	}
	return cnt;
}

int main() {
	cin >> computer >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		connect.push_back(make_pair(a, b));
	}
	cout << dfs();
}