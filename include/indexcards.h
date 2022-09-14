//
// File:    indexcard.h
// Author: Kaylee Hurst  
// Purpose: allow you enter and search a deck of index cards
// 

#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 

class IndexCard
{
    private: 
        int count = 0;
        std::vector<int> id;
        std::vector<std::string> keyword; 
        std::vector<std::string> description;

    public: 
    //default constructor
    IndexCard() {};

    //given keyword and description, adds a card with a unique id#
    int enterCard(std::string word, std::string desc)
    {
        srand(0);
        id.push_back(rand());
        keyword.push_back(word);
        description.push_back(desc);
        count++;

        return id[count]; //returns unique id#
    }

    //given unique id#, displays card information
    void searchCards(int number)
    {
        std::vector<int>::iterator it;  
        it = std::find(id.begin(), id.end(), number);  
        if(it != id.end())  
        {  
            std::cout << keyword[it - id.begin() + 1] <<"\n"; 
            std::cout << description[it - id.begin() + 1] << "\n";
        }  
        else 
        {
            std::cout << "Element does not exist.\n \n"; 
        }  
    }

};