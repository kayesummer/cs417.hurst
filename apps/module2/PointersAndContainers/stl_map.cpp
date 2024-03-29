//
// File:    stl_map.cpp
// Author:  adam.lewis@athens.edu
// Purpose:
// Illustrate use of STL map class
//
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
typedef std::map<std::string, int> My_Map;
struct print {
    void operator () (const My_Map::value_type &p)
    { std::cout << p.second << " "
                << p.first << std::endl; }
};
int main() {
   My_Map my_map;
   for (std::string a_word;
        std::cin >> a_word; ) 
   {
	   my_map[a_word]++;
   }
   std::for_each (my_map.begin(),
		  my_map.end(),
                  print ());
   return 0;
}