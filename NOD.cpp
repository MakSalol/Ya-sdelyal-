#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	int a,b,c;
	cin >> a >> b;
	if (a < b){
		c=a;
	}
	else {
		c=b;
	}
	while (a % c !=0 || b % c !=0){
		--c;
	}
	cout << c;
	}







