/*
Name: Lucas Hasting
Project Number: 5
File Name: Stuff.h
Project Description: Create a Linked List of objects using a templated Linked List Class
Course: CS 255
Instructor: Janet Jenkins
*/

#ifndef _Stuff_H
#define _Stuff_H
class Stuff{
    string FirstName;
    string LastName;
    string StreetAddr;
    string City;
    string ST;
    string Zip;
    string Thanks[3];
public:
    Stuff(string fn, string ln, string straddr, string city, string st, string zip, string thank[]);
    friend ostream& operator<<(ostream& os, Stuff right);
    bool operator<(Stuff right);
    bool operator>(Stuff right);
};

#endif
