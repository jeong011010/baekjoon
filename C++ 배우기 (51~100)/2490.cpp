#include<iostream>
using namespace std;

int main(){
	int arr[3][4], sum;
	for (int i = 0; i < 3; i++) {
		for(int j=0;j<4;j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < 3; i++) {
		sum = 0;
		for (int j = 0; j < 4; j++)
			sum += arr[i][j];
		switch (sum) {
		case 0: cout << "D\n"; break;
		case 1: cout << "C\n"; break;
		case 2: cout << "B\n"; break;
		case 3: cout << "A\n"; break;
		case 4: cout << "E\n"; break;
		}
	}
}