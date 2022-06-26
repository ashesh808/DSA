// Including the required headers
#include <iostream>
using namespace std;

// Pass by value
void passByValue(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Pass by refrence
void passByRefrence(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Pass by address
void passByAddress(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 5, b = 6;
    cout << "Before Swaping: a = " << a << " b = " << b << endl;
    // Calling functions
    passByValue(a, b); // This produces no change
    cout << "After Swaping from pass by value: a = " << a << " b = " << b << endl;

    passByRefrence(a, b); // This produces change
    cout << "After Swaping from pass by reference: a = " << a << " b = " << b << endl;

    passByAddress(&a, &b); // This produces change
    cout << "Swaping again from pass by address: a = " << a << " b = " << b << endl;

    return 0;
}
