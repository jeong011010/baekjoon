#include<iostream>
using namespace std;

int main(){
	int n, score = 0, tmp, count=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 1) score += tmp + count++;
		else count = 0;
	}
	cout << score;

	return 0;
}