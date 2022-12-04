//
//  AdjListGraph.h
//  GraphTest
//
//  Created by Adam Lewis on 1/27/14.
//  Copyright (c) 2014 Adam Lewis. All rights reserved.
//

#pragma once
#include "Graph.h"
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

template <class N>
class AdjListGraph: public Graph<N>  {
private:
    using Edges = list<pair<N, N>>;
    map<N,Edges> vertexMap;
public:
    // Default constuctor, create empty
    AdjListGraph() : Graph<N>() { };

    
    // Get the vertex map from the Graph we're copying
    AdjListGraph(const AdjListGraph& other) : Graph<N>()
    {
        vertexMap = other->vertexMap;
    }
    
    // Don't forget to overload the assignment operator
    AdjListGraph& operator= (const AdjListGraph &source)
    {
        vertexMap = source->vertexMap;
        return *this;
    }
    
    // Add the nodes in the list to graph
    AdjListGraph(vector<N> newNodes, vector<pair<N,N>> newEdges) :
        Graph<N>(newNodes, newEdges)
    {
        for (auto it = newNodes.begin();
             it < newNodes.end();
             ++it)
        {
            N node = *it;
            vertexMap[node].push_back(newEdges);
        }
    }
    
    
    // Clean up behind ourselves
    ~AdjListGraph() { }
    
    virtual bool adjacent(N x, N y){
        Edges edges = vertexMap.at(x);
        pair<N,N> *searchEdge = new pair<N,N>(x,y);
        typename Edges::const_iterator begin = edges.begin();
        typename Edges::const_iterator end = edges.end();
        auto pos = std::find_if(begin,end,
                                [&](pair<N,N> const &b) {
                                    return b.first == searchEdge->first;
                                });
      
        return (pos != end);
    }

    virtual vector<N> neighbors(N x) {
        vector<N> *nodes = new vector<N>();
        Edges edges = vertexMap.at(x);
        for (typename Edges :: const_iterator it = edges.begin(); it != edges.end(); it++) {
            pair<N,N> e = *it;
            nodes->push_back(e.first);
        }
        return *nodes;
    }

    virtual void addNode(N node){
        Edges emptyEdgeList;
        vertexMap[node] = emptyEdgeList;
    }
    
    virtual void addEdge(N x, N y){
        pair<N,N> forwardEdge = make_pair(x,y);
        pair<N,N> backwardEdge = make_pair(y,x);
        vertexMap[x].push_back(forwardEdge);
        vertexMap[y].push_back(backwardEdge);
    }
    
    virtual void deleteEdge(N x, N y){
        pair<N,N> forwardEdge = make_pair(x,y);
        pair<N,N> backwardEdge = make_pair(y,x);
        vertexMap[x].remove(forwardEdge);
        vertexMap[y].remove(backwardEdge);
    }
    

};
