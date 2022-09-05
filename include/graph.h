//
// File:    graph.h
// Author: Kaylee Hurst  
// Purpose:
// Implement a pure virtual base class for a graph to be inherited by adjacencylist.h and adjacencymatrix.h
//

#pragma once
#include <vector>

template <typename ValueType> 
class Graph
{
    public:
        //constructors and destructor
        Graph() {};
        Graph(vector<valueType> nodes, vector<std::pair<valueType,valueType>> edges) {};
        virtual ~Graph() {};

        virtual bool adjacent(ValueType x, ValueType y) = 0; 
        virtual vector<ValueType> neighbors(ValueType x) = 0; 
        virtual void addEdge(ValueType source, ValueType dest) = 0; 
        virtual void addNode(ValueType x) = 0; 
        virtual void deleteEdge(ValueType source, ValueType dest) = 0;
        virtual void deleteNode(ValueType node) = 0;

};