// Including the required headers
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
    //  4. Prev : This pointer will point to the previous member of the linked list
    int key;
    int data;
    Node *next; // Pointer of the data type "Node"
    Node *prev;

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
    prev = NULL;
}
// Parameterised Constructor (Function overloading)
Node::Node(int k, int d)
{
    key = k;
    data = d;
}

// class to doubly link the nodes
class DoublyLinkedList
{
public:
    // Head and Tail pointers
    Node *head;
    Node *tail;

    // Constructor functions
    DoublyLinkedList();
    DoublyLinkedList(Node *n);

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

// Default Constructor
DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}

// Parameterized construtor
DoublyLinkedList::DoublyLinkedList(Node *n)
{
    // Head and tail is the same in a doubly linked list with only one element
    head = n;
    tail = n;
}

Node *DoublyLinkedList::nodeExists(int k)
{
    Node *ptr = head;
    Node *temp = NULL;
    while (ptr->next != NULL)
    {
        if (ptr->key == k)
        {
            temp = ptr;
        }
        ptr = ptr->next;
    }
    return temp;
}
void DoublyLinkedList::prependNode(Node *n)
{
    // Input validation to make sure the key is unique
    if (nodeExists(n->key) != NULL)
    {
        cout << "Node with the same key already exists in the list! \n";
    }
    else
    {
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {

            // Traversing to the end of the list
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            // The next pointer of the last element will point to the new node
            ptr->next = n;
            // The previous pointer of the new element will point to the last node
            n->prev = ptr;
        }
    }
}

// Main function for testing
int main()
{
    cout << "This is a doubly linked list \n";
    return 0;
}