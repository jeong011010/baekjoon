#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m, sol=0, tmp;
	vector<int> card;
	cin >> n >> m;
	for (int i = 0; i < n; i++) { cin >> tmp; card.push_back(tmp); }

	for (int i = 0; i<n-2; i++) {
		for (int j = i+1; j<n-1; j++) {
			for (int k = j+1; k<n; k++) {
				tmp = card[i] + card[j] + card[k];
				if (tmp <= m && tmp >= sol) sol = tmp;
			}
		}
	}
	cout << sol;
}