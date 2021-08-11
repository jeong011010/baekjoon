#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, min, tmp, ans=0;
	string str;
	cin >> n;

	for(int i=0;i<n;i++){
		str = to_string(i);
		tmp = i;
		for (int j = 0; j < str.length(); j++) { tmp += (int)str[j] - 48; }
		if (tmp == n) {
			ans = 1;
			cout << i;
			break;
		}
	}
	if (ans == 0) cout << 0;

}