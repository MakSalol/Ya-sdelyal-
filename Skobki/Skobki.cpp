#include <iostream>
using namespace std;

int main(){
	string a;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	cin >> a;
	for (auto t : a){
		if (t == '('){
			b += 1;
			e++;
		}
		if (t == ')'){
			b -=1;
			e++;
		}
		if (t == '{'){
			c += 1;
			e++;
		}
		if (t == '}'){
			c -= 1;
			e++;
		}
		if (t == '['){
			d += 1;
			e++;
		}
		if (t ==']'){
			d -= 1;
			e++;
		}
	}
	if ((c == 0) && (d == 0) && (b == 0) && (e != 0)){
		cout << "Correct";
	}
	else {
		cout << "Incorrect";
	}
}
