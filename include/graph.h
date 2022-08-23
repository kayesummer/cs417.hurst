//
// File:    graph.h
// Author: Kaylee Hurst  
// Purpose:
// Implement a virtual base class for a graph to be inherited by adjacencylist.h and adjacencymatrix.h
//

template <typename ValueType> 
class Graph
{
    private: 

    public:
        // Assume that the class is templated by the type "ValueType"
        virtual bool adjacent(ValueType x, ValueType y) = 0; // is there a node from x to y
        virtual vector<ValueType> neighbors(ValueType x) = 0; // Return a vector of neighbor nodes
        virtual void addEdge(ValueType source, ValueType dest) = 0; //add an edge from source, to dest
                                                        // add dest if it isn't already in graph
        virtual void addNode(ValueType x) = 0;  //Add x to graph
        virtual void deleteEdge(ValueType source, ValueType dest) = 0;
        virtual void deleteNode(ValueType node) = 0;

};