#include<iostream>
#include<string>
#include<queue>
using namespace std;

int n, tmp;
string mod;
queue<int> q;

void recycle(int n) {
	for (int i = 0; i < q.size() - n; i++) {
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
}

void push_front() {
	cin >> tmp;
	q.push(tmp);
	recycle(1);
}
void push_back() {
	cin >> tmp;
	q.push(tmp);
}
void pop_front() {
	if (!q.empty()) {
		cout << q.front()<<'\n';
		q.pop();
	}
	else cout << "-1\n";
}
void pop_back() {
	if (!q.empty()) {
		cout << q.back() <<'\n';
		recycle(1);
		q.pop();
	}
	else cout << "-1\n";
}
void size() { cout << q.size()<<'\n'; }
void empty() { cout << (q.empty() == 1 ? '1' : '0') << '\n'; }
void front() { cout << (q.empty() == 0 ? q.front() : -1) << '\n'; }
void back() { cout << (q.empty() == 0 ? q.back() : -1) << '\n'; }
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mod;

		if (mod == "push_front") { push_front(); }
		else if (mod == "push_back") { push_back(); }
		else if (mod == "pop_front") { pop_front(); }
		else if (mod == "pop_back") { pop_back(); }
		else if (mod == "size") { size(); }
		else if (mod == "empty") { empty(); }
		else if (mod == "front") { front(); }
		else if (mod == "back") { back(); }
	}

	return 0;
}