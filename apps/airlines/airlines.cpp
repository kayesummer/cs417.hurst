//
// File:    airlines.cpp
// Author: Kaylee Hurst  
// Purpose: runs a simulation of airline queues 
//

#include <iostream> 
#include <chrono> 
#include <algorithm> 
#include <queue>
#include <string>
using namespace std; 

//function prototypes 
int maxSize (int, int);
void periodicPrint(string, bool);


int main ()
{
    queue<int> firstPass;
    queue<int> businessPass;
    queue<int> economyPass;
    queue<int> firstAgent;
    queue<int> businessAgent;
    queue<int> economyAgent;

    string first = "First";
    string business = "Business";
    string economy = "Economy";
    auto firstCount = 0;
    auto businessCount = 0;
    auto economyCount = 0;
    auto firstMax = 0;
    auto businessMax = 0;
    auto economyMax = 0;
    auto firstAverage = 0;
    auto businessAverage = 0;
    auto economyAverage = 0;
    auto fAssist = false;
    auto bAssist = false;
    auto eAssist = false;
    auto fTotal = 0;
    auto bTotal = 0;
    auto eTotal = 0;
    auto frand = 0;
    auto brand = 0;
    auto erand = 0;
    auto fservice = 0;
    auto bservice = 0;
    auto eservice = 0;


    firstAgent.push(1);
    businessAgent.push(1);
    economyAgent.push(1);
    srand(0);   //rand() % 3 + 1, rand() % 15 + 1, rand() % 30 + 1, rand() % 10 + 5, rand() % 12 + 6, rand() % 20 + 5

    //start clock
    while (clock % 720 != 0)
    {
        if (clock % 10 == 0)    //print every 10 minutes 
        {
            cout << "First Class Line: " << firstPass.size() << endl;
            cout << "Business Class Line: " << businessPass.size() << endl;
            cout << "Economy Class Line: " << economyPass.size() << endl;
            periodicPrint(first, fAssist);
            periodicPrint(business, bAssist);
            periodicPrint(economy, eAssist);

            cout << endl;
        }
        //customer arrival rates
        frand = rand() % 30 + 1;
        brand = rand() % 15 + 1;
        erand = rand() % 3 + 1;
        if (clock % frand == 0)
        {
            firstPass.push(1);
            fTotal++;
            firstMax = maxSize(firstPass.size(), firstMax);
        }
        if (clock % brand == 0)
        {
            businessPass.push(1);
            bTotal++;
            businessMax = maxSize(businessPass.size(), businessMax);
        }
        if (clock % erand == 0)
        {
            economyPass.push(1);
            eTotal++;
            economyMax = maxSize(economyPass.size(), economyMax);
        }
        //service times
        fservice = rand() % 15 + 10;
        bservice = rand() % 12 + 6;
        eservice = rand() % 20 + 5;
        if (clock % fservice == 0)
        {
            firstPass.pop();
        }
        if (clock % bservice == 0)
        {
            businessPass.pop();
        }
        if (clock % eservice == 0)
        {
            economyPass.pop();
        }

        //move agents according to rules 
        if (firstPass.size() == 0 && businessClass.size() > 0)
        {
            if (firstAgent.size() == 0)
            {
                businessAgent.push(1);
                //change processing times
            }
            if (firstAgent.size() > 0)
            {
                firstAgent.pop();
                businessAgent.push(1);
                //change processing time
            }
            if (economyPass.size() == 0)
            {
                eAssist = false;
            }
            if (economyPass.size() > 0)
            {
                eAssist = true;
            }
            fAssist = true;
            bAssist = true;

        }
        if (firstPass.size() == 0 && businessPass.size() == 0)
        {
            if (firstAgent.size() == 0)
            {
                businessAgent.pop();    //remove firstAgent from business line
                economyAgent.push(1);
                //change processing time

            }
            if (firstAgent.size() > 0)
            {
                firstAgent.pop();
                economyAgent.push(1);
                //change processing time
            }
            fAssist = true;
            eAssist = true;
            bAssist = false;
        }
        if (businessPass.size() == 0 && firstPass.size() > 0)
        {
            if (businessAgent.size() == 0)
            {
                firstAgent.push(1);
                //change processing time
            }
            if (businessAgent.size() > 0)
            {
                businessAgent.pop();
                firstAgent.push(1);
                //change processing time
            }
            if (economyPass.size() == 0)
            {
                eAssist = false;
            }
            if (economyPass.size() > 0)
            {
                eAssist = true;
            }
            fAssist = true;
            bAssist = true;
        }
        if (businessPass.size() == 0 && firstPass.size() == 0 && economyPass.size > 0)
        {
            if (businessAgent.size > 0)
            {
                businessAgent.pop();
                economyAgent.push(1);
                //change processing time
            }
            if (businessAgent.size() == 0 && firstAgent.size() > 0)
            {
                firstPass.pop();
                economyAgent.push(1);
                //change processing time
            }
            fAssist = false;
            bAssist = true;
            eAssist = true;

        }
        if (economyPass.size() == 0 && firstPass.size() > 0)
        {
            if (economyAgent.size() > 0)
            {
                economyAgent.pop();
                firstAgent.push(1);
                //change processing time
            }
            if (economyAgent.size() == 0)
            {
                firstAgent.push(1);
                //change processing time
            }
            if (businessPass.size() == 0)
            {
                bAssist = false;
            }
            if (businessPass.size() > 0)
            {
                bAssist = true;
            }
            eAssist = true;
            fAssist = true;

        }
        if (economyPass.size() == 0 && firstPass.size() == 0 && businessPass.size() > 0)
        {
            if (economyAgent.size() > 0)
            {
                economyAgent.pop();
                businessAgent.push(1);
            }
            if (economyAgent.size() == 0 && firstAgent.size() == 2)
            {
                firstAgent.pop();
                businessAgent.push(1);
                //change processing time
            }
            eAssist = true;
            bAssist = true;
            fAssist = false; 
        }
        if (firstPass.size() == 0 && businessPass.size() == 0 && economyPass.size() == 0)
        {
            fAssist = false; 
            bAssist = false;
            eAssist = false; 
            if (firstAgent.size() == 0)
            {
                firstAgent.push(1);
            }
            if (firstAgent.size() > 1)
            {
                while (firstAgent.size() != 1)
                {
                    firstAgent.pop();
                }
            }
            if (businessAgent.size() == 0)
            {
                businessAgent.push(1);
            }
            if (businessAgent.size() > 1)
            {
                while (businessAgent.size() != 1)
                {
                    businessAgent.pop();
                }
            }
            if (economyAgent.size() == 0)
            {
                economyAgent.push(1);
            }
            if (economyAgent.size() > 1)
            {
                while (economyAgent.size() != 1)
                {
                    economyAgent.pop();
                }
            }
        }
        if (firstPass.size() > 0 && businessPass.size > 0 && economyPass.size() > 0)
        {
            fAssist = true;
            bAssist = true;
            eAssist = true;
                        if (firstAgent.size() == 0)
            {
                firstAgent.push(1);
            }
            if (firstAgent.size() > 1)
            {
                while (firstAgent.size() != 1)
                {
                    firstAgent.pop();
                }
            }
            if (businessAgent.size() == 0)
            {
                businessAgent.push(1);
            }
            if (businessAgent.size() > 1)
            {
                while (businessAgent.size() != 1)
                {
                    businessAgent.pop();
                }
            }
            if (economyAgent.size() == 0)
            {
                economyAgent.push(1);
            }
            if (economyAgent.size() > 1)
            {
                while (economyAgent.size() != 1)
                {
                    economyAgent.pop();
                }
            }
        }

    }

    //compute here? 

    cout << "Class:\tAverage Line Length:\tMax Line Length:\tAverage Wait Time:\tAverage Service Time:\n";
    cout << "First Class:\t" << firstAverage << "\t" << firstMax << "\t" << //wait times here
    cout << "Business Class:\t" << businessAverage << "\t" << businessMax << "\t" << //wait times here 
    cout << "Economy Class:\t" << economyAverage << "\t" << economyMax << "\t" << //wait times here

    return 0;
}

int maxSize (int look, int max)
{
    if (look > max)
    {
        max = look;
    }
    return max;
}

void periodicPrint(string name, bool assist)
{
    if (assist)
    {
        cout << name << " Class Agent is assisting a customer\n";
    }
    if (!assist)
    {
        cout <<name << " Class Agent is not assisting a customer\n";
    }
}