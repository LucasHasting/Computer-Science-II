/*
Name: Lucas Hasting
Project Number: Project 1 – Fraction Calculator
Project Description: Allows the user to test every method in the fraction class
Course: CS 255
Instructor: Janet Jenkins
*/

#include "Fraction.cpp"
#include <iomanip>

//Function Prototypes
int Menu();
void Computations(Fraction Fraction1, Fraction Fraction2);
void Math_Operations(Fraction Fraction1, Fraction Fraction2);
void Relational_Operations(Fraction Fraction1, Fraction Fraction2);
void Print_Separator(char output, int size);

int main() //driver function
{
    Fraction Fraction1;
    Fraction Fraction2(1);
    Computations(Fraction1, Fraction2);
    return 0;
}

/*
Function Name: Menu
Function Description: Display a menu to the user
Return Value: an integer (choice) that decides which computation to make
Incoming Parameters: None
Outgoing Parameters: choice
*/
int Menu()
{
    int choice;
    cout << left << setw(50) << "Fraction 1 Full: " << "Enter 1" <<
    endl << left << setw(50) << "Fraction 1 Full, not simplified: " << "Enter 2" <<
    endl << left << setw(50) << "Fraction 1 Denominator: " << "Enter 3" <<
    endl << left << setw(50) << "Fraction 1 Numerator: " << "Enter 4" <<
    endl << left << setw(50) << "Set Fraction 1 Full(n/d): " << "Enter 5" <<
    endl << left << setw(50) << "Set Fraction 1 Denominator: " << "Enter 6" <<
    endl << left << setw(50) << "Set Fraction 1 Numerator: " << "Enter 7" <<
    endl << left << setw(50) << "Fraction 2 Full: " << "Enter 8" <<
    endl << left << setw(50) << "Fraction 2 Full, not simplified: " << "Enter 9" <<
    endl << left << setw(50) << "Fraction 2 Denominator: " << "Enter 10" <<
    endl << left << setw(50) << "Fraction 2 Numerator: " << "Enter 11" <<
    endl << left << setw(50) << "Set Fraction 2 Full(n/d): " << "Enter 12" <<
    endl << left << setw(50) << "Set Fraction 2 Denominator: " << "Enter 13" <<
    endl << left << setw(50) << "Set Fraction 2 Numerator: " << "Enter 14" <<
    endl << left << setw(50) << "Simplify Fractions: " << "Enter 15" <<
    endl << left << setw(50) << "Math operations: " << "Enter 16" <<
    endl << left << setw(50) << "Relational operations: " << "Enter 17" <<
    endl << left << setw(50) << "Quit: " << "Enter 18" <<
    endl << "Enter: ";
    cin >> choice;
    Print_Separator('-', 60);
    return choice;
}

/*
Function Name: Computations
Function Description: Compute, based on a choice from the menu
Return Value: None
Incoming Parameters: Fraction1, Fraction2
Outgoing Parameters: Varies depending on functions the user chooses
*/
void Computations(Fraction Fraction1, Fraction Fraction2)
{
    int decide;
    int denom;
    int numerator;
    do{
        decide = Menu();
        if (decide == 1)
            cout << Fraction1;
        else if (decide == 2)
            Fraction1.PrintNotReduced(cout);
        else if (decide == 3)
            cout << Fraction1.getDen();
        else if (decide == 4)
            cout << Fraction1.getNum();
        else if (decide == 5)
            cin >> Fraction1;
        else if (decide == 6)
        {
            cout << "Denominator: " << endl;
            cin >> denom;
            Fraction1.setDen(denom);
        }
        else if (decide == 7)
        {
            cout << "Numerator: " << endl;
            cin >> numerator;
            Fraction1.setNum(numerator);
        }
        else if (decide == 8)
            cout << Fraction2;
        else if (decide == 9)
            Fraction2.PrintNotReduced(cout);
        else if (decide == 10)
            cout << Fraction2.getDen();
        else if (decide == 11)
            cout << Fraction2.getNum();
        else if (decide == 12)
            cin >> Fraction2;
        else if (decide == 13)
        {
            cout << "Denominator: " << endl;
            cin >> denom;
            Fraction1.setDen(denom);
        }
        else if (decide == 14)
        {
            cout << "Numerator: " << endl;
            cin >> numerator;
            Fraction1.setNum(numerator);
        }
        else if (decide == 15)
        {
            Fraction1.reduce();
            Fraction2.reduce();
        }
        else if (decide == 16)
            Math_Operations(Fraction1, Fraction2);
        else if (decide == 17)
            Relational_Operations(Fraction1, Fraction2);
        Print_Separator('-', 60);
    } while (decide != 18);
    return;
}

/*
Function Name: Math_Operations
Function Description: Perform mathematical operations on fractions
Return Value: None
Incoming Parameters: Fraction1, Fraction2
Outgoing Parameters: the math operation chosen by the user
*/
void Math_Operations(Fraction Fraction1, Fraction Fraction2){
    //declare variables
    int option1;
    char option2;
    char Operator;
    bool Switch = true;

    //declare object and pointers to objects
    Fraction f3;
    Fraction *one;
    Fraction *two;

    //short menu-gets input
    cout << "Usable Operators: " << endl << left << setw(30) << "Addition: +" << "Subtraction -" <<
    endl << left << setw(30) << "Multiplication: *" << "Division: /" <<
    endl << left << setw(30) << "Increment: ++" << "Decrement: --" << endl <<
    endl << left << setw(30) << "Refer to Fraction 1 as 1" << "1: " << Fraction1 <<
    endl << left << setw(30) << "refer to Fraction 2 as 2" << "2: " << Fraction2 << endl <<
    endl << left << setw(30) << "Example: " << "2++ or 1 * 2" << endl;
    cin >> option1 >> Operator >> option2;

    //set's the pointers objects for 1 and 2
    if (option1 == 1)
        one = &Fraction1;
    else if (option1 == 2)
        one = &Fraction2;

    if (option2 == '1')
        two = &Fraction1;
    else if (option2 == '2')
        two = &Fraction2;

    //if the second option is a + or - instead of a number, do the following operation
    switch(option2){
        case '+':
            f3 = *one++;
            f3++;
            Switch = false;
            break;
        case '-':
            f3 = *one;
            f3--;
            Switch = false;
            break;
    }

    //perform calculations based on the operator inputed by the user
    if (Switch){
        switch(Operator)
        {
            case '+':
                f3 = *one + *two;
                break;
            case '-':
                f3 = *one - *two;
                break;
            case '*':
                f3 = *one * *two;
                break;
            case '/':
                f3 = *one / *two;
                break;
        }
    }

    //output the answer
    cout << left << setw(30) << "Answer: " << f3 << endl;
    return;
}

/*
Function Name: Relational_Operations
Function Description: Perform relational operations on fractions
Return Value: None
Incoming Parameters: Fraction1, Fraction2
Outgoing Parameters: the relation chosen by the user
*/
void Relational_Operations(Fraction Fraction1, Fraction Fraction2){
    //declare variables
    int option1;
    char option2;
    string Operator;
    bool result;

    //declare pointers to objects
    Fraction *one;
    Fraction *two;

    //short menu-gets input
    cout << "Usable Operators: " << endl << left << setw(30) << "Greater Than: >" << "Less Than: <"
    << endl << left << setw(30) << "Equal: ==" << "Not Equal: !="
    << endl << left << setw(30) << "Greater Than/Equal: >=" << "Less Than/Equal: <=" << endl
    << endl << left << setw(30) << "Refer to Fraction 1 as 1" << "1: " << Fraction1
    << endl << left << setw(30) << "refer to Fraction 2 as 2" << "2: " << Fraction2 << endl
    << endl << left << setw(30) << "Example: " << "1 == 2 or 2 == 1" << endl;
    cin >> option1 >> Operator >> option2;

    //set's the pointers objects for 1 and 2
    if (option1 == 1)
        one = &Fraction1;
    else if (option1 == 2)
        one = &Fraction2;

    if (option2 == '1')
        two = &Fraction1;
    else if (option2 == '2')
        two = &Fraction2;

    //performs the operations based on the inputed operator
    if (Operator == "<")
        result = *one < *two;
    else if (Operator == ">")
        result = *one > *two;
    else if (Operator == "==")
        result = *one == *two;
    else if (Operator == "!=")
        result = *one != *two;
    else if (Operator == "<=")
        result = *one <= *two;
    else if (Operator == ">=")
        result = *one >= *two;

    //output the answer
    cout << left << setw(30) << "Answer: " << boolalpha << result << endl;
    return;
}

/*
Function Name: Print_Separator
Function Description: To separate the output
Return Value: None
Incoming Parameters: output, size
Outgoing Parameters: output with amount of size
*/
void Print_Separator(char output, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << output;
    }
    cout << endl;
    return;
}
