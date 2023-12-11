/*
Name: Lucas Hasting
Project Number: 4
File Name: HastingLucas_CS255_P4.cpp
Project Description: Use a linked list to store meal courses
Course: CS 255
Instructor: Janet Jenkins
*/

#include "CourseList.cpp"

//function prototypes
void InsertMenu(CourseList &obj);
void MainMenu(CourseList &obj);
void MainMenuSwitch(int decide, CourseList &obj);

int main(){
    //create the course list object
    CourseList obj;

    //display the main menu
    MainMenu(obj);

    //end the program
    return 0;
}

/*
Function Name: InsertMenu
Function Description: Ask's the user information to insert into the list
Return Value: None
Incoming Parameters: CourseList obj
Outgoing Parameters: CourseList obj
*/
void InsertMenu(CourseList &obj){
    //declare variables
    string sep = obj.PrintSeparator(50, "-");
    string host;
    string course;
    int CourseNumber;
    string food[5];
    string drink[3];

    //get input and send output
    cout << sep << endl << "Enter Host: ";
    cin >> host;
    cout << "Enter Course: ";
    cin >> course;
    cout << "Enter Course Number: ";
    cin >> CourseNumber;

    //separate output
    cout << sep << endl;

    //output the food
    for (int i = 0; i < 5; i++){
        cout << "Enter food item " << i + 1 << "(if none, type none): ";
        cin >> food[i];
    }

    //separate output
    cout << sep << endl;

    //output the drinks
    for (int i = 0; i < 3; i++){
        cout << "Enter drink item " << i + 1 << "(if none, type none): ";
        cin >> drink[i];
    }

    //insert the data into the list
    obj.Insert(CourseNumber, course, host, food, drink);
}

/*
Function Name: MainMenu
Function Description: The main menu the user will see
Return Value: None
Incoming Parameters: CourseList obj
Outgoing Parameters: CourseList obj
*/
void MainMenu(CourseList &obj){
    //declare variables
    int decide = 0;
    string sep = obj.PrintSeparator(50, "*");

    //separate output
    cout << sep << endl;

    //loop the input/output
    do{
        cout << "Display Course List:                         1" <<
        endl << "Insert a Course:                             2" <<
        endl << "Remove a course by course number:            3" <<
        endl << "Display the amount of courses on the list:   4" <<
        endl << "Search for a course by name:                 5" <<
        endl << "Search for a course by number:               6" <<
        endl << "Quit:                                        0" <<
        endl << "Enter: ";
        cin >> decide;

        //put the input into the MainMenuSwitch function
        MainMenuSwitch(decide, obj);

        //separate output
        cout << sep << endl;
    } while (decide != 0);
}

/*
Function Name: MainMenuSwitch
Function Description: The switch for the main menu, which decides what action to take from the main menu
Return Value: None
Incoming Parameters: integer decide, CourseList obj
Outgoing Parameters: CourseList obj
*/
void MainMenuSwitch(int decide, CourseList &obj){
    //declare variables
    int remove;
    string name;
    int number;
    string sep = obj.PrintSeparator(50, "-");

    //switch to decide which methods to call and which inputs and outputs to use
    switch(decide){
    case 0:
        break;
    case 1:
        obj.Print();
        break;
    case 2:
        InsertMenu(obj);
        break;
    case 3:
        cout << sep << endl << "Enter the course to be removed: ";
        cin >> remove;
        obj.Remove(remove);
        cout << sep << endl;
        break;
    case 4:
        cout << sep << endl << "The amount of courses is: " << obj.GetCourseAmount() << endl << sep << endl;
        break;
    case 5:
        cout << sep << endl << "Enter the course name: ";
        cin >> name;
        cout << sep << endl;
        obj.FindCourseName(name);
        break;
    case 6:
        cout << sep << endl << "Enter the course number: ";
        cin >> number;
        cout << sep << endl;
        obj.FindCourseNumber(number);
        break;
    default:
        cout << sep << endl;
        cout << "Wrong Input, please try again" << endl;
        cout << sep << endl;
        break;
    }
}

