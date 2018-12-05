#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct changes{
string name;
string surname;
int date;
int changingFn;// переменные, которые отвечают за сам факт изменения имени и фамилии.
int changingSn; // 1 = изменение произошло, 0 = изменений не было.
changes (string a, string b, int c, int d, int f){
	name = a;
	surname = b;
	date = c;
	changingFn = d;
	changingSn = f;
}
};


class Person{
public:
	string first_name;
	string second_name;
	int birth;
	vector <changes> change;
	int m = 0;
	Person (string a, string b, int c){
		first_name = a;
		second_name = b;
		birth = c;
		changes d(a,b,c, 0, 0);
		change.push_back(d);
	}
	void ChangeFirstName(int year, const string& new_first_name){
		if (year > birth){
			if (new_first_name == first_name){
			m++;
			}else
			{
			first_name = new_first_name;
			string new_second_name = second_name;
			changes NewFirst(new_first_name, new_second_name, year, 1, 0);
			change.push_back(NewFirst);
			}
		}
		else cout << "No Person" << endl;
	}
	void ChangeLastName(int year, const string& last_name) {
	   if (year > birth){
		   if (last_name == second_name){
			  m++;
		   }else
		   {
		   string new_first_name = first_name;
		   second_name = last_name;
		   changes NewSecond(new_first_name, last_name, year, 0, 1);
		   change.push_back(NewSecond);
		   }
	   }
	   else cout << "No Person" << endl;
	}
	void GetFullNameWithHitory(int year) {
		for (unsigned int i = 0; i < change.size(); i++){
			cout << change[i].name <<" "<< change[i].surname <<" " << change[i].date << endl;
		}
	}
	void GetFullName(int year){
		int l = 0;
		int k = 0;
		int z = 0;
		if (birth < year){
			for (unsigned int i = 0; i < change.size(); i++){
				if ((change[i].date <= year)){
					l++;
					 if (change[i].changingFn == 1){  //считаю все изменения.
						 k++;
					 }
					 if (change[i].changingSn == 1){
						 z++;
					 }
					}
				}
			if ((k != 0) && (z != 0)){
				cout << change[l-1].name <<" "<< change[l-1].surname <<" "<< endl;
			}
			if ((k == 0) && (z != 0)){
				cout << change[l-1].surname <<" "<< "with unknown first name" << endl;
			}
			if ((k != 0) && (z == 0)){
				cout << change[l-1].name <<" "<< "with unknown last name" << endl;
			}
			if ((k == 0) && (z == 0)){
				cout << "Incognito" << endl;
			}
		} else cout << "No Person";
	}
};

int main() {
  Person abc("Victoriya", "Olololshina", 1950);

  abc.ChangeLastName(1951, "Olololshina");
  abc.ChangeLastName(1952, "Olololshina");
  abc.ChangeFirstName(1953,"Yana");


  abc.ChangeFirstName(1965, "Polina");
  abc.ChangeLastName(1967, "Sergeeva");
  abc.ChangeFirstName(1969, "Galina");
  abc.ChangeLastName(1970, "Ivanova");
  abc.ChangeLastName(1971, "Ivanova");
  abc.ChangeLastName(1972, "Krasnova");
  abc.GetFullNameWithHitory(1973);
  cout << endl;
  abc.GetFullName(1952);

  return 0;
}
