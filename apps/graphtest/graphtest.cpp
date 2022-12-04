//
//  main.cpp
//  GraphTest
//
//  Created by Adam Lewis on 1/19/14.
//  Copyright (c) 2014 Adam Lewis. All rights reserved.
//

#include <iostream>
#include <string>
#include "Graph.h"
#include "AdjListGraph.h"
#include "AdjMatrixGraph.h"


void testCreateGraphOfInts(Graph<int> *g)
{
    g->addNode(0);
    g->addNode(1);
    g->addNode(2);
    g->addNode(3);
    
    g->addEdge(0,1);
    g->addEdge(0,2);
    g->addEdge(0,3);
    
    g->addEdge(1,0);
    g->addEdge(1,2);
    g->addEdge(1,3);
    
    g->addEdge(2,0);
    g->addEdge(2,1);
    g->addEdge(2,3);
    
    g->addEdge(3,0);
    g->addEdge(3,1);
    g->addEdge(3,2);
    
    g->deleteEdge(2,1);
    
    bool test1 = g->adjacent(2,0);
    bool test2 = g->adjacent(2,1);
    if (test1 && !test2)
    {
        cout << "test passed: adjacency" << endl;
    }
    else
    {
        cout << "test failed: adjacency<int>" << endl;
    }
    
    vector<int> n3 = g->neighbors(3);
    auto printer = [=] (int elem) {
        cout << elem << endl;
    };
    for_each(n3.begin(),
             n3.end(),
             printer);
}

void testCreateGraphOfStrings(Graph<string> *g)
{
    g->addNode("a");
    g->addNode("b");
    g->addNode("c");
    g->addNode("d");
    
    g->addEdge("a","b");
    g->addEdge("a","c");
    g->addEdge("a","d");
    
    g->addEdge("b","a");
    g->addEdge("b","c");
    g->addEdge("b","d");
    
    g->addEdge("c","a");
    g->addEdge("c","b");
    g->addEdge("c","d");
    
    g->addEdge("d","a");
    g->addEdge("d","b");
    g->addEdge("d","c");
    
    g->deleteEdge("a","d");
    g->deleteEdge("a","d");
    
    bool test1 = g->adjacent("b","a");
    bool test2 = g->adjacent("b","d");
    if (test1 && !test2)
    {
        cout << "test passed: adjacency" << endl;
    }
    else
    {
        cout << "test failed: adjacency<int>" << endl;
    }
    
    vector<string> n3 = g->neighbors("c");
    auto printer = [=] (string elem) {
        cout << elem << endl;
    };
    for_each(n3.begin(),
             n3.end(),
             printer);
}

int main(int argc, const char * argv[])
{
    std::cout << "Manually test Graph classes\n";
    // Test Adjacency Lists
    AdjListGraph<int> *alig = new AdjListGraph<int>();
    testCreateGraphOfInts(alig);
    AdjListGraph<string> *alsg = new AdjListGraph<string>();
    testCreateGraphOfStrings(alsg);
    
    // Test Adjacency Lists
    AdjMatrixGraph<int> *amig = new AdjMatrixGraph<int>();
    testCreateGraphOfInts(amig);
    AdjMatrixGraph<string> *amsg = new AdjMatrixGraph<string>();
    testCreateGraphOfStrings(amsg);
    
    return 0;
}
