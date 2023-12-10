/*
Name: Lucas Hasting
Project Number: 5
File Name: Stuff.cpp
Project Description: Create a Linked List of objects using a templated Linked List Class
Course: CS 255
Instructor: Janet Jenkins
*/

#include "Stuff.h"

/*
Method Name: Stuff
Method Description: The constructor, sets the data members using the parameters
Return Value: nothing
Incoming Parameters: fn, ln, straddr, city, st, zip, thank[]
Outgoing Parameters: none
*/
Stuff::Stuff(string fn, string ln, string straddr, string city, string st, string zip, string thank[]){
        FirstName = fn;
        LastName = ln;
        StreetAddr = straddr;
        City = city;
        ST = st;
        Zip = zip;

        for(int i = 0; i < 3; i++){
            Thanks[i] = thank[i];
        }
}

/*
Method Name: operator<<
Method Description: overloads the << operator, displays output
Return Value: ostream
Incoming Parameters: os, right
Outgoing Parameters: os
*/
ostream& operator<<(ostream& os, Stuff right){
    os << right.FirstName << endl << right.LastName << endl
    << right.StreetAddr << endl << right.City  << endl << right.ST
    << endl << right.Zip << endl;

    for(int i = 0; i < 3; i++){
        os << right.Thanks[i] << endl;
    }
    return os;
}

/*
Method Name: operator<
Method Description: overloads the < operator, compares the first character of the last name then first name
Return Value: bool
Incoming Parameters: right
Outgoing Parameters: none
*/
bool Stuff::operator<(Stuff right){
    if (LastName[0] < right.LastName[0])
        return true;
    else if (LastName[0] == right.LastName[0] && FirstName[0] <= right.FirstName[0])
        return true;
    else
        return false;
}

/*
Method Name: operator>
Method Description: overloads the > operator, compares the first character of the last name then first name
Return Value: bool
Incoming Parameters: right
Outgoing Parameters: none
*/
bool Stuff::operator>(Stuff right){
    if (LastName[0] > right.LastName[0])
        return true;
    else if (LastName[0] == right.LastName[0] && FirstName[0] > right.FirstName[0])
        return true;
    else
        return false;
}
