#include<iostream>
using namespace std;

class gpa {
public:
	int c;
	float g;
};

int main() {
	int t,n,c,j;
	float g;

	cin >> t;

	gpa* gp = new gpa[t];

	for (int i = 0; i < t; i++) {
		gp[i].c = 0;
		gp[i].g = 0;
		cin >> n;

		for (j = 0; j < n; j++) {
			cin >> c >> g;
			gp[i].c += c;
			gp[i].g += g*c;
		}
		gp[i].g /= gp[i].c;
	}

	for (int i = 0; i < t; i++) {
		cout.precision(2);
		cout << gp[i].c << " " << gp[i].g << '\n';
	}
	return 0;
}