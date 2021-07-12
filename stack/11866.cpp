#include<iostream>
#include<queue>
using namespace std;

int k, n, tmp;
queue<int> q;

void recycle(int n) {
	for (int i = 0; i < n; i++) {
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
}

void print() {
	cout << q.front();
	q.pop();
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);

	recycle(k - 1);
	cout << '<';
	print();
	for (int i = 0; i < n-1; i++) {
		recycle(k-1);
		cout << ", ";
		print();
	}
	cout << '>';
	return 0;
}