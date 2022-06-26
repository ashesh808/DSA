// This program takes in two complex numbers and returns thier sum
// Including the required headers
#include <iostream>
using namespace std;

// Class containing the features of a complex number
class Complexno
{
public:
    // Data members, complex numbers consist of a real part and an imaginary part
    int real;
    float imaginary;
    //Constructor methods
    Complexno();
    Complexno(int, float);
};
//Default constructor
Complexno::Complexno()
{
    real = 0;
    imaginary = 0;
}
//Parameterized Constructor
Complexno::Complexno(int i, float f)
{
    real = i;
    imaginary = f;
}

//Function to add the two complex numbers
Complexno *add(Complexno *num1, Complexno *num2)
{
    //Creating a new complex number to store the values after addition
    Complexno *add = new Complexno(); // New complex number with value 0
    add->real = num1->real + num2->real; // Adding the real part
    add->imaginary = num1->imaginary + num2->imaginary; // Adding the imaginary part
    return add; // Returning the pointer to the sum value
}

int main()
{
    Complexno *num1 = new Complexno(1, 5); // 1 + 5i
    Complexno *num2 = new Complexno(2, 7); // 2 + 7i
    Complexno *sum = add(num1, num2);

    cout << "The sum is: " << sum->real << " + " << sum->imaginary << "i \n";

    return 0;
}