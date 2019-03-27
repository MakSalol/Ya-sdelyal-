#include <iostream>
using namespace std;
const int c = 3;


void fill(int a[c][c]){
	for (int i = 0; i < c; i++){
		for (int j = 0; j < c; j++){
			cin >> a[i][j];
		}
	}
}

void show(int A[c][c]){
	for (int i = 0; i < c; i++){
		for (int j = 0; j < c; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void tr(int a[c][c]){
	fill(a);
	show(a);
	int b[c][c];
	for(int i = 0; i < c; i++){
		for(int j = 0; j < c; j++){
			b[i][j] = a[j][i];
		}
	}
	show(b);
}


int main(){
	int a[c][c];
	tr(a);
}
