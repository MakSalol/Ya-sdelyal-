#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Reverse(vector<int>& a){
	vector <int> b;
	for (int i = a.size() - 1; i >= 0; i--){
		b.push_back(a[i]);
	}
	for (int s = 0; s < b.size(); s++){
		cout << b[s] << " ";
	}
}

int main(){
	vector<int> numbers ={1, 2, 3, 4, 5};
	Reverse(numbers);
}
