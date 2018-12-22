#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int main(){
	ifstream input("input.txt");
	double a;
	double b;
	input >> a;
	input >> b;

	cout << (round(a*1000))/1000 << endl;
	cout << (round(b*1000))/1000 << endl;
}
