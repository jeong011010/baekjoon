#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, tmp;
	vector<int> v1, v2;
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> tmp; v1.push_back(tmp); }
	sort(v1.begin(), v1.end());
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> tmp; v2.push_back(tmp); }

	for (int i = 0; i < v2.size(); i++) {
		int left=0, right=v1.size()-1, mid, answer = 0;
		while (left <= right) {
			mid = (right + left) / 2;
			if (v2[i] > v1[mid])
				left = mid + 1;
			else if (v2[i] < v1[mid])
				right = mid - 1;
			else
			{
				answer = 1; break;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}