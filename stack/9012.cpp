#include<iostream>
#include<cstring>
using namespace std;

class Stack {
	int top, size;
public:
	Stack() {
		top = 0; size = 50;
	}

	void push() {
		top++;
	}
	int pop() {
		top--;
		if (top < 0)
			return 0;
		return 1;
	}
	bool is_empty() {
		return (top == 0 ? true : false);
	}
	int what() {
		return top;
	}

};

int main(){
	int n, size;
	bool fact;
	char c;
	cin >> n;
	n++;

	bool* YN = new bool[n];
	for (int i = 0; i < n; i++) {
		fact = true;
		Stack s;
		while (1) {
			cin.get(c);
			if (c == '\n')
				break;
			else if (c == '(')
				s.push();
			else if (c == ')')
				if (s.pop() == 0) { fact = false; }
		}
		YN[i] = s.is_empty();
		if (fact == false) YN[i] = false;
	}
	for (int i = 1; i < n; i++)
		cout << (YN[i] == true ? "YES" : "NO")<< '\n';
}