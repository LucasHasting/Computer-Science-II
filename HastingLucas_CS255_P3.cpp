/*
Name: Lucas Hasting
Project Number: 3
File Name: HastingLucas_CS255_P3.cpp
Project Description: Allows the user to draw on a grid with a size chosen by the user by typing in a number as a position
Course: CS 255
Instructor: Janet Jenkins
*/

#include "Canvas.cpp"

//declare constants
const int MAX_CANVAS_SIZE = 30;
const int MIN_CANVAS_SIZE = 2;


//function prototypes
int drawMenu(Canvas canvas);
void functionalMenu(int decide, Canvas& canvas);
int inputSize();
int inputRow();
int inputCol();

int main() //Driver function
{
    //Declare data types
    Canvas canvas(MAX_CANVAS_SIZE);
    int option;
    int input;

    //Menu to get the size of the canvas
    do{

        //Menu output
        cout << "Select the size option:" << endl
        << "Select an overall size:                    Enter 1" << endl
        << "Select a size for the row and column:      Enter 2" << endl
        << "Use the default size:                      Enter 0" << endl
        << "Enter: ";

        //Menu input
        cin >> input;
        switch(input)
        {
        case 1:
            {
                //Setting canvas size
                Canvas temp(inputSize());

                //testing the copy constructor
                Canvas temp2(temp);

                //using the assignment operator method
                canvas = temp2;
                break;
            }
        case 2:
            {
                //Setting canvas row and col size
                Canvas temp(inputRow(), inputCol());

                //using the assignment operator method
                canvas = temp;
                break;
            }
        case 0:
            {
                //Declaring default size
                Canvas temp;

                //Using the assignment operator method
                canvas = temp;
                break;
            }
        default:
            //ran when there is invalid input
            cout << endl << "Wrong Input, Please try again" << endl << endl;
        }

      //validates input
    } while (input < 0 || input > 2);

    //loop until the user enters 0 in the draw menu
    do
    {
        //display the draw menu
        option = drawMenu(canvas);

        //decide the right option from the menu
        functionalMenu(option, canvas);
        cout << endl;

    } while (option != 0);
    return 0;
}

/*
Function Name: drawMenu
Function Description: A menu for the user to draw
Return Value: decide
Incoming Parameters: canvas
Outgoing Parameters: none
*/
int drawMenu(Canvas canvas)
{
    //declare local variable decide, which decides which option to perform from the menu
    int decide;
    do
    {
        //display the canvas board
        canvas.DrawBoard();

        //display the menu
        cout << endl << "See image:                                               1" << endl
                     << "Draw:                                                    2" << endl
                     << "Undo:                                                    3" << endl
                     << "Reset:                                                   4" << endl
                     << "Quit:                                                    0" << endl
                     << "Enter: ";

        //get input for the menu
        cin >> decide;

        //validate the input
        if (decide > 4 || decide < 0)
            cout << endl << "Error: invalid input, please try again" << endl << endl;

      //loop until the input is valid
    } while (decide > 4 || decide < 0);

    return decide;
}

/*
Function Name: functionalMenu
Function Description: Use a switch statement to call different actions from the menu function
Return Value: None
Incoming Parameters: decide, canvas
Outgoing Parameters: canvas
*/
void functionalMenu(int decide, Canvas& canvas)
{
    int pos;
    switch (decide)
    {
    case 1:
        cout << endl;
        canvas.DrawImage();
        break;
    case 2:
        pos = canvas.InputPos();
        canvas.Draw(pos);
        break;
    case 3:
        canvas.Undo();
        break;
    case 4:
        canvas.Reset();
        break;
    default:
        break;
    }
}

/*
Function Name: inputSize
Function Description: get size input from the user
Return Value: size
Incoming Parameters: none
Outgoing Parameters: none
*/
int inputSize()
{
    int size;
    do
    {
        cout << endl << "Enter the overall size: ";
        cin >> size;
        if (size < MIN_CANVAS_SIZE || size > MAX_CANVAS_SIZE)
            cout << "Wrong input, please try again";
        cout << endl;
    } while(size < MIN_CANVAS_SIZE || size > MAX_CANVAS_SIZE);
    return size;
}

/*
Function Name: inputRow
Function Description: get row size input from the user
Return Value: row
Incoming Parameters: none
Outgoing Parameters: none
*/
int inputRow()
{
    int row;
    do
    {
        cout << "Enter the amount of rows: ";
        cin >> row;
        if (row < MIN_CANVAS_SIZE || row > MAX_CANVAS_SIZE)
            cout << "Wrong input, please try again";
        cout << endl << endl;
    } while(row < MIN_CANVAS_SIZE || row > MAX_CANVAS_SIZE);
    return row;
}

/*
Function Name: inputCol
Function Description: get col size input from the user
Return Value: col
Incoming Parameters: none
Outgoing Parameters: none
*/
int inputCol()
{
    int col;
    do
    {
        cout << "Enter the amount of columns: ";
        cin >> col;
        if (col < MIN_CANVAS_SIZE || col > MAX_CANVAS_SIZE)
            cout << "Wrong input, please try again" << endl;
        cout << endl;
    } while(col < MIN_CANVAS_SIZE || col > MAX_CANVAS_SIZE);
    return col;
}
