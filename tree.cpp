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
    Node *left;
    Node *right;

    // Constructor methods
    Node();
    Node(int k, int d);
};

Node::Node()
{
    data = 0;
    parent = NULL;
    left = right = NULL;
}
Node::Node(int k, int d)
{
    key = k;
    data = d;
    left = right = NULL;
}

// This class to represent the data structure Tree
class Tree
{
public:
    Node *root;
    // Constructor functions
    Tree();
    Tree(Node *n);

    // Operation functions
    void insertNode(Node *n);
    void deleteNode(int k);
    void updateNode(int k, int d);
    void print();
};

//Default constructor
Tree::Tree()
{
    root = NULL;
}

Tree::Tree(Node *n)
{
    root = n;
}

// Recursive function to return
int depthFirstSearch(Node *rootNode, int k)
{
    if (rootNode->key == k || rootNode == NULL)
    {
        return rootNode->data;
    }
    // Recurring on left subtree
    depthFirstSearch(rootNode->left, k);
    // Recurring on right subtree
    depthFirstSearch(rootNode->right, k);
}

void Tree::insertNode(Node *n)
{
    if (root == NULL)
    {
        root = n;
    }
    else
    {
    }
}
void Tree::print()
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        cout << ptr->data << "\n";
        ptr = ptr->left;
    }
}

/* Given a binary tree, print its nodes in inorder*/
int findNode(Node* node, int k)
{
    if (node == NULL )
    {
        return  -1;
    }
    findNode(node->left, k); 
    
     if (node->key == k)
    {
        return  node->data;
    }
    /* now recur on right child */
    findNode(node->right, k);
}
 
int main()
{
    // Creating new nodes
    Node *root = new Node(1, 9);
    // Adding nodes as children
    root->left =  new Node(2, 10);
    root->right = new Node(3, 16);
    cout << "\n";

    //printing the value of the node with the key 2
   cout << findNode(root, 2);

    return 0;
}