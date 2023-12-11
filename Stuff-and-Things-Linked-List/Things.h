/*
Name: Lucas Hasting
Project Number: 5
File Name: Things.h
Project Description: Create a Linked List of objects using a templated Linked List Class
Course: CS 255
Instructor: Janet Jenkins
*/

#ifndef _Things_H
#define _Things_H
class Things{
    int courseNum;
    double* grades;
    int gradeAmount;
public:
    Things(int num, double arr[], int size);
    Things(const Things &right);
    ~Things();
    Things operator=(Things right);
    friend ostream& operator<<(ostream& os, Things right);
    bool operator<(Things right);
    bool operator>(Things right);
    void Copy(const Things &right);
};

#endif
