//
// File:    graph.h
// Author: Kaylee Hurst  
// Purpose:
// Implement a pure virtual base class for a graph to be inherited by adjacencylist.h and adjacencymatrix.h
//

#include <vector>

template <typename ValueType> 
class Graph
{
    public:

        //add constructor/destructor hehe

        virtual bool adjacent(ValueType x, ValueType y) = 0; 
        virtual vector<ValueType> neighbors(ValueType x) = 0; 
        virtual void addEdge(ValueType source, ValueType dest) = 0; 
        virtual void addNode(ValueType x) = 0; 
        virtual void deleteEdge(ValueType source, ValueType dest) = 0;
        virtual void deleteNode(ValueType node) = 0;

};