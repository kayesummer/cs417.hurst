//
// File:    organizedlist.cpp
// Author: Kaylee Hurst  
// Purpose:
// 
//

#include <list>
#include <iostream>
#include <algorithm>

template <typename T>
class OrganizedList
{
    public:
        //default constructor
        OrganizedList() {};

        void findAndMove(std::list<T>* things, t item)
        {
            std::list<T>::iterator it;
            it = std::find(things.begin(), things.end(), item);

            //check if iterator points to end or not
            if (it != things.end())
            {
                things.remove(item);
                things.push_front(item);
            }
            else
            {
                std::cout << item << " is not in the list\n";
            }
        }
};