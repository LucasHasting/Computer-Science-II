/*
Name: Lucas Hasting
Project Number: 4
File Name: CourseList.h
Project Description: Use a linked list to store meal courses
Course: CS 255
Instructor: Janet Jenkins
*/

#include <iostream>
using namespace std;

#ifndef _CourseList_H
#define _CourseList_H
class Node{
    //data members
    int CourseNumber;
    string CourseName;
    string food[5];
    string drink[3];
    string host;
    Node* next;
    //Constructors - note: they are private
    Node();
    Node(string d);
    Node(string d, Node* n);
    friend class CourseList;
};

class CourseList{
    Node* head;
public:
    CourseList();
    ~CourseList();
    bool Insert(int courseNumber, string course, string host, string food[], string drink[]);
    bool Remove(int item);
    bool FindCourseNumber(int item);
    bool FindCourseName(string item);
    void Print();
    int GetCourseAmount();
    string PrintSeparator(int amount, string spacer);
    void Copy(string arr1[], string arr2[], int size);
    void PrintArr(string arr[], int size);
};



#endif



