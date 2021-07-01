/*#include<iostream>
#include<string>
using namespace std;

class birth {
public:
	int d, m, y;
	string name;
};

int main() {
	int n;
	birth b[100], min, max;
	cin >> n;
	cin >> b[0].name >> b[0].d >> b[0].m >> b[0].y;
	min = max = b[0];
	for (int i = 1; i < n; i++) {
		cin >> b[i].name >> b[i].d >> b[i].m >> b[i].y;

		if (b[i].y < max.y)
			max = b[i];
		else if (b[i].y == max.y)
			if (b[i].m < max.m)
				max = b[i];
			else if (b[i].m == max.m)
				if (b[i].d < max.d)
					max = b[i];

		if (b[i].y > min.y)
			min = b[i];
		else if (b[i].y == min.y)
			if (b[i].m > min.m)
				min = b[i];
			else if (b[i].m == min.m)
				if (b[i].d > min.d)
					min = b[i];
	}
	cout << min.name << endl << max.name << endl;
	return 0;
}*/