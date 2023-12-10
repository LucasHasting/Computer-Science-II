/*
Name: Lucas Hasting
Project Number: 5
File Name: HastingLucas_CS255_p5.cpp
Project Description: Create a Linked List of objects using a templated Linked List Class
Course: CS 255
Instructor: Janet Jenkins
*/

#include "LL.h"
#include "Stuff.cpp"
#include "Things.cpp"

int main(){
    //Creates LL Objects to hold Stuff objects and Things objects
    LL<Stuff> objLLS;
    LL<Things> objLLT;

    //Creates a thanks array to be reused
    string thanks[3] = {"Thank you Bob", "Thank you Joy", "Thank you Kevin"};

    //Creates 3 Stuff objects
    Stuff objS1("Susie","Jones","111 Go Street","Florence","Alabama","35603",thanks);
    Stuff objS2("Michael","McKenny","111 Bo Street","Florence","Alabama","35604",thanks);
    Stuff objS3("Kyle","Johns","111 No Street","Florence","Alabama","35602",thanks);

    //Inserts the objects into the LL object
    objLLS.Insert(objS1);
    objLLS.Insert(objS2);
    objLLS.Insert(objS3);

    //Outputs the LL object
    objLLS.Print();

    //Create 2 double arrays to be used in the Things object
    double data1[3] = {30.0,40.0,50.0};
    double data2[5] = {60.0,70.0,80.0,90.0,100.0};

    //Create things object in the format (course #, data, size of array)
    Things objT1(1, data1, 3);
    Things objT2(3, data2, 5);
    Things objT3(2, data1, 3);

    //Use the copy constructor and copy data from T3 to T4
    Things objT4 = objT3;

    //inserts T1
    objLLT.Insert(objT1);
    //inserts T4 which is T3
    objLLT.Insert(objT4);

    //changes T1 to T2 using assignment overload
    objT1 = objT2;

    //inserts T1 which is now T2
    objLLT.Insert(objT1);

    //Outputs the LL object
    objLLT.Print();
}
