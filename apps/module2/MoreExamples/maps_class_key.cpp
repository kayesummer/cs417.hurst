//
// File:	maps_class_value.cpp
// Author:	Adam.Lewis@athens.edu
// Purpose:
// Demo use of user-defined class as keys in an associative container
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person
{
    friend class PersonLessThan;
public:
    string firstName;
    string lastName;

    Person(const string &firstName, const string &lastName);
};

Person::Person(const string &_firstName, const string &_lastName)
    : firstName(_firstName), lastName(_lastName)
{}

class PersonLessThan
{
public:
    bool operator( )(const Person& p1, const Person& p2) const {
      if (p1.lastName < p2.lastName)
         return(true);
      else if (p1.lastName == p2.lastName)
         return(p1.firstName < p2.firstName);
      else
         return(false);
   }
};

int main()
{
   map<Person, bool, PersonLessThan> M;
   Person p_1("Wilma","Flintstone");
   Person p_2("Betty","Rubble");
   Person p_3("Fred","Flintstone");
   Person p_4("Barney","Rubble");
 
   M[p_1] = true;
   M[p_2] = true;
   M[p_3] = true;
   M[p_4] = true;

   for( map <Person, bool>::iterator ii = M.begin(); ii != M.end(); ++ii)
   {
       cout << ((*ii).first).lastName << ", " << ((*ii).first).firstName << ": " << (*ii).second << endl;
   } 
}