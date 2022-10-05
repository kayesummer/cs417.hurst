//
// File:    airlines.cpp
// Author: Kaylee Hurst  
// Purpose: runs a simulation of airline queues 
// forgive me 
//

#include <iostream> 
#include <algorithm> 
#include <queue>
#include <string>
using namespace std; 

//function prototypes 
int maxSize (int, int);
void periodicPrint(string, bool);


int main ()
{
    queue<int> fPass;
    queue<int> bPass;
    queue<int> ePass;
    queue<int> fAgent;
    queue<int> bAgent;
    queue<int> eAgent;

    string first = "First";
    string business = "Business";
    string economy = "Economy";
    auto fMax = 0;
    auto bMax = 0;
    auto eMax = 0;
    auto fAverage = 0;
    auto bAverage = 0;
    auto eAverage = 0;
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
    auto fwait = 0;
    auto bwait = 0;
    auto ewait = 0;
    auto clock = 0;


    fAgent.push(1);
    bAgent.push(1);
    eAgent.push(1);
    srand(0); 

    while (clock != 0)
    {
        if (clock % 10 == 0)    //print every 10 minutes 
        {
            cout << "First Class Line: " << fPass.size() << endl;
            cout << "Business Class Line: " << bPass.size() << endl;
            cout << "Economy Class Line: " << ePass.size() << endl;
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
            fPass.push(1);
            fTotal++;
            fMax = maxSize(fPass.size(), fMax);
        }
        if (clock % brand == 0)
        {
            bPass.push(1);
            bTotal++;
            bMax = maxSize(bPass.size(), bMax);
        }
        if (clock % erand == 0)
        {
            ePass.push(1);
            eTotal++;
            eMax = maxSize(ePass.size(), eMax);
        }
        //service times
        fservice = rand() % 15 + 10;
        fwait += fservice;
        bservice = rand() % 12 + 6;
        bwait += bservice;
        eservice = rand() % 20 + 5;
        ewait += eservice;
        if (fAgent.size() == 1)
        {
            if (clock % fservice == 0)
            {
                fPass.pop();
            }
        }
        if (fAgent.size() > 1)
        {
            if (clock % (fservice / 2) == 0)
            {
                fPass.pop();
            }
        }
        if (bAgent.size() == 1)
        {
            if (clock % bservice == 0)
            {
                bPass.pop();
            }
        }
        if (bAgent.size() > 1)
        {
            if (clock % (bservice / 2) == 0)
            {
                bPass.pop();
            }
        }
        if (eAgent.size() == 1)
        {
            if (clock % eservice == 0)
            {
                ePass.pop();
            }
        }
        if (eAgent.size() > 1)
        {
            if (clock % (eservice / 2) == 0)
            {
                ePass.pop();
            }
        }

        //move agents according to rules 
        if (fPass.size() == 0 && bPass.size() > 0)
        {
            if (fAgent.size() == 0)
            {
                bAgent.push(1);
            }
            if (fAgent.size() > 0)
            {
                fAgent.pop();
                bAgent.push(1);
            }
            if (ePass.size() == 0)
            {
                eAssist = false;
            }
            if (ePass.size() > 0)
            {
                eAssist = true;
            }
            fAssist = true;
            bAssist = true;

        }
        if (fPass.size() == 0 && bPass.size() == 0)
        {
            if (fAgent.size() == 0)
            {
                bAgent.pop();    //remove firstAgent from business line
                eAgent.push(1);

            }
            if (fAgent.size() > 0)
            {
                fAgent.pop();
                eAgent.push(1);
            }
            fAssist = true;
            eAssist = true;
            bAssist = false;
        }
        if (bPass.size() == 0 && fPass.size() > 0)
        {
            if (bAgent.size() == 0)
            {
                fAgent.push(1);
            }
            if (bAgent.size() > 0)
            {
                bAgent.pop();
                fAgent.push(1);
            }
            if (ePass.size() == 0)
            {
                eAssist = false;
            }
            if (ePass.size() > 0)
            {
                eAssist = true;
            }
            fAssist = true;
            bAssist = true;
        }
        if (bPass.size() == 0 && fPass.size() == 0 && ePass.size() > 0)
        {
            if (bAgent.size() > 0)
            {
                bAgent.pop();
                eAgent.push(1);
            }
            if (bAgent.size() == 0 && fAgent.size() > 0)
            {
                fPass.pop();
                eAgent.push(1);
            }
            fAssist = false;
            bAssist = true;
            eAssist = true;

        }
        if (ePass.size() == 0 && fPass.size() > 0)
        {
            if (eAgent.size() > 0)
            {
                eAgent.pop();
                fAgent.push(1);
            }
            if (eAgent.size() == 0)
            {
                fAgent.push(1);
            }
            if (bPass.size() == 0)
            {
                bAssist = false;
            }
            if (bPass.size() > 0)
            {
                bAssist = true;
            }
            eAssist = true;
            fAssist = true;

        }
        if (ePass.size() == 0 && fPass.size() == 0 && bPass.size() > 0)
        {
            if (eAgent.size() > 0)
            {
                eAgent.pop();
                bAgent.push(1);
            }
            if (eAgent.size() == 0 && fAgent.size() == 2)
            {
                fAgent.pop();
                bAgent.push(1);
            }
            eAssist = true;
            bAssist = true;
            fAssist = false; 
        }
        if (fPass.size() == 0 && bPass.size() == 0 && ePass.size() == 0)
        {
            fAssist = false; 
            bAssist = false;
            eAssist = false; 
            if (fAgent.size() == 0)
            {
                fAgent.push(1);
            }
            if (fAgent.size() > 1)
            {
                while (fAgent.size() != 1)
                {
                    fAgent.pop();
                }
            }
            if (bAgent.size() == 0)
            {
                bAgent.push(1);
            }
            if (bAgent.size() > 1)
            {
                while (bAgent.size() != 1)
                {
                    bAgent.pop();
                }
            }
            if (eAgent.size() == 0)
            {
                eAgent.push(1);
            }
            if (eAgent.size() > 1)
            {
                while (eAgent.size() != 1)
                {
                    eAgent.pop();
                }
            }
        }
        if (fPass.size() > 0 && bPass.size() > 0 && ePass.size() > 0)
        {
            fAssist = true;
            bAssist = true;
            eAssist = true;
                        if (fAgent.size() == 0)
            {
                fAgent.push(1);
            }
            if (fAgent.size() > 1)
            {
                while (fAgent.size() != 1)
                {
                    fAgent.pop();
                }
            }
            if (bAgent.size() == 0)
            {
                bAgent.push(1);
            }
            if (bAgent.size() > 1)
            {
                while (bAgent.size() != 1)
                {
                    bAgent.pop();
                }
            }
            if (eAgent.size() == 0)
            {
                eAgent.push(1);
            }
            if (eAgent.size() > 1)
            {
                while (eAgent.size() != 1)
                {
                    eAgent.pop();
                }
            }
        }
        clock++;

    }

    fAverage = fwait / fTotal;
    bAverage = bwait / bTotal;
    eAverage = ewait / eTotal;

    cout << "Class:\tAverage Line Length:\tMax Line Length:\tAverage Wait Time:\tAverage Service Time:\n";
    cout << "First Class:\t" << fAverage << "\t" << fMax << "\t" << fAverage << "\t" << fAverage << endl;
    cout << "Business Class:\t" << bAverage << "\t" << bMax << "\t" << bAverage << "\t" << bAverage << endl;
    cout << "Economy Class:\t" << eAverage << "\t" << eMax << "\t" << eAverage << "\t" << eAverage << endl;

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