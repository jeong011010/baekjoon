#include<iostream>
#include<vector>
using namespace std;

int k, n, sum=0;
vector<int> v;

int main()
{
	cin >> k;
	for (int i = 0; i < k; i++) { 
		cin >> n;
		if (n == 0)
			v.pop_back();
		else if (n > 0)
			v.push_back(n);
	}
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	cout << sum;
	return 0;

}