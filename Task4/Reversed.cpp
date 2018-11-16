#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Reversed(const vector<int>& v){
	vector<int> b;
	for (int i = v.size() - 1; i >= 0; i--){
		b.push_back(v[i]);
	}
	return b;
}

int main(){
	vector<int> a={1, 2, 3, 4};
	for (auto r : Reversed(a)){
		cout << r << " ";
	}
}
