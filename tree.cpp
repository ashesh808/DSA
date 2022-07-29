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
    Node* depthFirstSearch(Node* rootNode, int k);
    void insertNode(Node *n);
    void deleteNode(int k);
    void updateNode(int k, int d);
    void print();
};

Tree::Tree()
{
    root = NULL;
}

Tree::Tree(Node *n)
{
    root = n;
}


//Recursive function to return 
Node *Tree::depthFirstSearch(Node* rootNode, int k)
{
    if(rootNode->key == k)
    {
        return root;
    }
    else
    {
        //Recurring on left subtree
        depthFirstSearch(rootNode->left, k);
        //Recurring on right subtree
        depthFirstSearch(rootNode->right, k);  
    }
    return NULL;
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
    Node* ptr = root;
    while (ptr != NULL)
    {
        cout << ptr->data << "\n";
        ptr = ptr->left;
    }
    
}
int main()
{
    Node* root = new Node(1,9);
    Node* leftChild = new Node(2,10);
    Node* rightChild = new Node(3,16);
    root->left = leftChild;
    root->right = rightChild;
    Tree t1(root);
    Node* search = t1.depthFirstSearch(root, 3);
    cout << search->data << "\n";
    return 0;
}