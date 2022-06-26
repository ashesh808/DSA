//Including the required headers
#include <iostream>
using namespace std;
int main(){

    int size; // For storing the user defined size
    int *ptr; //pointer variable

    cout << "Enter the number  of values you want to store: " << endl;
    cin >> size;

    ptr = new int[size]; // Creating a new array with the size allocated by the user in a memory address

    cout << "Enter all the values of the array: " << endl;
    for ( int i = 0; i < size; i++)
    {
        cin >> ptr[i]; //Accessing the array
    }
     cout << "Values of the array are: " << endl;
    for ( int i = 0; i < size; i++)
    {
        cout << ptr[i] << endl;
    }
    return 0;
}