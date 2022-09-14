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
        struct Information
        {
            int id; 
            std::string keyword; 
            std::string description;
        };
        std::vector<Information> indexCards;

    public: 
    //default constructor
    IndexCard() {};

    //given keyword and description, adds a card with a unique id#
    int enterCard(std::string word, std::string desc)
    {
        srand(0);
        Information temp;
        temp.id = rand();
        temp.keyword = word;
        temp.description = desc;
        indexCards.push_back(temp);
        count++;

        return indexCards[count].id; //returns unique id#
    }

    //given unique id#, displays card information
    int searchCards(int id)
    {
        std::vector<int>::iterator it;  
        it = std::find(indexCards.begin(), indexCards.end(), id);  
        if(it != indexCards.end())  
        {  
            std::cout << indexCards[it - indexCards.begin() + 1].keyword <<"\n"; 
            std::cout << indexCards[it - indexCards.begin() + 1].description << "\n";
        }  
        else  
            std::cout<<"Element does not exist.\n \n";  
        return 0; 
    }



};