#include<iostream>
#include<cstring>
using namespace std;

int n;

class stack {
public:
	int top, size;
	int* values;

	stack() {
		size = n;
		values = new int[n];
		top = -1;
	}
	~stack() {
		delete[] values;
	}
	bool is_empty() {
		if (top == -1)
			return true;
		else return false;
	}
	bool is_full() {
		if (top == size)
			return true;
		else return false;
	}
	void push(int value) {
		if (is_full())
			cout << "over_flow";
		else
			values[++top] = value;
	}
	int Top() {
		if (!is_empty())
			return values[top];
		else
			return -1;
	}
	int Size() {
		return top+1;
	}
	int empty() {
		if (top < 0)
			return 1;
		else
			return 0;
	}
	int pop() {
		if (!is_empty())
			return values[top--];
		else
			return -1;
	}
};

int main() {
	int v;
	string mod;
	cin >> n;
	stack s;
	for (int i = 0; i < n; i++) {
		cin >> mod;
		if (mod == "push") {
			cin >> v;
			s.push(v);
		}
		else if (mod == "pop") { cout<<s.pop()<<'\n'; }
		else if (mod == "size") { cout<<s.Size()<<'\n'; }
		else if (mod == "empty") { cout<<s.empty()<<'\n'; }
		else if (mod == "top") { cout<<s.Top()<<'\n'; }
		else { exit(1); }
	}
}