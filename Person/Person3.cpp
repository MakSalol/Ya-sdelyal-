#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

string GetString(vector<string>& v){
	stringstream mm;
	for ( int i =v.size() - 1; i >= 0; i--){
		mm << v[i] <<" ";
	}
	return mm.str();
}

class Person{
public:
	map <int, string> firstNames;
	map <int, string> lastNames;
	vector<string> changesFirst;
	vector<string> changesSecond;
	int birth;

Person(string a, string b, int c){
	birth = c;
	firstNames[c] = a;
	lastNames[c] = b;
	changesFirst.push_back(a);
	changesSecond.push_back(b);
}


  void ChangeFirstName(int year, const string& first_name) {
	  if(birth > year){

	  }else
	  firstNames[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  if (birth > year){

	  }else
	  lastNames[year] = last_name;

  }
  string GetFullName(int year) {
	  if (birth <= year){
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
	  else{
		  stringstream ss;
		  ss <<"No Person" << endl;
		  return ss.str();
	  }
  }

  string GetFullNameWithHistory(int year) {
	  if (birth <= year){
	  string FirstName;
	  string LastName;
	  string preFirst;
	  string preLast;
	  bool ChangeFirstName = false;
	  bool ChangeLastName = false;
	  stringstream ss;

	  for (auto i : firstNames){
		  if (i.first <= year){
			  ChangeFirstName = true;
			  changesFirst.push_back(i.second);
		  }
	  }

	  for (auto i : lastNames){
		  if(i.first <= year){
			  ChangeLastName = true;
			  changesSecond.push_back(i.second);
		  }
	  }


	  auto v = unique(changesFirst.begin(), changesFirst.end());
	  changesFirst.erase(v, changesFirst.end());

	  FirstName = *(changesFirst.end() - 1);


	  auto m = unique(changesSecond.begin(), changesSecond.end());
	  changesSecond.erase(m, changesSecond.end());
	  LastName = *(changesSecond.end() -1 );

	  if (FirstName == changesFirst.back()){
		  changesFirst.pop_back();
	  }


	  if (LastName == changesSecond.back()){
		  changesSecond.pop_back();
	  }


	  if (ChangeFirstName == false && ChangeLastName == false){
	 	  	  		  ss << "Incognito" << endl;
	 	  	  		  return ss.str();
	 	  	  }

	 	  	  if(ChangeFirstName == true && ChangeLastName == false){
	 	  		  if (changesFirst.size() == 0){
	 	  			ss << FirstName << " with unknown last name" << endl;
	 	  			return ss.str();
	 	  		  }
	 	  		  if (changesFirst.size() != 0){
	 	  	  		ss << FirstName <<" ("<< GetString(changesFirst) <<") " << " with unknown last name" << endl;
	 	  	  		return ss.str();
	 	  		  }
	 	  	  }

	 	  	  	if (ChangeFirstName == false && ChangeLastName == true){
	 	  	  		if (changesSecond.size() == 0){
	 	  	  		ss << LastName << " with unknown first name" << endl;
	 	  	  		return ss.str();
	 	  	  		}
	 	  	  		if (changesSecond.size() != 0){
	 	  	  		 ss << LastName <<" (" << GetString(changesSecond) <<")"  << " with unknown first name" << endl;
	 	  	  		return ss.str();
	 	  	  		}
	 	  	  			  }

	  if (ChangeFirstName == true && ChangeLastName == true){
		  if (changesFirst.size() == 0){
			  if(changesSecond.size() == 0){
				  ss << FirstName <<" "<< LastName << endl;
				  return ss.str();
			  }
			  if (changesSecond.size() != 0){
			  ss << FirstName <<" "<< LastName <<" (" << GetString(changesSecond) <<")" << endl;
			  return ss.str();
			  }
		  }
		  if (changesSecond.size() == 0){
			  if (changesFirst.size() == 0){
				  ss << FirstName << LastName << endl;
				  return ss.str();
			  }
			  if(changesFirst.size() != 0){
			  ss << FirstName <<" ("<< GetString(changesFirst) <<") " << LastName << endl;
			  return ss.str();
			  }
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
	  else {
		  stringstream ss;
		  ss <<"No Person" << endl;
		  return ss.str();
	  }
  }
};


int main(){
	Person person("Polina", "Sergeeva", 1960);
	  for (int year : {1959, 1960}) {
	    cout << year << endl <<  person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1965, "Appolinaria");
	  person.ChangeLastName(1967, "Ivanova");
	  for (int year : {1965, 1967}) {
	    cout << year << endl << person.GetFullNameWithHistory(year) << endl;
	  }

	  return 0;
	}
