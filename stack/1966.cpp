#include<iostream>
#include<queue>
using namespace std;

int t, n, m, tmp, tmp2_1, tmp2_2, idx;
bool sign;

int main()
{
	int count;
	queue<pair<int, int>> q;
	cin >> t;
	for (int i = 0; i < t; i++) { 
		count = 0;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			q.push({tmp,j});
		}
		while (!q.empty()) {
			sign = false;
			tmp = q.front().first;
			idx = q.front().second;
			q.pop();
			for (int j = 0; j < q.size(); j++) {
				tmp2_1 = q.front().first;
				tmp2_2 = q.front().second;
				if (tmp2_1 > tmp) sign = true;
				q.pop();
				q.push({ tmp2_1, tmp2_2 });
			}
			if (sign == true)
				q.push({ tmp, idx });
			else {
				count++;
				if(idx == m)
					cout << count << '\n';
			}
		}
	}
	
	return 0;

}