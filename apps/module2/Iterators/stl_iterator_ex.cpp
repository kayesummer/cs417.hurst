//
// File:    stl_iterator_ex.cpp
// Author:  adam.lewis@athens.edu
// Purpose:
// Example of using an iterator with a vector
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
  vector<string> projects;
  for (int i = 1; i < argc; ++i) {
      projects.push_back(string(argv[i]));
  }
  for (vector<string>::iterator j = projects.begin();
       j != projects.end();
       ++j) {
       cout << *j << endl;
  }
  return 0;
}