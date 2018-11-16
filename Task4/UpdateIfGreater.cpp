#include <iostream>
using namespace std;

void UpdateIfGreater(int& first, int& second){
	if (first > second){
		second = first;
		cout << "b=" << second;
	}
	else cout << "sry, but a <= b";
}


int main(){
	int a,b;
	cin >> a >> b;
	UpdateIfGreater(a,b);
}
