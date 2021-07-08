#include<iostream>
using namespace std;

int main(){
	int up, down, in=0, max=0;
	for (int i = 0; i < 4; i++) {
		cin >> down >> up;
		in += up - down;
		if (in > max) max = in;
	}
	cout << max;
	return 0;
}