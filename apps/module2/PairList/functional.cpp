//
// File:   functional.cpp
// Author: <Your Glorious Instructor>
// Purpose:
// Implement a list ADT using lambda expressions and functional programming
//
// Reference:
// https://numbergeneral.github.io/dailycodingproblem05/?utm_source=pocket_mylist#
// 
#include <iostream>
#include <vector>
#include <functional>

std::function<int (int(*f)(int, int))> combine(int a, int b)
{
  auto pair = [a, b] (int(*f)(int, int)) -> int
  {
     return (*f)(a, b);
  };
  return pair;
}

int head(std::function<int (int(*f)(int, int))> combine){
  auto get_a = [](int a, int b) -> int
  {
    return a;
  };
  return combine(*get_a);
}

int tail(std::function<int (int(*f)(int, int))> combine){
  auto get_b = [](int a, int b) -> int
  {
    return b;
  };
  return combine(*get_b);
}

int main() {
  std::function<int (int(*f)(int, int))> combine_v = combine(1, 2);
  int a = head(combine_v);
  int b = tail(combine_v);
  
  std::cout << "The value of a is: " << a << "\n";
  std::cout << "The value of b is: " << b << "\n";
}