#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstring>
using namespace std;

string GetString(vector<string>& v){
	stringstream mm;
	for (unsigned int i =0; i < v.size(); i++){
		mm << v[i] <<" ";
	}
	return mm.str();
}

class Person{
public:
	map <int, string> firstNames;
	map <int, string> lastNames;
	int birth;

  void ChangeFirstName(int year, const string& first_name) {
	  firstNames[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  lastNames[year] = last_name;

  }
  string GetFullName(int year) {
	  string FirstName;
	  string LastName;
	  bool ChangeFirstName = false;
	  bool ChangeLastName = false;
	  stringstream ss;
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

  string GetFullNameWithHistory(int year) {
	  string FirstName;
	  string LastName;
	  vector<string> changesFirst;
	  vector<string> changesSecond;
	  bool ChangeFirstName = false;
	  bool ChangeLastName = false;
	  stringstream ss;
	  for (const auto& name : firstNames){
		  if(name.first <= year){
			  FirstName = name.second;
			  changesFirst.push_back(FirstName);
			  ChangeFirstName = true;
		  }
	  }


	  for(const auto& surname : lastNames){
		  if(surname.first <= year){
			  LastName = surname.second;
			  changesSecond.push_back(LastName);
			  ChangeLastName = true;
		  }
	  }

	  for (unsigned int i = 0; i < changesFirst.size(); i++){
		  if( changesFirst.size() == 1){}
		  if (changesFirst.size() > 1){
		  if (changesFirst[i] == changesFirst[i-1]){
			  changesFirst.erase(changesFirst.begin() + i);
		  }
	  }
	  }

	  for (unsigned int i = 0; i < changesSecond.size(); i++){
		  if (changesSecond.size() == 1){}
		  if (changesSecond.size() > 1){
	  		  if (changesSecond[i] == changesSecond[i-1]){
	  			changesSecond.erase(changesSecond.begin() + i);
	  		  }
	  	  }
	  }
	  changesFirst.erase(changesFirst.end());
	  changesSecond.erase(changesSecond.end());

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
		  if (changesFirst.size() == 0){
			  ss << FirstName <<" "<< LastName <<" (" << GetString(changesSecond) <<")" << endl;
			  return ss.str();
		  }
		  if (changesSecond.size() == 0){
			  ss << FirstName <<" ("<< GetString(changesFirst) <<") " << LastName << endl;
			  return ss.str();
		  }
		  if (changesFirst.size() == 0 && changesSecond.size() == 0){
			  ss << FirstName <<" "<< LastName << endl;
		  }
		  if(changesSecond.size() != 0 && changesFirst.size() != 0){
			  ss << FirstName <<" ("<< GetString(changesFirst) <<") " << LastName <<" (" << GetString(changesSecond) <<")" << endl;
			  return ss.str();
		  }
	  }
  }
};


int main(){
	Person person;

	  person.ChangeFirstName(1965, "Polina");
	  person.ChangeLastName(1967, "Sergeeva");
	  for (int year : {1900, 1965, 1990}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1970, "Appolinaria");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeLastName(1968, "Volkova");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1990, "Polina");
	  person.ChangeLastName(1990, "Volkova-Sergeeva");
	  cout << person.GetFullNameWithHistory(1990) << endl;

	  person.ChangeFirstName(1966, "Pauline");
	  cout << person.GetFullNameWithHistory(1966) << endl;

	  person.ChangeLastName(1960, "Sergeeva");
	  for (int year : {1960, 1967}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeLastName(1961, "Ivanova");
	  cout << person.GetFullNameWithHistory(1967) << endl;

	  return 0;
	}



