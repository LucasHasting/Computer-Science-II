#ifndef _LL_H
#define _LL_H

#include <iostream>
using namespace std;

template <class T>
class LL;

template <class T>
class Node{
    Node(T d);
    Node(T d, Node* n);
    friend class LL <T>;
public:
    T data;
    Node* next;
};

template <class T>
class LL{
    Node <T>* head;
    void Destroy();
    void Copy(const LL&right);
public:
    LL();
    LL(const LL& right);
    ~LL();
	LL& operator=(const LL&right);
	bool operator>(LL right);
	bool operator<(LL right);
	bool operator==(LL right);

    bool Insert(T e);
    void Print()const;
    int Count()const;
    void Tinker()const;

    template <class U>
    friend ostream& operator<<(ostream& os, const LL<U>& right);
};

#endif
