/*
* File: Graph.cpp
* Course: CS216-002
* Project: Lab 12
* Purpose: Declaration of Graph class
*          This class represents an undirected Graph (no weight on each edge)
*          using adjacent map representation
*          It contains one private data memeber: adjMap
*          which represents the mapping from a Vertex, say u (key) to a set of vertices (value) which directly connect to u
* Editor: Anthony Wang 
*/
#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.h"
#include <queue>
#include <set>

using namespace std;

template <typename T>
Graph<T>::Graph(){
    // default constructor
    adjMap = {};
}

template <typename T>
bool Graph<T>::hasEdge(const T& v1, const T& v2) const{
    // if v1 dose not appear in adjMap, return false
    if(adjMap.find(v1) == adjMap.end()){
        return false;
    }
    // else, return (is v2 a adjacent of v1)
    return adjMap.at(v1).find(v2) != adjMap.at(v1).end();
}

template <typename T>
void Graph<T>::addEdge(const T& v1, const T& v2){
    // insert v1 and v2 to each other's pair
    adjMap[v1].insert(v1);
    adjMap[v2].insert(v2);
}

int Graph<T>::BFS(const T& s, const T& t, map<T, int>& distance, map<T, T>& go_through) const{
    // return -2 if least one of them are not in adjMap
    if(adjMap.find(s) == adjMap.end() || adjMap.find(t) == adjMap.end()){return INVALID_VERTEX;}

    // return distance=0 if they are same
    if(s == t){return 0;}

    // set distance of all vertex to -1(unvisited)
    for(auto vertex:adjMap){
        distance[vertex.first] = -1;
    }
    
    queue<T> q;
    distance[s] = 0; // set distance of itself to 0
    go_through[s] = s;
    q.push(s);
    T current = s;
    while(!q.empty() && current != t){
        // set current to first vertex in queue
        current = q.front();
        q.pop();
        // loop from all unvisited adjacent of current, add them to queue
        // add path of w -> current to go_through, distance of w = current+1
        for(T& w:adjMap.at(current)){
            if(distance[w] == -1){
                distance[w] = distance[current]+1;
                go_through[w] = current;
                q.push(w);
            }
        }
    }
    // return NOPATH if distance of t was not updated
    if(distance[t] == -1){
        return NOPATH;
    }
    // else, return distance of t to s
    return distance[t];
}

#endif
