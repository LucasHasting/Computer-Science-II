/*
Name: Lucas Hasting
Project Number: 5
File Name: Things.cpp
Project Description: Create a Linked List of objects using a templated Linked List Class
Course: CS 255
Instructor: Janet Jenkins
*/

#include "Things.h"

/*
Method Name: Things
Method Description: constructor, sets the data members
Return Value: none
Incoming Parameters: num, arr, size
Outgoing Parameters: none
*/
Things::Things(int num, double arr[], int size){
    gradeAmount = size;
    grades = new double[gradeAmount];
    courseNum = num;

    for (int i = 0; i < gradeAmount; i++){
        grades[i] = arr[i];
    }
}

/*
Method Name: Things
Method Description: copy constructor, calls the copy method when a things object is used in the parameter
Return Value: none
Incoming Parameters: right
Outgoing Parameters: right
*/
Things::Things(const Things &right){
    Copy(right);
}

/*
Method Name: ~Things
Method Description: destructor, deletes the dynamic array
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
Things::~Things(){
    delete [] grades;
}

/*
Method Name: operator=
Method Description: overloads the = operator, deletes the dynamic array then calls the copy method
Return Value: none
Incoming Parameters: right
Outgoing Parameters: none
*/
Things Things::operator=(Things right){
    delete [] grades;

    Copy(right);
}

/*
Method Name: operator<<
Method Description: overloads the << operator, displays output
Return Value: none
Incoming Parameters: os, right
Outgoing Parameters: os
*/
ostream& operator<<(ostream& os, Things right){
    for (int i = 0; i < right.gradeAmount; i++){
        cout << right.grades[i] << "\t";
    }
    cout << endl;
}

/*
Method Name: operator<
Method Description: overloads the < operator, compares the courseNum
Return Value: bool
Incoming Parameters: right
Outgoing Parameters: none
*/
bool Things::operator<(Things right){
    return courseNum <= right.courseNum;
}

/*
Method Name: operator>
Method Description: overloads the > operator, compares the courseNum
Return Value: bool
Incoming Parameters: right
Outgoing Parameters: none
*/
bool Things::operator>(Things right){
    return courseNum > right.courseNum;
}

/*
Method Name: Copy
Method Description: helper for the copy constructor and operator= methods
                    copy's data members values from the right object to the calling object
Return Value: none
Incoming Parameters: right
Outgoing Parameters: right
*/
void Things::Copy(const Things &right){
    courseNum = right.courseNum;
    gradeAmount = right.gradeAmount;
    grades = new double[gradeAmount];
    for(int i = 0; i < gradeAmount; i++)
    {
        grades[i] = right.grades[i];
    }
}
