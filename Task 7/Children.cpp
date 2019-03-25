#include <iostream>
#include <string>
using namespace std;

class Children{
private:
	string name;
	string surname;
	int age;
public:
	void istream(string a, string b, int c){
		name = a;
		surname = b;
		age = c;
	}
	void ostream(){
		cout <<"Name: " << name << endl;
		cout <<"Surname: " << surname << endl;
		cout <<"Age: " << age << endl;
	}
};

int main(){
	Children Max;
	Max.istream("Max", "Bogomolov", 16);
	Max.ostream();
}
