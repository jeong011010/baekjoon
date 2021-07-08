#include<iostream>
using namespace std;

int main(){
	int n, tmp, count=0;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		if (tmp == n) count++;
	}
	cout << count;
	return 0;
}