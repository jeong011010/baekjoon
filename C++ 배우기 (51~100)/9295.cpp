#include<iostream>
using namespace std;

class TestCase {
public:
	int a, b;
};

int main() {
	int t;
	cin >> t;
	TestCase* tc = new TestCase[t];
	for (int i = 0; i < t; i++)
		cin >> tc[i].a >> tc[i].b;
	for (int i = 0; i < t; i++)
		cout<<"Case "<<i+1<<": "<<tc[i].a+tc[i].b<<'\n';
	return 0;
}