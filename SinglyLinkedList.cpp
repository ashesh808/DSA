// Including the required headers
#include <iostream>
using namespace std;

// This class represents the node of a linked list
class Node
{
private:
    // Data memebers of a node are:
    //  1. Key : which is used for finding and updating each node will have a unique key
    //  2. Data : which is the actual value contained in the node
    //  3. Next : This pointer will point to the next member of the linked list
    int key;
    int data;
    Node *next; // Pointer of the data type "Node"
public:
    // Constructor methods
    Node();
    Node(int k, int d);
    int getKey();
    int getData();
    Node *getNext();
    void setKey(int k);
    void setData(int d);
    void setNext(Node *n);
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
int Node::getKey()
{
    return key;
}
int Node::getData()
{
    return data;
}
Node *Node::getNext()
{
    return next;
}
void Node::setKey(int k)
{
    key = k;
}
void Node::setData(int d)
{
    data = d;
}
void Node::setNext(Node *n)
{
    next = n;
}

// Singly linked list class will essentially link all the nodes and will make it possiable for us to perform operations on them
class SinglyLinkedList
{
public:
    // The only data member of the linked list class is the head pointer which points to the first element of the linked list
    Node *head;

    // Constructor functions
    SinglyLinkedList();
    SinglyLinkedList(Node *n);

    //  Destructor function
    ~SinglyLinkedList();

    // Operation functions
    Node *nodeExists(int k);
    void prependNode(Node *n);
    void insertNodeAfter(int k, Node *n);
    void insertNodeBefore(int k, Node *n);
    void appendNode(Node *n);
    void addNewNode(Node *n);
    void addNode(Node *ptr, Node *n);

    void deleteNode(int k);
    void updateNode(int k, int d);

    // Method to print the members of the linked list
    void printList();
};

// Default constructor
SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
}
// Parameterized constructor
SinglyLinkedList::SinglyLinkedList(Node *n)
{
    head = n;
}
// Destructor function
SinglyLinkedList::~SinglyLinkedList()
{
    Node *ptr = head;
    Node *temp;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->getNext();
        delete temp;
    }
}

// Method to find a node with key 'k'
Node *SinglyLinkedList::nodeExists(int k)
{
    Node *temp = NULL;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->getKey() == k)
        {
            temp = ptr;
        }
        ptr = ptr->getNext();
    }
    return temp;
}
// Method  to append a node to the singly linked list
void SinglyLinkedList::appendNode(Node *n)
{
    if (nodeExists(n->getKey()) != NULL)
    {
        cout << "Node with the same key value already exist!" << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *ptr = head;
            while (ptr->getNext() != NULL)
            {

                ptr = ptr->getNext();
            }
            ptr->setNext(n);
        }
        cout << "Node Appended" << endl;
    }
}

// Method  to add a node to the singly linked list
void SinglyLinkedList::addNewNode(Node *n)
{
    if (nodeExists(n->getKey()) != NULL)
    {
        cout << "Node with the same key value already exist!" << endl;
    }
    else
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            addNode(head, n);
        }
        cout << "Node added to the ordered linked list" << endl;
    }
}

// Method  to add a node to the singly linked list
void SinglyLinkedList::addNode(Node *root, Node *n)
{
    if (root->getData() < n->getData())
    {
        if (root->getNext() == NULL)
        {
            insertNodeAfter(root->getKey(), n); // O(n)
        }
        else
        {
            root = root->getNext();
            addNode(root, n); // Used recursion
        }
    }
    else
    {
        insertNodeBefore(root->getKey(), n); // Best : O(1), Worst : O(n)
    }
}

// Method  to insert a node to the singly linked list
void SinglyLinkedList::prependNode(Node *n)
{
    n->setNext(head);
    head = n;
}

// Method  to insert a node after the targeted node to the singly linked list
void SinglyLinkedList::insertNodeAfter(int k, Node *n)
{
    // Checking if the new node's key is already in use by  a previous node
    if (nodeExists(n->getKey()) != NULL)
    {
        cout << "Node with the same key value already exist!" << endl;
    }
    else
    {
        // Checking if the key matches any node in the linked list
        if (nodeExists(k) == NULL)
        {
            cout << "Node with the given key does not exist!" << endl;
        }
        else
        {
            // The address of the node whose's key is given by the user is stored in target pointer
            Node *target = nodeExists(k);
            // The next pointer of the new node will point to the node next to the targeted node
            n->setNext(target->getNext());
            // The next pointer of the targeted node will point to the new node
            target->setNext(n);
        }
    }
}

// Method to insert a node before the targeted node to the singly linked list
void SinglyLinkedList::insertNodeBefore(int k, Node *n)
{
    // Checking if the new node's key is already in use by  a previous node
    if (nodeExists(n->getKey()) != NULL)
    {
        cout << "Node with the same key value already exist!" << endl;
    }
    else
    {
        // Checking if the key matches any node in the linked list
        if (nodeExists(k) == NULL)
        {
            cout << "Node with the given key does not exist!" << endl;
        }
        // If the targeted node is head than the node is prepended
        else if (nodeExists(k) == head)
        {
            prependNode(n);
        }

        else
        {
            // The address of the node whose's key is given by the user is stored in target pointer
            Node *target = nodeExists(k);
            // Pointer of the node previous to the targeted node
            Node *prev = NULL;
            // Traversing the list to find the node previous to the targeted node
            Node *ptr = head;
            while (ptr != NULL)
            {
                if (ptr->getKey() == target->getKey())
                {
                    prev = ptr;
                }
                ptr->setNext(ptr->getNext());
            }
            // The previous node of the targeted node will point to the new node
            prev->setNext(n);

            // The new node will point to the targeted node
            n->setNext(target);
        }
    }
}

// Method to delete a Node to the singly linked list
void SinglyLinkedList::deleteNode(int k)
{
    // Checking if the node with the user given key exists
    if (nodeExists(k) == NULL)
    {
        cout << "Node with the key value does not exist!" << endl;
    }
    else
    {
        // The address of the node whose's key is given by the user is stored in target pointer
        Node *target = nodeExists(k);
        // Pointer of the node previous to the targeted node
        Node *prev = NULL;
        // Traversing the list to find the node previous to the targeted node
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->next == target)
            {
                prev = ptr;
            }
                ptr = ptr->next;
        }
        // The next of the previous node will point to the next of the targeted node
        prev->next = target->next;
        // Erasing the next of the targeted node
        target->next = NULL;
    }
}

// Method  to update a node to the singly linked list
void SinglyLinkedList::updateNode(int k, int d)
{
    // node pointer to store the targeted node
    Node *target = nodeExists(k);
    // Checking if the node with the user given key exist
    if (target == NULL)
    {
        cout << "Node with given key does not exist!" << endl;
    }
    else
    {
        // Updating the data of the targeted node with the user given data
        target->setData(d);
    }
}

// Method to print each element of the linked list
void SinglyLinkedList::printList()
{
    if (head == NULL)
    {
        cout << "No nodes present!" << endl;
    }
    else
    {
        cout << "\n Singly Linked List Values:";
        cout << '\n';
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "(" << temp->getKey() << " ," << temp->getData() << ")--> ";
            temp->setNext(temp->getNext());
        }
        cout << '\n';
    }
}

// Main function for testing
int main()
{
    Node *n1 = new Node(2, 20);
    Node *n2 = new Node(1, 10);
    Node *n3 = new Node(3, 30);
    Node *n4 = new Node(4, 40);
    Node *n5 = new Node(5, 25);

    SinglyLinkedList s(n1); // Initializing linked list with n1 as head
    s.addNewNode(n2);
    s.addNewNode(n3);
    s.addNewNode(n4);
    s.addNewNode(n5);

    s.printList();
    //O(n) deletion
    s.deleteNode(5);
    s.printList();
    //O(1) deletion
    s.deleteNode(1);
    s.printList();



    return 0;
}