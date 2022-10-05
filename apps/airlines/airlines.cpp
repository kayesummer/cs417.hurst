//
// File:    airlines.cpp
// Author: Kaylee Hurst  
// Purpose: runs a simulation of airline queues 
//

#include <iostream> 
#include <chrono> 
#include <algorithm> 
#include <utility> 
#include <vector> 
#include <string> 
#include <queue>
using namespace std; 


int main ()
{
    queue<int> firstPass;
    queue<int> businessPass;
    queue<int> economyPass;
    queue<int> firstAgent;
    queue<int> businessAgent;
    queue<int> economyAgent;

    auto firstCount = 0;
    auto businessCount = 0;
    auto economyCount = 0;
    auto firstMax = 0;
    auto businessMax = 0;
    auto economyMax = 0;
    auto firstAverage = 0;
    auto businessAverage = 0;
    auto economyAverage = 0;

    firstAgent.push(1);
    businessAgent.push(1);
    economyAgent.push(1);
    srand(0);   //rand() % 3 + 1, rand() % 15 + 1, rand() % 30 + 1, rand() % 10 + 5, rand() % 12 + 6, rand() % 20 + 5


    while (clock % 720 != 0)
    {
        if (clock % 10 == 0)
        {
            cout << "First Class Line: " << firstPass.size() << endl;
            cout << "Business Class Line: " << businessPass.size() << endl;
            cout << "Economy Class Line: " << economyPass.size() << endl;

            cout << endl;
        }
    }

    //compute here? 

    cout << "Class:\tAverage Line Length:\tMax Line Length:\tAverage Wait Time:\tAverage Service Time:\n";
    cout << "First Class:\t" << firstAverage << "\t" << firstMax << "\t" << //wait times here
    cout << "Business Class:\t" << businessAverage << "\t" << businessMax << "\t" << //wait times here 
    cout << "Economy Class:\t" << economyAverage << "\t" << economyMax << "\t" << //wait times here

    return 0;
}