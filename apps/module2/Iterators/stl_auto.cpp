//
// File:    stl_auto.cpp
// Author:  adam.lewis@athens.edu
// Purpose:
// How automatic type detection helps simplify code
#include <list>
#include <iostream>
using namespace std;
int main()
{
 list<char> coll;      // list container for character elements
 // append elements from 'a' to 'z'
 for (char c='a'; c<='z'; ++c) {
   coll.push_back(c);
 }
 for (auto pos = coll.begin(); 
           pos != coll.end(); 
	   ++pos) {
      cout << *pos << ' ';
 }
 cout << endl;
}