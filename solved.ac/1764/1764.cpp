#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v1, v2;

int main(){
	int n, m;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v1.push_back(s);
	}

	sort(v1.begin(), v1.end());
	for (int i = 0; i < m; i++) {
		cin >> s;
		int left = 0, right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (s == v1[mid]) {
				v2.push_back(s);
				break;
			}
			else if (s.compare(v1[mid]) < 0)
				right = mid - 1;
			else if (s.compare(v1[mid]) > 0)
				left = mid + 1;
		}
	}
	sort(v2.begin(), v2.end());

	cout << v2.size()<<'\n';
	for (int i = 0; i < v2.size(); i++) cout << v2[i] << '\n';

}