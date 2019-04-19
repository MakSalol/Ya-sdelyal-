#include <iostream>
using namespace std;

int main(){
	int N;
	int a;
	int l = 0;
	int m = 0;
	int n = 0;
	int g = 0;
	int z = 0;
	int f = 0;
	int v = 0;
	cin >> N;
	while (N > 0){
		N--;
		z++;
		cin >> a;
		if ((a > l) && (a % 21 == 0)){
			 f = z;
			l = a;
		}
		if (a > g){
			 v = z;
			if (v != f){
				g = a;
			}
			else {
				continue;
			}
		}
		if ((a > m) && (a % 7 == 0) && (a % 21 != 0)){
			m = a;
		}
		if ((a > n) && (a % 3 == 0) && (a % 21 != 0)){
			n = a;
		}
	}
	int R;
	cin >> R;
	if ((l == 0 && m == 0) || (l == 0 && n == 0)){
		cout << 0;
	}
	if (l * g < m * n){
		cout << m * n << endl;
		if (m * n != R){
			cout <<"Access denied";
		} else{cout <<"Access granted";}
	}
	else {
		cout << l * g << endl;
		if (l * g != R){
			cout <<"Access denied";
		}else{cout <<"Access granted";}
	}
}
