// Including the required headers
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int DestinationVertexID;
    int weight;
};

class Vertex
{
public:
    int state_id;
    string  state_name;
    list<Edge> edgeList;
};

class Graph
{
public:
    vector<Vertex> vertices;

    void addVertex(int id, string name)
    {
        Vertex v;
        v.state_id = id;
        v.state_name = name;
        vertices.push_back(v);
    }
    Graph();
    void printGraph();

    //Search Algorithms
    void DFS(int src);
    void BFS(int src);
};


int main()
{
   
    return 0;
}