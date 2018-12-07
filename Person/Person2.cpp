#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct changes{
string name;
string surname;
int date;
int changingFn;
int changingSn;
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
	void GetFullNameWithHistory(int year) {
		if (year >= birth){
		for (unsigned int i = 0; i < change.size(); i++){
			cout << change[i].name <<" "<< change[i].surname <<" " << change[i].date << endl;
			}
		} else cout <<"No Person" << endl;
	}
	void GetFullName(int year){
		int l = 0;
		int k = 0;
		int z = 0;
		if (birth <= year){
			for (unsigned int i = 0; i < change.size(); i++){
				if ((change[i].date <= year)){
					l++;
					 if (change[i].changingFn == 1){
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
				if (year < change[1].date){
					cout << change[0].name <<" "<< change[0].surname << endl;
				} else cout <<"Incognito";
			}
		} else cout << "No Person";
	}
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	  for (int year : {1959, 1960}) {
	     person.GetFullNameWithHistory(year);
	  }

	  person.ChangeFirstName(1965, "Appolinaria");
	  person.ChangeLastName(1967, "Ivanova");
	  for (int year : {1965, 1967}) {
	    person.GetFullNameWithHistory(year);
	  }


  return 0;
}
