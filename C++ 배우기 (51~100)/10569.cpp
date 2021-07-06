#include<iostream>
using namespace std;

class TestCase {
public:
	int v, e;
};

int main() {
	int t;
	cin >> t;
	TestCase* tc = new TestCase[t];
	for (int i = 0; i < t; i++)
		cin >> tc[i].v >> tc[i].e;
	for (int i = 0; i < t; i++)
		cout<<(tc[i].v-tc[i].e-2)*-1<< '\n';
	return 0;
}