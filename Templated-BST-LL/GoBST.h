#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <class T>
class BST;

template <class T>
class BNode{
    T data;
    BNode* left;
    BNode* right;
    BNode* parent;
    BNode();
    BNode(T);
    BNode(T, BNode*, BNode*);
    friend class BST <T>;
};

template <class T>
BNode<T>::BNode(){
    left = right = parent = nullptr;
}

template <class T>
BNode<T>::BNode(T d){
    data = d;
    left = right = parent = nullptr;
}

template <class T>
BNode<T>::BNode(T d, BNode* l, BNode* r){
    data = d;
    left = l;
    right = r;
    parent = nullptr;
}

template <class T>
class BST{
	//data member
    BNode<T>* root;

    //helper methods
    bool InsertHelp(T e, BNode<T>*& b);
    void PrintInOrderHelp(BNode<T>* b)const;
    void PrintPreOrderHelp(BNode<T>* b)const;
    void PrintPostOrderHelp(BNode<T>* b)const;
    int CountHelper(BNode<T>* b)const;
    int CountHeightHelper(BNode<T>* b)const;
    bool SearchHelp(BNode<T>* b, T item)const;
    bool RemoveHelp(BNode<T>*& b, T item);
    BNode<T>* GetMinHelp(BNode<T>* b)const;
    BNode<T>* GetMaxHelp(BNode<T>* b)const;
    int GetAverageHelp(BNode<T>* b)const;
    void CopyHelp(BNode<T>*& b1, BNode<T>*& b2);

public:
    BST();
    BST<T>(BST<T>& right);
    ~BST();
    bool operator=(BST right);
    bool operator<(BST right);
    bool operator>(BST right);
    void Deallocate(BNode<T>*& b);
    void Copy(BST<T>& right);
    bool Insert(T e);
    void PrintInOrder()const;
    void PrintPreOrder()const;
    void PrintPostOrder()const;
	int Count()const;
	int CountHeight()const;
	bool Search(T item)const;
	bool Remove(T item);
	int GetMin()const;
	int GetMax()const;
	double GetAverage()const;

	template <class U>
	friend ostream& operator<<(ostream& os, const BST<U>& right);

};
