/*
Name: Lucas Hasting
Project Number: 4
File Name: CourseList.cpp
Project Description: Use a linked list to store meal courses
Course: CS 255
Instructor: Janet Jenkins
*/

#include "CourseList.h"
Node::Node():next(nullptr){}
Node::Node(string d):CourseName(d), next(nullptr){}
Node::Node(string d, Node* n):CourseName(d), next(n){}

//Constructor
CourseList::CourseList():head(nullptr){}

//Destructor
CourseList::~CourseList(){
      while(head != nullptr)
      {
         Node* temp = head;
         head = head->next;
         delete temp;
      }
}

/*
method Name: Insert
method Description: Inserts data into the list
Return Value: boolean success
Incoming Parameters: courseNumber, course, host, food array, drink array
Outgoing Parameters: none
*/
//modified method from class code
bool CourseList::Insert(int courseNumber, string course, string host, string food[], string drink[]){
    bool success = true;

    if (head == nullptr || courseNumber < head->CourseNumber){
       head = new Node(course, head);
       head->host = host;
       head->CourseNumber = courseNumber;
       Copy(head->food, food, 5);
       Copy(head->drink, drink, 3);
    }
    else{
        Node *temp = head;
        Node *prev = nullptr;
        while (temp != nullptr && courseNumber >= temp->CourseNumber){
            prev = temp;
            temp = temp->next;
        }
        prev->next = new Node(course, temp);
        prev->next->host = host;
        prev->next->CourseNumber = courseNumber;
        Copy(prev->next->food, food, 5);
        Copy(prev->next->drink, drink, 3);
    }

    return success;
}

/*
method Name: Remove
method Description: Removes a value from the list
Return Value: boolean success
Incoming Parameters: item
Outgoing Parameters: nones
*/
//modified method from class code
bool CourseList::Remove(int item){
    bool success = true;

    Node *temp = head;
    Node *prev = nullptr;

    while(temp != nullptr && item != temp->CourseNumber){
         prev = temp;
         temp=temp->next;
    }
    if (temp == nullptr)
       success = false;
    else if (temp==head){
         head = head->next;
         delete temp;
    }
    else{
         prev->next = temp->next;
         delete temp;
    }
    if (success == false)
        cout << "Error, could not find course" << endl;
    return success;
}

/*
method Name: FindCourseNumber
method Description: Finds and outputs the course based on its course number
Return Value: bool
Incoming Parameters: integer item
Outgoing Parameters: none
*/
//modified method from class code
bool CourseList::FindCourseNumber(int item){
     string spacer = PrintSeparator(50, "-");
     Node* temp = head;
     bool success = false;

     while (temp != nullptr)
     {
        if (temp->CourseNumber == item){
            cout << "Course Number: " << temp->CourseNumber
            << endl << "Course Name: " << temp->CourseName
            << endl << "Host: " << temp->host << endl;

            cout << "Food:";
            PrintArr(temp->food, 5);
            cout << "Drink:";
            PrintArr(temp->drink, 3);
            cout << spacer << endl;
            temp = temp->next;
            success = true;
        }
        else
            temp = temp->next;
     }

     if (!success){
        cout << "Could not find course" << endl;
        cout << spacer << endl;
     }
}

/*
method Name: FindCourseName
method Description: Finds and outputs the course based on its name
Return Value: bool
Incoming Parameters: string item
Outgoing Parameters: none
*/
//modified method from class code
bool CourseList::FindCourseName(string item){
     string spacer = PrintSeparator(50, "-");
     Node* temp = head;
     bool success = false;

     while (temp != nullptr)
     {
        if (temp->CourseName == item){
            cout << "Course Number: " << temp->CourseNumber
            << endl << "Course Name: " << temp->CourseName
            << endl << "Host: " << temp->host << endl;

            cout << "Food:";
            PrintArr(temp->food, 5);
            cout << "Drink:";
            PrintArr(temp->drink, 3);
            cout << spacer << endl;
            temp = temp->next;
            success = true;
        }
        else
            temp = temp->next;
     }

     if (!success){
        cout << "Could not find course" << endl;
        cout << spacer << endl;
     }
}

/*
method Name: Print
method Description: outputs all courses in the list
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
//modified method from class code
void CourseList::Print(){
    string spacer = PrintSeparator(50, "-");
    Node* temp = head;

    if (head == nullptr){
        cout << spacer << endl;
        cout << "No Courses In The List" << endl;
        cout << spacer << endl;
        return;
    }

    cout << spacer << endl;
    while(temp!=nullptr){
        cout << "Course Number: " << temp->CourseNumber
        << endl << "Course Name: " << temp->CourseName
        << endl << "Host: " << temp->host << endl;

        cout << "Food:";
        PrintArr(temp->food, 5);
        cout << "Drink:";
        PrintArr(temp->drink, 3);
        cout << spacer << endl;
        temp = temp->next;                      // moves to next item
    }
}

/*
method Name: GetCourseAmount
method Description: returns the amount of courses
Return Value: integer
Incoming Parameters: none
Outgoing Parameters: none
*/
int CourseList::GetCourseAmount(){
    Node* temp = head;
    int inc = 0;
    while(temp!=nullptr){
        inc++;
        temp = temp->next;
    }
    return inc;
}

/*
method Name: PrintSeparator
method Description: used to separate output
Return Value: string sep
Incoming Parameters: integer amount, string spacer
Outgoing Parameters: none
*/
string CourseList::PrintSeparator(int amount, string spacer){
    string sep = "";
    for (int i = 0; i < amount; i++)
    {
        sep += spacer;
    }
    return sep;
}

/*
method Name:
method Description:
Return Value:
Incoming Parameters:
Outgoing Parameters:
*/
void CourseList::Copy(string arr1[], string arr2[], int size){
    for(int i = 0; i < size; i++){
        arr1[i] = arr2[i];
    }
}

/*
method Name: PrintArr
method Description: Outputs the contents of an array
Return Value: none
Incoming Parameters: string array arr, integer size
Outgoing Parameters: none
*/
void CourseList::PrintArr(string arr[], int size){
    for(int i = 0; i < size; i++){
        cout << endl << "  " << arr[i];
    }
    cout << endl;
}
