// Including the required headers
//Implementing a stack using linked list
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
// This class to represent the data structure stack
//FILO -> First In Last Out
//LIFO -> Last In First Out
//Insertion and deletion happen on the same end`
class Stack
{

public:
    //Head of the linked list
    Node* head;
    //Methods of a stack
    //Pushes an element into the stack
    void push(int n);
    //Returns and removes the last element from the stack
    int pop();


  
};

int main()
{
    return 0;
}