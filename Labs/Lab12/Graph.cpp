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


#include "Graph.h"
#include <queue>
#include <set>

using namespace std;

Graph::Graph(){
    // default constructor
    adjMap = {};
}

bool Graph::hasEdge(char v& v1, char v& v2) const{
    // if v dose not appear in adjMap, return false
    if(adjMap.find(v1) == adjMap.end()){
        return false;
    }
    // else, return (is w a adjacent of v)
    return adjMap.at(v1).find(v2) != adjMap.at(v1).end();
}

void Graph::addEdge(char v& v1, char v& v2){
    // insert v and w to each other's pair
    adjMap[v].insert(v1);
    adjMap[w].insert(v2);
}

int Graph::BFS(char v& s, char v& t, map<char, int>& distance, map<char, char>& go_through) const{
    // return -2 if least one of them are not in adjMap
    if(adjMap.find(s) == adjMap.end() || adjMap.find(t) == adjMap.end()){return INVALID_VERTEX;}

    // return distance=0 if they are same
    if(s == t){return 0;}

    // set distance of all vertex to -1(unvisited)
    for(auto vertex:adjMap){
        distance[vertex.first] = -1;
    }
    
    queue<char> q;
    distance[s] = 0; // set distance of itself to 0
    go_through[s] = s;
    q.push(s);
    char current = s;
    while(!q.empty() && current != t){
        // set current to first vertex in queue
        current = q.front();
        q.pop();
        // loop from all unvisited adjacent of current, add them to queue
        // add path of w -> current to go_through, distance of w = current+1
        for(char w:adjMap.at(current)){
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

