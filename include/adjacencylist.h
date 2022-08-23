//
// File:    adjacencylist.h
// Author: Kaylee Hurst  
// Purpose:
// Implement the graph ADT using an adjacency list
//

#include <vector>   //to use the vector ADT
#include <list>     //to use the list ADT 
#include "graph.h"      //to inherit from the graph class

template <typename ValueType>
class AdjacencyList
{
    private: 

    public: 
    // Assume that the class is templated by the type "ValueType"
    bool adjacent(ValueType x, ValueType y); // is there a node from x to y
    vector<ValueType> neighbors(ValueType x); // Return a vector of neighbor nodes
    void addEdge(ValueType source, ValueType dest); //add an edge from source, to dest
                                                    // add dest if it isn't already in graph
    void addNode(ValueType x); //Add x to graph
    void deleteEdge(ValueType source, ValueType dest);
    void deleteNode(ValueType node);
};