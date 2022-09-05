//
// File:    adjacencylist.h
// Author: Kaylee Hurst  
// Purpose:
// Implement the graph ADT using an adjacency list
//

#pragma once 
#include <vector>   
#include <list>     
#include "graph.h"      //to inherit from the graph class

template <typename ValueType>
class AdjacencyList : public Graph<ValueType>
{
    private: 

    public: 
    // Assume that the class is templated by the type "ValueType"
    virtual bool adjacent(ValueType x, ValueType y) // is there a node from x to y
    {

    }
    virtual vector<ValueType> neighbors(ValueType x) // Return a vector of neighbor nodes
    {

    }
    virtual void addEdge(ValueType source, ValueType dest); //add an edge from source, to dest add dest if it isn't already in graph
    {

    }
    virtual void addNode(ValueType x) //Add x to graph
    {

    }
    virtual void deleteEdge(ValueType source, ValueType dest)
    {

    }
    virtual void deleteNode(ValueType node)
    {
        
    }
};