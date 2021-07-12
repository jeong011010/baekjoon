#include<iostream>
#include<queue>
using namespace std;

int n, tmp;
queue<int> q;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)q.push(i);
	for (int i = 1; i < n; i++) {
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.front();
	return 0;
}