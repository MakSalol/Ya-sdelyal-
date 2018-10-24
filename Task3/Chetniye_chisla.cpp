#include <iostream>
#include <vector>
using namespace std;

/*
 * Дано два целых числа A и B (A <= B, A >= 1, B <= 30000).
 *  Выведите через пробел все чётные числа от A до B (включительно).
 */

int main() {
	int a,b;
	int i=0;
	cin >> a >> b;
	vector<int> chet;
	if (a <= b && a >= 1 && b <= 30000 ) {
		for (a; a <= b; a++) {
			if (a % 2 == 0) {
				chet.push_back(a);
				i++;
			}
		}
		for (int m = i - 1; m >= 0; m--) {
			cout << chet[m] << " ";
		}
	}
	else cout << "Error";

}


