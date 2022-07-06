// Including the required headers
#include <iostream>
using namespace std;

// This class represents the node of a graph
class Node
{
public:
    // Data memebers of a node are:
    //  1. Key : which is used for finding and updating each node will have a unique key
    //  2. Data : which is the actual value contained in the node
    int key;
    int data;

    // Constructor methods
    Node();
    Node(int k, int d);
};

// This class to represent the data structure Graph
class Graph
{
public:
    // Head and Tail pointers
    Node *head;
    Node *tail;

    // Constructor functions
    Graph();
    Graph(Node *n);

    // Destructor function
    ~Graph();

    // Operation functions
    Node *nodeExists(int k);
    void prependNode(Node *n);
    void appendNode(Node *n);
    void insertNodeAfter(int k, Node *n);
    void deleteNode(int k);
    void updateNode(int k, int d);
};

// Default constructor
Node::Node()
{
    key = 0;
    data = 0;
}

// Parameterised Constructor (Function overloading)
Node::Node(int k, int d)
{
    key = k;
    data = d;
}
// Default constructor
Graph::Graph()
{
    head = NULL;
    tail = NULL;
}

// Parameterised Constructor (Function overloading)
Graph::Graph(Node *n)
{
    head = n;
    tail = n;
}

int main()
{
    return 0;
}