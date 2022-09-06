//
// File:    asg1.cpp
// Author: Kaylee Hurst  
// Purpose:
// Given a directed graph, this program will check to see if a user-specified path from that graph contains a cycle
//

#include <iostream> 
#include "adjacencylist.h"
#include "graph.h"
#include <fstream>
using namespace std;

//function prototypes
bool readData();
bool doesItCycle(parameters);

//global variables..?


int main ()
{
    bool goodRead = readData();
    if (goodRead)
    {
        cout << "Enter cycle: \n";
        //cin statement..? for-loop..? 
        bool cycles = doesItCycle();
        if (cycles)
        {
            cout << "That path cycles!\n";
        }
        else 
        {
            cout << "That path does not cycle\n";
        }
       
    }
    else 
    {
        cout << "Error reading text file." << endl;
    }

    return 0;
}

bool readData()
{
    bool goodRead = true;
    ifstream inFile;
    string dataFile;

    cout << "File Name: \n";
    cin >> dataFile;

    inFile.open(dataFile);
    if (inFile.is_open())   //replace if statement with reading into graph**********************************************************************
    {
        inFile >> tempRow.taskNumber >> tempRow.status >> tempRow.description;
        while (!inFile.eof())
        {
            taskData.push_back(tempRow);
            inFile >> tempRow.taskNumber >> tempRow.status >> tempRow.description;
        }
        inFile.close();
    }
    else
    {
        cerr << "Error: Unable to open data file \n";
        goodRead = false;
    }

    return goodRead;
}

bool doesItCycle()
{
    bool cycles = true;


    return cycles;
}