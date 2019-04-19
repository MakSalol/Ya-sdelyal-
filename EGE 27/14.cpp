#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N];
	int a = 0;
	int l = 0;
	int m = 0;
	int z = 0;
	for (int i = 0; i < N; i++){
		cin >> A[i];
		if ((A[i] > a) && (A[i] % 21 == 0)){
			a = A[i];
			int t = A[0];
			A[0] = A[i];
			A[i] = t;
		}
	}
	int R;
	cin >> R;
	for (int i = 1; i < N; i++){
		if (A[i] > l){
			l = A[i];
		}
	}
	for (int i = 1; i < N; i++){
		if ((A[i] >= m) && (A[i] % 3 == 0) && (A[i] % 21 != 0)){
			m = A[i];
		}
	}
	for (int i = 1; i < N; i++){
		if ((A[i] >= z) && (A[i] % 7 == 0) && (A[i] % 21 != 0)){
			z = A[i];
		}
	}
	if (a * l < m * z){
		cout << m * z << endl;
		if (m * z != R){
			cout <<"Access denied";
		}else{cout <<"Access granted";}
	}
	else{
		cout << a * l << endl;
		if(a * l != R){
			cout <<"Access denied";
		} else{cout <<"Access granted";}
	}
}
