#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int t;
long long k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		multiset<int> q;
		for (int j = 0; j < k; j++) {
			char c;
			long long n;
			cin >> c >> n;
			if (c == 'I') {
				q.insert(n);
			}
			else if (c == 'D') {
				if (!q.empty()) {
					if (n == 1) {
						auto tmp = q.end();
						tmp--;
						q.erase(tmp);
					}
					else if (n == -1) {
						q.erase(q.begin());
					}
				}
			}
		}
		if (q.empty()) cout << "EMPTY\n";
		else { 
			auto tmp = q.end();
			tmp--;
			cout << *tmp << ' ' << *q.begin() << '\n'; 
		}
	}
	return 0;
}