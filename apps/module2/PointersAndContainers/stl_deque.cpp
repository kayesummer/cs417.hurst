//
// File:    stl_deque.cpp
// Author:  adam.lewis@athens.edu
// Purpose:
// Illustrate use of STL deque class
//

#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
int main() {
  deque<int> a_deck;
  a_deck.push_back (3);
  a_deck.push_front (1);
  a_deck.insert (a_deck.begin () + 1, 2);
  a_deck[2] = 0;
  copy (a_deck.begin (), a_deck.end (),
  ostream_iterator<int>(std::cout, " "));
  return 0;
}