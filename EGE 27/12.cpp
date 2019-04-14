#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int a[N];
	int k = 1001;
	int l = 1001;
	int j = 1001;
	for (int i = 0; i < N; i++){
		cin >> a[i];
		if (a[i] < k){
			k = a[i];
			a[i] = a[0];
			a[0] = k;
		}
	}
	int control;
	cin >> control;
	if (k % 2 == 0){
		for (int i = 1; i < N; i++){
			if ((a[i] < l) && (a[i] % 2 == 0) && (a[i] >= k)){
				l = a[i];
			}
		}
		cout << k + l << endl;
		if (k + l == control){
			cout << "Success";
		} else { cout << "Fail"; }
		}
	else {
		for (int i = 1; i < N; i++){
			if ((a[i] < j) && (a[i] % 2 != 0) && (a[i] >= k)){
				j = a[i];
			}
		}
		cout << k + j << endl;
		if (k + j == control){
					cout << "Success";
				} else { cout << "Fail"; }
	}
}
