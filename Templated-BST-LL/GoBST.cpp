//************************************************************
// P6: Binary Search Tree Fun
// Author: Janet T. Jenkins, Lucas Hasting
// Use this file as a starting file for Project 6
// You will need to add the appropriate functionality
// to the BST class in order to complete this work.
//************************************************************

#include "GoBST.h"

template <class T>
BST<T>::BST(){
    root = nullptr;
}

template <class T>
BST<T>::~BST(){
    Deallocate(root);
}

template <class T>
BST<T>::BST(BST<T>& right){
    Copy(right);
}

template <class T>
bool BST<T>::operator=(BST right){
    Deallocate(root);
    Copy(right);
}

template <class T>
bool BST<T>::operator<(BST right){
    return Count() <= right.Count();
}

template <class T>
bool BST<T>::operator>(BST right){
    return Count() >= right.Count();
}

template <class U>
ostream& operator<<(ostream& os, const BST<U>& right){
    right.PrintInOrder();
    return os;
}

template <class T>
bool BST<T>::InsertHelp(T e, BNode<T>*& b){
    bool success = false;
    if (b == nullptr){
        b = new BNode<T>(e);
        success = true;
    }
    else{
        if (e < b->data)
        {
            success = InsertHelp(e, b->left);
            b->left->parent = b;
        }
        else if (e > b->data)
        {
            success = InsertHelp(e, b->right);
            b->right->parent = b;
        }
        else{
            cout << "NO DUPs" << endl;
            success = false;
        }
    }

    return success;
}

template <class T>
bool BST<T>::Insert(T e){
    return InsertHelp(e, root);
}

template <class T>
void BST<T>::Deallocate(BNode<T>*& b){
    if (b != nullptr){
        Deallocate(b->left);
        delete(b);
        Deallocate(b->right);
    }
}

template <class T>
void BST<T>::CopyHelp(BNode<T>*& b1, BNode<T>*& b2){
    if (b2 != nullptr){
        b1 = new BNode<T>;
        b1->data = b2->data;
        CopyHelp(b1->left, b2->left);
        CopyHelp(b1->right, b2->right);
    }
}

template <class T>
void BST<T>::Copy(BST<T>& right){
    CopyHelp(root, right.root);
}

template <class T>
void BST<T>::PrintInOrderHelp(BNode<T>* b)const{
    if (b != nullptr){
        PrintInOrderHelp(b->left);
        cout << b->data << "\t";
        PrintInOrderHelp(b->right);
    }
}

template <class T>
void BST<T>::PrintInOrder()const{
	cout << "<\t";
	if (root == nullptr)
        cout << "root is null" << endl;
    PrintInOrderHelp(root);
    cout << ">";
}

template <class T>
void BST<T>::PrintPreOrderHelp(BNode<T>* b)const{
    if (b != nullptr){
        cout << b->data << "\t";
        PrintPreOrderHelp(b->left);
        PrintPreOrderHelp(b->right);
    }
}

template <class T>
void BST<T>::PrintPreOrder()const{
	cout << "<\t";
    PrintPreOrderHelp(root);
    cout << ">" << endl;
}

template <class T>
void BST<T>::PrintPostOrderHelp(BNode<T>* b)const{
    if (b != nullptr){
        PrintPostOrderHelp(b->left);
        PrintPostOrderHelp(b->right);
        cout << b->data << "\t";
    }
}

template <class T>
void BST<T>::PrintPostOrder()const{
	cout << "<\t";
    PrintPostOrderHelp(root);
    cout << ">" << endl;
}

template <class T>
bool BST<T>::SearchHelp(BNode<T>* b, T item)const{
    bool success = false;
    if (b != nullptr && !success){
        success = SearchHelp(b->left, item);
        if (b->data == item && !success)
        {
            if (b->parent == nullptr)
                cout << "NULL" << endl;
            else
                cout << "parent data: " << (b->parent->data) << endl;
            success = true;
        }
        else if (!success)
            success = SearchHelp(b->right, item);
    }
    return success;
}

template <class T>
bool BST<T>::Search(T item)const{
    return SearchHelp(root, item);
}

template <class T>
bool BST<T>::RemoveHelp(BNode<T>*& b, T item){
    bool success = false;
    if (b != nullptr && !success){
        success = RemoveHelp(b->left, item);
        if (b->data == item && !success)
        {
            //if it is the root
            if (b->parent == nullptr)
            {
                //if the root has a right child
                if (b->right != nullptr)
                {
                    BNode<T>* temp;
                    temp = GetMinHelp(b->right);

                    temp->parent = nullptr;
                    temp->left = b->left;
                    if (temp->left != nullptr)
                        temp->left->parent = temp;

                    if (temp != b->right)
                    {
                        temp->right = b->right;
                        if (temp->right->left != nullptr && temp == temp->right->left)
                        {
                            temp->right->left = nullptr;

                            if(temp->right != nullptr)
                                temp->right->parent = temp;

                            if (temp->left != nullptr)
                                temp->left->parent = temp;
                        }
                    }
                    delete(b);
                    b = temp;
                }
                //if the root has a left child
                else if (b->left != nullptr)
                {
                    BNode<T>* temp;
                    temp = b->left;
                    temp->parent = nullptr;
                    delete(b);
                    b = temp;
                }
                //if the root has no child
                else
                {
                    delete(b);
                    b = nullptr;
                }
            }
            //if children are removed
            else
            {
                BNode<T>* temp = nullptr;
                //if the data is to the left of the parent
                if (b->parent->left != nullptr && b->parent->left->data == b->data)
                {
                    if (b->right != nullptr)
                    {
                        temp = b->right;
                        temp->left = b->left;
                        if(temp->right != nullptr)
                                temp->right->parent = temp;

                        if (temp->left != nullptr)
                            temp->left->parent = temp;

                        temp->parent = b->parent;
                    }
                    else
                    {
                        if (temp != nullptr)
                            temp->parent = b->parent;
                    }
                }
                else
                {
                    //if data is to the right of the parent
                    if (b->right != nullptr)
                    {
                        temp = b->right;
                        temp->left = b->left;

                        if(temp->right != nullptr)
                                temp->right->parent = temp;

                        if (temp->left != nullptr)
                            temp->left->parent = temp;

                        temp->parent = b->parent;
                    }
                    else
                    {
                        if (temp != nullptr)
                            temp->parent = b->parent;
                    }
                }
                delete(b);
                b = temp;
            }
            success = true;
        }
        else if (!success)
            success = RemoveHelp(b->right, item);
    }
    return success;
}

template <class T>
bool BST<T>::Remove(T item){
    return RemoveHelp(root, item);
}

template <class T>
BNode<T>* BST<T>::GetMinHelp(BNode<T>* b)const{
    if (b->left != nullptr)
        return GetMinHelp(b->left);
    return b;
}

template <class T>
int BST<T>::GetMin()const{
    if (root == nullptr)
        return INT_MAX;
    return GetMinHelp(root)->data;
}

template <class T>
BNode<T>* BST<T>::GetMaxHelp(BNode<T>* b)const{
    if (b->right != nullptr)
        return GetMaxHelp(b->right);
    return b;
}

template <class T>
int BST<T>::GetMax()const{
    if (root == nullptr)
        return INT_MIN;
    return GetMaxHelp(root)->data;
}

template <class T>
int BST<T>::GetAverageHelp(BNode<T>* b)const{
    int total = 0;
    if (b != nullptr){
        total += b->data;
        total += GetAverageHelp(b->left);
        total += GetAverageHelp(b->right);
    }
    return total;
}

template <class T>
double BST<T>::GetAverage()const{
    return GetAverageHelp(root) / double(Count());
}

template <class T>
int BST<T>::CountHelper(BNode<T>* b)const{
	if (b != nullptr)
		return 1 + CountHelper(b->left) + CountHelper(b->right);
	else
		return 0;
}

template <class T>
int BST<T>::Count()const{
	return CountHelper(root);
}

template <class T>
int BST<T>::CountHeightHelper(BNode<T>* b)const{
	if (b != nullptr){
		return 1 + max(CountHeightHelper(b->left), CountHeightHelper(b->right));
	}
	else
		return 0;
}

template <class T>
int BST<T>::CountHeight()const{
	return CountHeightHelper(root);
}
