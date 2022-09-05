//
// File:    adjacencylist.h
// Author: Adam Lewis
// **Kaylee Hurst does not own the rights**
// Copyright (c) 2014 Adam Lewis. All rights reserved
// Purpose:
// Implement the graph ADT using an adjacency list
//

#pragma once 
#include <vector>  
#include <map>
#include <deque>
#include <algorithm> 
#include <list>     
#include "graph.h"      //to inherit from the graph class

template <typename ValueType>
class AdjacencyList : public Graph<ValueType>
{
    private: 
        using Edges = list<std::pair<ValueType,ValueType>>;
        map<ValueType,Edges> vertexMap;

    public: 
    //constructors/destructor
    AdjacencyList() : Graph<ValueType>() {};

    AdjacencyList(const AdjacencyList& other) : Graph<ValueType> ()
    {
        vertexMap = other->vertexMap;
    }

    //Add the nodes in the list to graph
    AdjacencyList(vector<ValueType> newNodes, vector<pair<ValueType,ValueType>> newEdges) : Graph<ValueType> (newNodes, newEdges)
    {
        for (auto it = newNodes.begin(); it < newNodes.end(); ++it)
        {
            ValueType node = *it; 
            vertexMap[node].pushback(newEdges);
        }
    }

    ~AdjacencyList() {};

    //overload assignment operator
    AdjacencyList& operator= (const AdjacencyList &source)
    {
        vertexMap = source->vertexMap;
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
        std::pair<ValueType,ValueType> forwardEdge = std::make_pair(source,dest);
        std::pair<ValueType,ValueType> backwardEdge = std::make_pair(dest,source);
        vertexMap[source].push_back(forwardEdge);
        vertexMap[dest].push_back(backwardEdge);
    }

    virtual void addNode(ValueType x) //Add x to graph
    {
        Edges emptyEdgeList;
        vertexMap[x] = emptyEdgeList;
    }

    virtual void deleteEdge(ValueType source, ValueType dest)
    {
        std::pair<ValueType,ValueType> forwardEdge = std::make_pair(source,dest);
        std::pair<ValueType,ValueType> backwardEdge = std::make_pair(dest,source);
        vertexMap[source].remove(forwardEdge);
        vertexMap[dest].remove(backwardEdge);
    }

    virtual void deleteNode(ValueType node)
    {
        vertexMap[node].remove();
    }
};