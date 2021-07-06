#include<iostream>
using namespace std;

class TestCase {
public:
	int c, v;
	void print() {
		cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s)." << '\n';
	}
};

int main() {
	int n;
	cin >> n;
	TestCase* tc = new TestCase[n];
	for (int i = 0; i < n; i++)
		cin >> tc[i].c >> tc[i].v;
	for (int i = 0; i < n; i++)
		tc[i].print();
	return 0;
}