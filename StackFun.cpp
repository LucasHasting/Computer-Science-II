/*
Name: Lucas Hasting
Description: Test the methods in the Stack class
Course: CS 255 Computer Science II
Date: 10-5-2022
*/

#include <iostream>
using namespace std;
const int MAX = 5;
class Stack{
    int data[MAX];  //array holding the data
    int top;   // index of the top item
public:
    Stack();
    bool Push(int item);
    bool Pop(int& item);
    void Print()const;
    bool Peek(int& item)const;
    bool IsEmpty()const;
    bool IsFull()const;
};
Stack::Stack():top(-1){}

bool Stack::Push(int item){
    bool success = false;
    if (! IsFull()){
       success = true;
       data[++top] = item;
    }
    return success;
}
bool Stack::Pop(int& item){
    bool success = false;
    if (!IsEmpty()){
       success = true;
       item = data[top--];

    }
    return success;
}
void Stack::Print()const{
    for (int t = top; t >= 0; t--)
        cout << data[t] << endl;
    cout << "----" << endl;
}
bool Stack::Peek(int& item)const{
    bool success = false;
    if (!IsEmpty()){
       success = true;
       item = data[top];
    }
    return success;
}
bool Stack::IsEmpty()const{
    return top == -1;
}
bool Stack::IsFull()const{
    return top == MAX - 1;
}


//Driver Program
int main(){
    //Creating the stack object
    Stack s1;
    int peek;

    //Fills the stack and beyond
    for (int i = 0; i < MAX + 1; i++)
    {
        cout << boolalpha << "Full: " << s1.IsFull() << endl;
        s1.Print(); cout << endl;
        s1.Push(i+1);
    }

    //sets the peek of the stack in the peek variable and outputs it
    s1.Peek(peek);
    cout << endl << "Peek of the stack: " << peek << endl << endl;

    //pops all the values in the stack and one more to test popping no values
    for (int i = 0; i < MAX + 1; i++)
    {
        int e = 0;
        s1.Pop(e);
        cout << boolalpha << "Empty: " << s1.IsEmpty() << endl;
        cout << "Popped: " << e << endl;
        cout << "*****" << endl;
        s1.Print(); cout << endl;
    }

    return 0;
}







