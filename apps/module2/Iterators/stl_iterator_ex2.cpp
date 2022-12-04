//
// File:    stl_iterator_ex2.cpp
// Author:  adam.lewis@athens.edu
// Purpose:
// Example of using an iterator with a vector

#include <list>
#include <iostream>
using namespace std;
int main() {
    list<char> coll;
    for (char c='a'; c <= 'z'; ++c) {
     coll.push_back(c);
    }
    list<char>::const_iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos)
    {
     cout << *pos << ' ';
    }
    cout << endl;
}
