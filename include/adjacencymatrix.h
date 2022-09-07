//
// File:    adjacencyMatrix.h
// Author: Kaylee Hurst
// Purpose:
// Implement the graph ADT using an adjacency matrix
// used code from this website: https://www.programiz.com/dsa/graph-adjacency-matrix & https://www.includehelp.com/ds/addition-and-deletion-of-nodes-and-edges-in-a-graph-using-adjacency-matrix.aspx
//
// pretend all of this is correct :/
//

#pragma once 
#include <iostream>
#include <vector>  
#include <algorithm>      
#include "graph.h"      //to inherit from the graph class

template <typename ValueType>
class AdjacencyMatrix : public Graph<ValueType>
{
    private: 
        ValueType** matrix;
        int numVertices;
        vector<ValueType> info;

    public: 
    //constructors/destructor
    AdjacencyMatrix() : Graph<ValueType>() {};

    AdjacencyMatrix(const AdjacencyMatrix& other) : Graph<ValueType> ()
    {
        numVertices = other;
        matrix = new ValueType*[numVertices];
        for (int count = 0; count < numVertices; count++)
        {
            matrix[count] = new ValueType[numVertices];
            for (int counter = 0; counter < numVertices; counter++)
            {
                matrix[count][counter] = false;
            }
        }
    }

    ~AdjacencyMatrix() 
    {
        for (int count = 0; count < numVertices; count++)
        {
            delete[] matrix[count];
        }
        delete[] matrix;
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
        numVertices++;  
        for (int count = 0; count < numVertices; count++)
        {
            matrix[count][numVertices] = x;
            matrix[numVertices][count] = x;
        }
    }

    virtual void deleteEdge(ValueType source, ValueType dest)
    {
        matrix[source][dest] = false;
        matrix[dest][source] = false;
    }

    virtual void deleteNode(ValueType node)
    {
        if (numVertices == 0)
        {
            std::cout << "This graph is empty\n"; 
            return;
        }
        if (node > numVertices)
        {
            std::cout << "Node not in graph\n";
            return;
        }
        for (int count = 0; count < numVertices - 1; count++)
        {
            for (int counter = 0; counter < numVertices; counter++)
            {
                matrix[count][counter] = matrix[count][counter + 1];
                matrix[counter][count] = matrix[counter + 1][count];
            }
        }
        numVertices--;
    }
};