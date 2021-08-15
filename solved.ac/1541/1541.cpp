#include<iostream>
#include<string>
using namespace std;

string s;
int arr[51];

int main() {
	int j = 0, flag=0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') flag = 1;
		else if (s[i] == '-') flag = 0;
		else {
			arr[j] += s[i]-48;
			while (s[i + 1] != '+' && s[i + 1] != '-' && i<s.size()-1) {
				arr[j] *= 10;
				i++;
				arr[j] += s[i] - 48;
			}
			j++;
			if (flag == 1) {
				j--;
				arr[j - 1] += arr[j];
				arr[j] = 0;
				flag = 0;
			}
		}
	}
	j--;
	int sum = arr[0];
	for (int i = 1; i <= j; i++) {
		sum -= arr[i];
	}
	cout << sum;
}