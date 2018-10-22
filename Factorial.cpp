#include <iostream>
using namespace std;

int Factorial (int& a) {
	int b=1;
	if (a > 0){
		for (int i=1; i <= a; i++){
			b=b*i;
		}
			return b;
	}
	else return 1;
}

int main() {
	int a;
	cin >> a;
	cout << Factorial(a);
}


