/*
Name: Lucas Hasting
Project Number: 3
File Name: Canvas.cpp
Project Description: Allows the user to draw on a grid with a size chosen by the user by typing in a number as a position
Course: CS 255
Instructor: Janet Jenkins
*/

#include "Canvas.h"

//constructor
Canvas::Canvas()
{
    Init();
}

//constructor with size parameter
Canvas::Canvas(const int size)
{
    row = size;
    col = size;
    Init();
}

//copy constructor
Canvas::Canvas(Canvas &canvas)
{
    row = canvas.row;
    col = canvas.col;
    Init();
}

//constructor with row and col size parameters
Canvas::Canvas(const int r, const int c)
{
    row = r;
    col = c;
    Init();
}

//destructor
Canvas::~Canvas()
{
    DeallocateImage();
    DeallocateBoard();
}

/*
Method Name: operator=
Method Description: overloads the assignment operator
Return Value: Canvas&
Incoming Parameters: canvas
Outgoing Parameters: canvas
*/
Canvas& Canvas::operator=(Canvas &canvas)
{
    if (this == &canvas)
        return *this;

    row = canvas.row;
    col = canvas.col;
    Init();

    return *this;
}

/*
Method Name: Init
Method Description: Initializes the object
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::Init()
{
    //checks to see if the image or board need to be deallocated
    if (image != nullptr)
        DeallocateImage();

    if (board != nullptr)
        DeallocateBoard();

    //allocate the image and board
    AllocateImage();
    AllocateBoard();

    //sets the check to false as nothing has been drawn yet
    check = false;

    //fill the image with blank characters (-)
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            image[r][c] = '-';

    //fills the board with numbers 1 - row * col
    int count = 0;
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            board[r][c] = ++count;

    return;
}

/*
Method Name: AllocateImage
Method Description: Allocates the image 2D array to be dynamic
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::AllocateImage()
{
    image = new char *[row];

    for (int r = 0; r < row; r++)
        image[r] = new char[col];

    return;
}

/*
Method Name: DeallocateImage
Method Description: Deallocates the image 2D dynamic array
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::DeallocateImage()
{
    for (int r = 0; r < row; r++)
        delete [] image[r];
    delete [] image;

    return;
}

/*
Method Name: AllocateBoard
Method Description: Allocates the board 2D array to be dynamic
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::AllocateBoard()
{
   //allocate a 2D arrays
    board = new int *[row];

    for (int r = 0; r < row; r++)
        board[r] = new int[col];

    return;
}

/*
Method Name: DeallocateBoard
Method Description: Deallocates the board 2D dynamic array
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::DeallocateBoard()
{
    for (int r = 0; r < row; r++)
        delete [] board[r];
    delete [] board;

    return;
}

/*
Method Name: DrawImage
Method Description: Outputs the Image to the screen
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::DrawImage()const
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
            cout << image[r][c] << "\t";
        cout << endl;
    }
}

/*
Method Name: DrawBoard
Method Description: Outputs the Board to the screen
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::DrawBoard()const
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
            cout << board[r][c] << "\t";
        cout << endl;
    }
}

/*
Method Name: Reset
Method Description: Reset the current object using the Init function which deallocates and reallocates both image and board
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::Reset()
{
    Init();
}

/*
Method Name: InputPos
Method Description: Input the position to be drawn
Return Value: pos
Incoming Parameters: None
Outgoing Parameters: None
*/
int Canvas::InputPos()const
{
    int pos;
    do
    {
        //ask the user for input
        cout << endl << "To erase a number, draw at the number again"
        << endl << "Which number would you like to draw at: ";

        //get input
        cin >> pos;

        //validate input
        if (pos > (row * col) || pos < 1)
            cout << endl << "Error: invalid input, please try again" << endl << endl;

      //loop until the input is valid
    } while (pos > (row * col) || pos < 1);

    return pos;
}

/*
Method Name: Draw
Method Description: Allows the user to draw on the image
Return Value: None
Incoming Parameters: pos
Outgoing Parameters: None
*/
void Canvas::Draw(const int pos)
{
    //check becomes true as the user has drawn something
    check = true;

    //store the last pos for the undo method
    lastPos = pos;

    //get the col and row based on pos chosen
    int colD = (pos-1)%col;
    int rowD = (pos-1)/col;

    //if something has been drawn erase it
    if (image[rowD][colD] == 'X')
        image[rowD][colD] = '-';

    //otherwise draw it
    else
        image[rowD][colD] = 'X';
}

/*
Method Name: Undo
Method Description: Undoes the last action
Return Value: None
Incoming Parameters: None
Outgoing Parameters: None
*/
void Canvas::Undo()
{
    //if nothing has been drawn, do not undo
    if (check)
        Draw(lastPos);
}
