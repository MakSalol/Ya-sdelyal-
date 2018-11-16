#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
	string mnd;
	for (int i=0; i < source.size(); i++){
		destination.push_back(source[i]);
	}
	source.clear();

	for(int m = 0; m < destination.size(); m++){
		cout << destination[m] << " ";
	}
}

int main(){
	vector <string> source={"a", "b", "c"};
	vector <string> destination={"d", "e", "f"};
	MoveStrings(source, destination);
}
