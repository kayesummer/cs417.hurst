//
// File:    adjacencyMatrix.h
// Author: Kaylee Hurst
// Purpose:
// Implement the graph ADT using an adjacency matrix
// used code from this website: https://algodaily.com/lessons/implementing-graphs-edge-list-adjacency-list-adjacency-matrix/java
//
// pretend all of this is correct :/

#pragma once 
#include <vector>  
#include <algorithm>      
#include "graph.h"      //to inherit from the graph class

template <typename ValueType>
class AdjacencyMatrix : public Graph<ValueType>
{
    private: 
        ValueType matrix[][];
        int numVertices;
        //vector here

    public: 
    //constructors/destructor
    AdjacencyMatrix() : Graph<ValueType>() {};

    AdjacencyMatrix(const AdjacencyMatrix& other) : Graph<ValueType> ()
    {
        numVertices = other;
        matrix = new matrixptr[numVertices][numVertices];
    }

    ~AdjacencyMatrix() 
    {
        delete[][] matrixptr;
        matrixptr = nullptr;
    }

    //overload assignment operator
    AdjacencyMatrix& operator= (const AdjacencyMatrix &source)
    {
        numVertices = source;
        return *this;
    }
    
    // Assume that the class is templated by the type "ValueType"
    virtual bool adjacent(ValueType x, ValueType y) // is there a node from x to y
    {
        Edges edges = vertexMap.at(x);
        std::pair<ValueType,ValueType> *searchEdge = new pair<ValueType,ValueType>(x,y);
        typename Edges::const_iterator begin = edges.begin();
        typename Edges::const_iterator end = edges.end();
        auto pos = std::find_if(begin, end, [&](std::pair<ValueType, ValueType> const &b)
        {
            return b.first == searchEdge->//something here
        }
        );
        return (pos != end);
    }

    virtual vector<ValueType> neighbors(ValueType x) // Return a vector of neighbor nodes
    {
        std::vector<ValueType> *nodes = new vector<ValueType>();
        Edges edges = vertexMap.at(x);
        for (typename Edges :: const_iterator it = edges.begin(); it < edges.end(); ++it)
        {
            std::pair<ValueType,ValueType> e = *it;
            nodes->push_back(e.first); 
        }
        return *nodes;
    }

    virtual void addEdge(ValueType source, ValueType dest) //add an edge from source, to dest add dest if it isn't already in graph
    {
        matrix[source][dest] = true;
        matrix[dest][source] = true;
    }

    virtual void addNode(ValueType x) //Add x to graph
    {
        Edges emptyEdgeList;
        vertexMap[x] = emptyEdgeList;
    }

    virtual void deleteEdge(ValueType source, ValueType dest)
    {
        matrix[source][dest] = false;
        matrix[dest][source] = false;
    }

    virtual void deleteNode(ValueType node)
    {
        vertexMap[node].remove();
    }
};