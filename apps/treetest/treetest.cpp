//
// File:    treetest.cpp
// Author: Kaylee Hurst
// Purpose:
// constructs a BST with 1000 random numbers & then searches for 100 random numbers in the tree
//

//libraries
#include <iostream> 
#include "tree.h"   //to use tree ADT
using namespace std;

//function prototypes 
void fillTree();
bool searchTree(int);

//global variables 
Tree<int> bst;

int main ()
{
    const auto TESTSIZE = 100;
    int testArray[TESTSIZE];
    int value;
    srand(0);

    fillTree();

    for (auto count = 0; count < TESTSIZE; count++)
    {
        value = rand() % TESTSIZE;
        bool found = searchTree(value);

        if (found)
        {
            cout << value << " is in the tree.\n";
        }
        else //!found
        {
            cout << value << " is not in the tree\n";
        }
    }

    return 0;
}

void fillTree()
{
    const auto SIZE = 1000;
    srand(0);

    for (auto count = 0; count < SIZE; count++)
    {
        bst.insert(rand() % SIZE);
    }
}

bool searchTree(int value)
{
    bool found = bst.member(value);

    return found;
}