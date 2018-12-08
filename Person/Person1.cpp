#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Person{
private:
	map <int, string> firstNames;
	map <int, string> lastNames;
public:
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  firstNames[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  lastNames[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
	  string FirstName;
	  string LastName;
	  bool ChangeFirstName = false;
	  bool ChangeLastName = false;
	  for (const auto& name : firstNames){
		  if (name.first <= year){
			  FirstName = name.second;
			  ChangeFirstName = true;
		  }
	  }

	  for (const auto& surname : lastNames){
		  if (surname.first <= year){
			  LastName = surname.second;
			  ChangeLastName = true;
		  }
	  }

	  stringstream ss;
	  if (ChangeFirstName == false && ChangeLastName == false){
		  ss << "Incognito" << endl;
		  return ss.str();
	  }

	  if(ChangeFirstName == true && ChangeLastName == false){
		  ss << FirstName << " with unknown last name" << endl;
		  return ss.str();
	  }

	  if (ChangeFirstName == false && ChangeLastName == true){
		  ss << LastName << " with unknown first name" << endl;
		  return ss.str();
	  }

	  if (ChangeFirstName == true && ChangeLastName == true){
		  ss << FirstName <<" "<< LastName << endl;
		  return ss.str();
	  }
  }
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}

