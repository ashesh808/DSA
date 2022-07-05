#include <iostream>
using namespace std;

// This class represents the node of a linked list
class Node
{
public:
    // Data memebers of a node are:
    //  1. Key : which is used for finding and updating each node will have a unique key
    //  2. Data : which is the actual value contained in the node
    //  3. Next : This pointer will point to the next member of the linked list
    int key;
    int data;
    Node *next; // Pointer of the data type "Node"

    // Constructor methods
    Node();
    Node(int k, int d);
};
// Default constructor
Node::Node()
{
    key = 0;
    data = 0;
    next = NULL;
}
// Parameterised Constructor (Function overloading)
Node::Node(int k, int d)
{
    key = k;
    data = d;
}

// class to doubly link the nodes
class CircularLinkedList
{
public:
    // Head and Tail pointers
    Node *head;

    // Constructor functions
    CircularLinkedList();
    CircularLinkedList(Node *n);

    // Destructor function
    ~CircularLinkedList();

    // Operation functions
    Node *nodeExists(int k);
    void prependNode(Node *n);
    void appendNode(Node *n);
    void insertNodeAfter(int k, Node *n);
    void deleteNode(int k);
    void updateNode(int k, int d);

    // Method to print the members of the linked list
    void printList();
};

// Default constructor
CircularLinkedList::CircularLinkedList()
{
    head = NULL;
}
// Parameterised Constructor (Function overloading)
CircularLinkedList::CircularLinkedList(Node *n)
{
    head = n;
}
// Destructor function
CircularLinkedList::~CircularLinkedList()
{
    Node *temp = head;
    Node *temp2 = head;
    while (temp != NULL)
    {
        temp = temp->next;
        delete temp2;
        temp2 = temp;
    }
}
// Operation functions
Node *CircularLinkedList::nodeExists(int k)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->key == k)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void CircularLinkedList::prependNode(Node *n)
{
    n->next = head;
    head = n;
}
void CircularLinkedList::appendNode(Node *n)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void CircularLinkedList::insertNodeAfter(int k, Node *n)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->key == k)
        {
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
}
void CircularLinkedList::deleteNode(int k)
{
    Node *temp = head;
    Node *temp2 = head;
    while (temp != NULL)
    {
        if (temp->key == k)
        {
            if (temp == head)
            {
                head = temp->next;
            }
            else
            {
                temp2->next = temp->next;
            }
            delete temp;
            return;
        }
        temp2 = temp;
        temp = temp->next;
    }
}
void CircularLinkedList::updateNode(int k, int d)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->key == k)
        {
            temp->data = d;
            return;
        }
        temp = temp->next;
    }
}

// Method to print the members of the linked list
void CircularLinkedList::printList() // Function overloading
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->key << " " << temp->data << endl;
        temp = temp->next;
    }
} // End of printList()

// Driver program to test the above functions
int main()
{
    Node *n1 = new Node(1, 10);
    Node *n2 = new Node(2, 20);
    Node *n3 = new Node(3, 30);
    Node *n4 = new Node(4, 40);
    Node *n5 = new Node(5, 50);
    Node *n6 = new Node(6, 60);
    Node *n7 = new Node(7, 70);
    Node *n8 = new Node(8, 80);
    Node *n9 = new Node(9, 90);
    Node *n10 = new Node(10, 100);

    CircularLinkedList *cll = new CircularLinkedList(); // Create a new object of the class CircularLinkedList
    cll->prependNode(n1);                               // Prepend the node n1 to the linked list
    cll->prependNode(n2);                               // Prepend the node n2 to the linked list
    cll->prependNode(n3);                               // Prepend the node n3 to the linked list
    cll->prependNode(n4);                               // Prepend the node n4 to the linked list
    cll->prependNode(n5);                               // Prepend the node n5 to the linked list
    cll->prependNode(n6);                               // Prepend the node n6 to the linked list
    cll->prependNode(n7);                               // Prepend the node n7 to the linked list
    cll->prependNode(n8);                               // Prepend the node n8 to the linked list
    cll->prependNode(n9);                               // Prepend the node n9 to the linked list
    cll->prependNode(n10);                              // Prepend the node n10 to the linked list
    cll->printList();                                   // Print the members of the linked list
    cout << endl;
    cll->insertNodeAfter(5, n1); // Insert the node n1 after the node with key 5
    cll->printList();            // Print the members of the linked list
    cout << endl;
    cll->insertNodeAfter(5, n2); // Insert the node n2 after the node with key 5
    cll->printList();            // Print the members of the linked list
    cout << endl;
}