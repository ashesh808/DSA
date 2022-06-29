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

    // Destructor function
    ~DoublyLinkedList();

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

// Destructor function to deallocate the memory
DoublyLinkedList::~DoublyLinkedList()
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
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
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void DoublyLinkedList::appendNode(Node *n)
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
void DoublyLinkedList::insertNodeAfter(int k, Node *n)
{
    // Input validation to make sure the key is unique
    if (nodeExists(n->key) != NULL)
    {
        cout << "Node with the same key already exists in the list! \n";
    }
    else
    {
        // Input validation to make sure the key entered by user exists in the list
        if (nodeExists(k) == NULL)
        {
            cout << "Node with the key entered does not exisit! \n";
        }
        else
        {
            Node *ptr = head;
            while (ptr->key != k)
            {
                ptr = ptr->next;
            }
            n->next = ptr->next;
            ptr->next = n;
            n->prev = ptr;
        }
    }
}
// Needs some fixing
void DoublyLinkedList::deleteNode(int k)
{
    Node *target = nodeExists(k);
    // Input validation to make sure the key entered by user exists in the list
    if (target == NULL)
    {
        cout << "Node with the key entered does not exisit! \n";
    }
    else if (target == head)
    {
        head = target->next;
        target->next->prev = NULL;
        delete target;
    }

    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
}
void DoublyLinkedList::updateNode(int k, int d)
{
    Node *target = nodeExists(k);
    if (target == NULL)
    {
        cout << "Node with the key entered does not exisit! \n";
    }
    else
    {
        target->data = d;
    }
}

void DoublyLinkedList::printList()
{
    Node *ptr = head;
    if (head == NULL)
    {
        cout << "The linked list is empty \n";
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->data << " <==> ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}

// Main function for testing
int main()
{
    cout << "This is a doubly linked list \n";

    // Creating nodes
    Node *n1 = new Node(1, 10);
    Node *n2 = new Node(2, 20);
    Node *n3 = new Node(3, 30);
    Node *n4 = new Node(4, 40);
    Node *n5 = new Node(0, 0);
    Node *n6 = new Node(6, 6);

    DoublyLinkedList d(n1);
    d.appendNode(n2);
    d.appendNode(n3);
    d.appendNode(n4);
    d.prependNode(n5);
    d.printList();

    d.insertNodeAfter(0, n6);
    d.printList();
    d.deleteNode(0);
    d.printList();
    d.updateNode(3, 700);
    d.printList();

    // d.deleteNode(1);
    // d.printList();

    return 0;
}