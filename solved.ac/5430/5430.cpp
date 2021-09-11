#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;
string cmd;
string num;
int n;

int main() {
	int t;
	cin >> t;
	for (int testcase = 0; testcase < t; testcase++) {
		int tmp = 0;
		dq.clear();
		cin >> cmd >> n >> num;
		for (int i = 1; i < num.size(); i++) {
			if (num[i] == ']') { 
				if (tmp == 0) break;
				tmp /= 10; dq.push_back(tmp);  break; 
			}
			else if (num[i] == ',') { tmp /= 10; dq.push_back(tmp); tmp = 0; }
			else { tmp += (int)num[i] - 48; tmp *= 10; }
		}
		bool rev = false;
		bool err = false;
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'R') rev = !rev;
			else {
				if (dq.empty()) { err = true; break; }
				if (rev) dq.pop_back();
				else dq.pop_front();
			}
		}
		if (err) cout << "error\n";
		else {
			cout << '[';
			if (!dq.empty()) {
				if (rev) cout << dq[dq.size() - 1];
				else cout << dq[0];
			}
			for (int i = 1; i < dq.size(); i++) {
				cout << ',';
				if (rev) cout << dq[dq.size() - i - 1];
				else cout << dq[i];
			}
			cout << ']'<<'\n';
		}
	}
}