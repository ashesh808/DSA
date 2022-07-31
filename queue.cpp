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
    int data;
    Node *next; // Pointer of the data type "Node"
    // Constructor methods
    Node();
    Node(int d);
};
Node::Node()
{
    data = 0;
}
Node::Node(int d)
{
    data = d;
}

// This class to represent the data structure queue
// The Queue has a First In First Out(FIFO) system
class Queue
{
public:
    Node *head;
    // Default Constructor
    Queue();
    // Adding element to the back
    void enqueue(int n);
    // Removing element the first added element
    void dequeue();
    // Printing all the elements of a queue
    void print();
};
// Default Constructor
Queue::Queue()
{
    head = NULL;
}
void Queue::enqueue(int n)
{
    if (head == NULL)
    {
        Node *newNode = new Node(n);
        head = newNode;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        Node *newNode = new Node(n);
        ptr->next = newNode;
    }
}
// Method to remove the first element
void Queue::dequeue()
{
    cout << head->data << " has been removed! \n";
    head = head->next;
}

void Queue::print()
{
    Node *ptr = head;
    cout << "\n";
    while (ptr != NULL)
    {
        cout << ptr->data << " ---> ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main()
{
    Queue q;
    for (int i = 0; i < 10; i++)
    {
        q.enqueue(i);
    }
    q.print();
    q.dequeue();
    q.print();


    return 0;
}