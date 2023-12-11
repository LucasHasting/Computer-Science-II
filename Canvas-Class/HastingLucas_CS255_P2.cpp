/*
Name: Lucas Hasting
Project Number: 2
File Name: HastingLucas_CS255_P2.cpp
Project Description: Allows the user to draw on a 4x4 grid by typing in a number as a position
Course: CS 255
Instructor: Janet Jenkins
*/

#include "Canvas.cpp"

//function prototypes
int drawMenu(Canvas canvas);
void functionalMenu(int decide, Canvas& canvas);

int main() //Driver function
{
    //declare local variables
    Canvas canvas;
    int option;

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
Outgoing Parameters: decide
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
        cout << endl << "See image: 1" << endl
                     << "Draw:      2" << endl
                     << "Undo:      3" << endl
                     << "Reset:     4" << endl
                     << "Quit:      0" << endl
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
