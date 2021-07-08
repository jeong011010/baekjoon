#include<iostream>
using namespace std;

int dec(int n){
	if (n == 0 || n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;

}

int main() {
	int n,count=0,tmp;
	cin >> n;		
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		count += dec(tmp);
	}
	cout << count;
	return 0;
}