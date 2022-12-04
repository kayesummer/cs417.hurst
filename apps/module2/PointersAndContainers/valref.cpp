//
// File:   valref.cpp
// Author: Adam.Lewis@athens.edu
// Purpose:
// Example of pass by value and pass by reference
#include <iostream>
using namespace std;


void swapByVal(int num1, int num2) {
   int temp = num1;
   num1 = num2;
   num2 = temp;
}

void swapByRef(int& num1, int& num2)
{
   int temp = num1;
   num1 = num2;
   num2 = temp;
}

int main(int argc, char **argv)
{
   int i = 10, j = 20;
   swapByVal(i, j);
   cout << i << "  " << j << endl;     // displays 10  20
   swapByRef(i, j);
   cout << i << "  " << j << endl;     // displays 20  10
}