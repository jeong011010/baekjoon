#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<pair<int, int>> point;
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}
	sort(point.begin(), point.end());
	for (int i = 0; i < n; i++) cout << point[i].first << ' ' << point[i].second << '\n';
	return 0;
}