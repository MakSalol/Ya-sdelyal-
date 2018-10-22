#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a,b,i,m;
	i = 0;
	vector <int> dva={};
	cin >> a;
	while (a >= 1) {
		b = a % 2;
		a /= 2;
		dva.push_back(b);
		i++;
	}
	for (m = i - 1; m >=0; m--)
		cout << dva[m];
}



