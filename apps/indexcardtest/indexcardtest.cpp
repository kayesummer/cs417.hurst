//
// File:    indexcardtest.cpp
// Author: Kaylee Hurst  
// Purpose: tests the indexcards.h class.
// 

#include "indexcards.h"
#include <iostream> 
#include <string>
using namespace std; 

int main ()
{
    IndexCard card;
    const auto COUNT = 3;
    int searchs[COUNT];
    string words[COUNT] = {"gouda", "munster", "swiss"};
    string defs[COUNT] = {"sweet, creamy, yellow cow's milk cheese originating from the Netherlands", 
                    "soft washed rind cheese made from milk produced by cows in France", 
                    "a yellow, medium-hard cheese that originated in Switzerland"};

    //enter 3 cheese cards
    for (auto i = 0; i < COUNT; i++)
    {
        searchs[i] = card.enterCard(words[i], defs[i]);
    }

    //search for the cards that do exist
    for (auto j = 0; j < COUNT; j++)
    {
        card.searchCards(searchs[j]);
    }

    //search random ID that doesn't exist
    card.searchCards(41687);

    return 0;
}