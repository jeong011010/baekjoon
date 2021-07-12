#include<iostream>
#include<string>
#include<queue>
using namespace std;

int n, tmp, sum, st=-1, laser = 0, open=0;
char ch;
queue<int> q;

int main() {
	while (1) {
		cin.get(ch);
		if (ch == '\n') break;
		q.push((ch=='('?0:1)); // ( = 0, ) = 1
	}

	int size = q.size();

	for (int i = 0; i < size; i++) {
		if (q.front() == 0) { 
			st++; 
			if (open == 1)
				sum++;
			laser = 1;
			open = 1;
		}
		else {
			if (laser == 1) {
				laser = 0;
				if(st>0)
					sum += st;
			}
			st--;
			open = 0;
		}
		cout << sum << '\n';
		q.pop();
	}

	cout << sum;

	return 0;
}