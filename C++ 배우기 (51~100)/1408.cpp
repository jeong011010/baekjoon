/*#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
#define max 86400
using namespace std;

int sec(string s) {
	int second;
	istringstream str(s);
	string token;
	getline(str, token, ':');
	second = stoi(token)*3600;
	getline(str, token, ':');
	second += stoi(token) * 60;
	getline(str, token, ':');
	second += stoi(token);
	return second;
}

int main() {
	string s;
	int now, start, second;
	int h, m, se;
	cin >> s;
	now = sec(s);
	cin >> s;
	start = sec(s);

	if (now > start) {
		second = max - (now - start);
	}
	else {
		second = start - now;
	}
	h = second / 3600;
	m = (second % 3600) / 60;
	se = ((second % 3600) % 60) % 60;
	cout << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << se << endl;
}*/