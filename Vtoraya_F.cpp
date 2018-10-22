#include <iostream>
using namespace std;

int PrintF (string& a){
	int m=0;
	for (int i=0; i < a.size(); i++){
		if (a[i] == 'f'){
			m++;
			if (m == 2){
				return i+1;
			}
		}
	}
	if (m == 1){
		return -1;
	}
	else if (m == 0) {
		return -2;
	}
}



int main() {
	string a;
	cin >> a;
	cout << PrintF(a);
}
