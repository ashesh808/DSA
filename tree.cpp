// Including the required headers
#include <iostream>
using namespace std;

// This class represents the node of a tree
class Node
{
public:
    // Data memebers of a node are:
    //  1. Key : which is used for finding and updating each node will have a unique key
    //  2. Data : which is the actual value contained in the node
    //  3. Parent : This pointer will point to the parent of the node
    //  4. Left Child : This pointer will point to the left child node
    //  5. Right Child : This pointer will point to the right child node

    int key;
    int data;
    Node *parent;
    Node *leftChild;
    Node *rightChild;

    // Constructor methods
    Node();
    Node(int k, int d);
};

// This class to represent the data structure Tree
class Tree
{
public:
    Node *root;
    // Constructor functions
    Tree();
    Tree(Node *n);

    // Destructor function
    ~Tree();

    // Operation functions
    Node *nodeExists(int k);
    void insertNode(Node *n);
    void deleteNode(int k);
    void updateNode(int k, int d);
};

Node *Tree::nodeExists(int k)
{
    if (k == root->key)
    {
        return root;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    return 0;
}