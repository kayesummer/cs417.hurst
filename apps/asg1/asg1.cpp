//
// File:    asg1.cpp
// Author: Kaylee Hurst  
// Purpose:
// Given a directed graph, this program will check to see if a user-specified path from that graph contains a cycle
// plz have mercy on me i beg of you
//

#include <iostream> 
#include <vector>
#include "adjacencylist.h"
#include "graph.h"
#include <fstream>
using namespace std;

//function prototypes
bool readData();
bool doesItCycle(parameters);

//global variables
AdjacencyList<int> graphTest;
vector<int> cycle;

int main ()
{
    auto length = 0;
    auto input = 0;
    bool goodRead = readData();
    if (goodRead)
    {
        cout << "How long is your cycle?\n";
        cin >> length;
        cout << "Enter cycle & enter 9999 when done: \n";
        while ((cin >> input) && input != 9999)
        {
            cycle.pushback(input);
        }
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
    auto goodRead = true;
    ifstream inFile;
    string dataFile;
    string data;

    cout << "File Name: \n";
    cin >> dataFile;

    inFile.open(dataFile);
    if (inFile.is_open())  
    {
        while (getline(inFile, data))
        {
            graphTest.addNode(data[0]);
            for (int count = 1; count < data.length(); count++)
            {
                graphTest.addEdge(data[count]);
            }
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
    auto cycles = true;

    for (vector<int>::iterator j = cycle.begin(); j != cycle.end(); ++j)
    {
       if ( !graphTest.adjacent(cycle[j]) )
       {
            cycles = false;
       }
    }

    return cycles;
}