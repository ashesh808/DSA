// Including the required headers
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
using namespace std;

// Class Edge
class Edge
{
public:
    int DestinationVertexID;
    int weight;
    Edge();
    Edge(int DestinationVertexID, int weight);
    void setEdge(int DestinationVertexID, int weight);
    void setDestinationVertexID(int DestinationVertexID);
    void setWeight(int weight);
    int getDestinationVertexID();
    int getWeight();
};
// Default constructor for edge
Edge::Edge()
{
    DestinationVertexID = 0;
    weight = 0;
}
// Parameterised constructor for edge
Edge::Edge(int DestinationVertexID, int weight)
{
    this->DestinationVertexID = DestinationVertexID;
    this->weight = weight;
}
// Setter for edge
void Edge::setEdge(int DestinationVertexID, int weight)
{
    this->DestinationVertexID = DestinationVertexID;
    this->weight = weight;
}
// Setter for destination vertex ID
void Edge::setDestinationVertexID(int DestinationVertexID)
{
    this->DestinationVertexID = DestinationVertexID;
}
// Setter for weight
void Edge::setWeight(int weight)
{
    this->weight = weight;
}
// Getter for destination vertex ID
int Edge::getDestinationVertexID()
{
    return DestinationVertexID;
}
// Getter for weight
int Edge::getWeight()
{
    return weight;
}

class Vertex
{
public:
    // Data members
    int state_id;
    string state_name;
    list<Edge> edgeList;
    // Methods
    Vertex();
    Vertex(int state_id, string state_name);
    void setVertex(int state_id, string state_name);
    void setStateID(int state_id);
    void setStateName(string state_name);
    void addEdge(Edge edge);
    list<Edge> getEdgeList();
};
// Default constructor for vertex
Vertex::Vertex()
{
    state_id = 0;
    state_name = "";
}
// Parameterised constructor for vertex
Vertex::Vertex(int state_id, string state_name)
{
    this->state_id = state_id;
    this->state_name = state_name;
}
// Setter for vertex
void Vertex::setVertex(int state_id, string state_name)
{
    this->state_id = state_id;
    this->state_name = state_name;
}
// Setter for state ID
void Vertex::setStateID(int state_id)
{
    this->state_id = state_id;
}
// Setter for state name
void Vertex::setStateName(string state_name)
{
    this->state_name = state_name;
}
// Add edge to vertex
void Vertex::addEdge(Edge edge)
{
    edgeList.push_back(edge);
}

// Getter for edge list
list<Edge> Vertex::getEdgeList()
{
    return edgeList;
}

class Graph
{
public:
    vector<Vertex> vertices;
    // All graph operations
    bool checkIfVertexExists(int vid);
    void addVertex(Vertex *newVertex);
};

//Fuction to check if a vertex exists with a certian id
bool Graph::checkIfVertexExists(int vid)
{

}

void Graph::addVertex(Vertex *newVertex)
{
}

int main()
{

    return 0;
}