// Including the required headers
// Implementing a stack using linked list
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
Node::Node()
{
    key = 0;
    data = 0;
}
Node::Node(int k, int d)
{
    key = k;
    data = d;
}

// This class to represent the data structure stack
// FILO -> First In Last Out
// LIFO -> Last In First Out
// Insertion and deletion happen on the same end`
class Stack
{

public:
    // Head of the linked list
    Node *head;
    Stack();
    Stack(Node *n);
    // Methods of a stack
    // Pushes an element into the stack
    void push(int n);
    // Returns and removes the last element from the stack
    int pop();
    // prints all elements of the stack
    void print();
};

// Default Constructor
Stack::Stack()
{
    head = NULL;
}

Stack::Stack(Node *n)
{
    head = n;
}

void Stack::push(int n)
{
    if (head == NULL)
    {
        head->key = 1;
        head->data = n;
    }
    else
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
        }
        Node *newNode = new Node(ptr->key + 1, n);
        ptr->next = newNode;
    }
}
int Stack::pop()
{
    int val;
     Node* ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    val = ptr->next->data;
    ptr->next = NULL;
    return val;
}
void Stack::print()
{
    Node* ptr = head;
    cout << "\n";
    while (ptr != NULL)
    {
        cout << ptr->data << " ---> ";
    }
    cout << "\n";
}

int main()
{
    Stack s1;
    for (int i = 0; i < 10; i++)
    {
        s1.push(i);
    }
    s1.print();
    return 0;
}