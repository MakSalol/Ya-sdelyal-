#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(int& f, int& n){
	return abs(f) > abs(n);
}

int main(){
	int N;
	int v;
	cin >> N;
	vector<int> a={N};
	for (N - 1; N > 0; N--){
		cin >> v;
		a.push_back(v);
	}
	sort (a.begin(), a.end(), comp);
	for (int m = 0; m < a.size(); m++){
		cout << a[m] << " ";
	}
}
