#include<iostream>
using namespace std;

int main(){
	int n, max=0;
	double sum = 0;
	cin >> n;
	int* tmp = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> tmp[i];
		if (tmp[i] > max) max = tmp[i];
	}
	for (int i = 0; i < n; i++) sum += tmp[i] / (double)max * 100;
	cout << (double)sum / (double)n;
}