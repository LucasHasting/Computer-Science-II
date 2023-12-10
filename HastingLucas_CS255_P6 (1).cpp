/*
Name: Lucas Hasting
Project Number: 6
File Name: HastingLucas_CS255_p6.coo
Project Description: Add methods to the BST class
Course: Computer Science
Instructor: Janet T. Jenkins
*/

//************************************************************
// P6: Binary Search Tree Fun
// Author: Janet T. Jenkins
// Use this file as a starting file for Project 6
// You will need to add the appropriate functionality
// to the BST class in order to complete this work.
//************************************************************

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//BNode class declaration
class BNode{
    int data;
    BNode* left;
    BNode* right;
    BNode();
    BNode(int);
    BNode(int, BNode*, BNode*);
    friend class BST;
};

/*
Method Name: BNode
Method Description: Constructor for the BNode Class
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
BNode::BNode(){
    left = right = nullptr;
}

/*
Method Name: BNode
Method Description: Constructor for the BNode Class
Return Value: none
Incoming Parameters: d
Outgoing Parameters: none
*/
BNode::BNode(int d){
    data = d;
    left = right = nullptr;
}

/*
Method Name: BNode
Method Description: Constructor for the BNode Class
Return Value: none
Incoming Parameters: d, l, r
Outgoing Parameters: none
*/
BNode::BNode(int d, BNode* l, BNode* r){
    data = d;
    left = l;
    right = r;
}

//BST class declaration
class BST{
	//data member
    BNode* root;

    //helper methods
    bool InsertHelp(int e, BNode*& b);
    void PrintInOrderHelp(BNode* b)const;
    void PrintPreOrderHelp(BNode* b)const;
    void PrintPostOrderHelp(BNode* b)const;
    int CountHelper(BNode* b)const;
    int CountHeightHelper(BNode* b)const;
    bool SearchHelp(BNode* b, int item)const;
    int GetMinHelp(BNode* b)const;
    int GetMaxHelp(BNode* b)const;
    int GetAverageHelp(BNode* b)const;

public:
    BST();
    bool Insert(int e);
    void PrintInOrder()const;
    void PrintPreOrder()const;
    void PrintPostOrder()const;
	int Count()const;
	int CountHeight()const;
	bool Search(int item)const;
	int GetMin()const;
	int GetMax()const;
	double GetAverage()const;

};

/*
Method Name: BST
Method Description: Constructor for the BST class
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
BST::BST(){
    root = nullptr;
}

/*
Method Name: InsertHelp
Method Description: Helper method for Insert
Return Value: bool
Incoming Parameters: e, b
Outgoing Parameters: b
*/
bool BST::InsertHelp(int e, BNode*& b){
    bool success = false;
    if (b == nullptr){
        b = new BNode(e);
        success = true;
    }
    else{
        if (e < b->data)
            success = InsertHelp(e, b->left);
        else if (e > b->data)
            success = InsertHelp(e, b->right);
        else{
            cout << "NO DUPs" << endl;
            success = false;
        }
    }

    return success;
}

/*
Method Name: Insert
Method Description: Uses InsertHelp to insert data into the BST
Return Value: bool
Incoming Parameters: e
Outgoing Parameters: none
*/
bool BST::Insert(int e){
    return InsertHelp(e, root);
}

/*
Method Name: PrintInOrderHelp
Method Description: Helper method for PrintInOrder, prints the data in order
Return Value: none
Incoming Parameters: b
Outgoing Parameters: none
*/
void BST::PrintInOrderHelp(BNode* b)const{
    if (b != nullptr){
        PrintInOrderHelp(b->left);
        cout << b->data << "\t";
        PrintInOrderHelp(b->right);
    }
}

/*
Method Name: PrintInOrder
Method Description: uses PrintInOrderHelp to print the data in the BST in order
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
void BST::PrintInOrder()const{
	cout << "<\t";
    PrintInOrderHelp(root);
    cout << ">" << endl;
}

/*
Method Name: PrintPreOrderHelp
Method Description: Helper method for PrintPreOrder, prints the data in pre order
Return Value: none
Incoming Parameters: b
Outgoing Parameters: none
*/
void BST::PrintPreOrderHelp(BNode* b)const{
    if (b != nullptr){
        cout << b->data << "\t";
        PrintPreOrderHelp(b->left);
        PrintPreOrderHelp(b->right);
    }
}

/*
Method Name: PrintPreOrder
Method Description: uses PrintPreOrderHelp to print the data in the BST in pre order
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
void BST::PrintPreOrder()const{
	cout << "<\t";
    PrintPreOrderHelp(root);
    cout << ">" << endl;
}

/*
Method Name: PrintPostOrderHelp
Method Description: Helper method for PrintPostOrder, prints the data in post order
Return Value: none
Incoming Parameters: b
Outgoing Parameters: none
*/
void BST::PrintPostOrderHelp(BNode* b)const{
    if (b != nullptr){
        PrintPostOrderHelp(b->left);
        PrintPostOrderHelp(b->right);
        cout << b->data << "\t";
    }
}

/*
Method Name: PrintPostOrder
Method Description: uses PrintPostOrderHelp to print the data in the BST in post order
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
void BST::PrintPostOrder()const{
	cout << "<\t";
    PrintPostOrderHelp(root);
    cout << ">" << endl;
}

/*
Method Name: SearchHelp
Method Description: Helper method for Search, searches for an item in the BST
Return Value: none
Incoming Parameters: b, item
Outgoing Parameters: none
*/
bool BST::SearchHelp(BNode* b, int item)const{
    bool success = false;
    if (b != nullptr && !success){
        success = SearchHelp(b->left, item);
        if (b->data == item && !success)
            success = true;
        else if (!success)
            success = SearchHelp(b->right, item);
    }
    return success;
}

/*
Method Name: Search
Method Description: uses SearchHelp to find a value in the BST
Return Value: none
Incoming Parameters: item
Outgoing Parameters: none
*/
bool BST::Search(int item)const{
    return SearchHelp(root, item);
}

/*
Method Name: GetMinHelp
Method Description: Helper method for GetMin, gets the min value
Return Value: none
Incoming Parameters: b
Outgoing Parameters: none
*/
int BST::GetMinHelp(BNode* b)const{
    if (b->left != nullptr)
        return GetMinHelp(b->left);
    return b->data;
}

/*
Method Name: GetMin
Method Description: uses GetMinHelp to find the min value in the BST
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
int BST::GetMin()const{
    if (root == nullptr)
        return INT_MIN;
    return GetMinHelp(root);
}

/*
Method Name: GetMaxHelp
Method Description: Helper method for GetMax, gets the max value
Return Value: none
Incoming Parameters: b
Outgoing Parameters: none
*/
int BST::GetMaxHelp(BNode* b)const{
    if (b->right != nullptr)
        return GetMaxHelp(b->right);
    return b->data;
}

/*
Method Name: GetMax
Method Description: uses GetMaxHelp to find the max value in the BST
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
int BST::GetMax()const{
    if (root == nullptr)
        return INT_MAX;
    return GetMaxHelp(root);
}

/*
Method Name: GetAverageHelp
Method Description: Helper method for GetAverage, gets the average value
Return Value: none
Incoming Parameters: b
Outgoing Parameters: none
*/
int BST::GetAverageHelp(BNode* b)const{
    int total = 0;
    if (b != nullptr){
        total += b->data;
        total += GetAverageHelp(b->left);
        total += GetAverageHelp(b->right);
    }
    return total;
}

/*
Method Name: GetAverage
Method Description: uses GetAverageHelp to find the average value in the BST
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
double BST::GetAverage()const{
    return GetAverageHelp(root) / double(Count());
}

/*
Method Name: CountHelper
Method Description: Helper method for Count, gets the number of items in the BST
Return Value: none
Incoming Parameters: b
Outgoing Parameters: none
*/
int BST::CountHelper(BNode* b)const{
	if (b != nullptr)
		return 1 + CountHelper(b->left) + CountHelper(b->right);
	else
		return 0;
}

/*
Method Name: Count
Method Description: uses CountHelp to find the number of items in the BST
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
int BST::Count()const{
	return CountHelper(root);
}

/*
Method Name: CountHeightHelper
Method Description: Helper method for CountHeight, gets the max height in the BST
Return Value: none
Incoming Parameters: b
Outgoing Parameters: none
*/
int BST::CountHeightHelper(BNode* b)const{
	if (b != nullptr){
		return 1 + max(CountHeightHelper(b->left), CountHeightHelper(b->right));
	}
	else
		return 0;
}

/*
Method Name: CountHeight
Method Description: uses CountHeightHelp to find the height of the BST
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
int BST::CountHeight()const{
	return CountHeightHelper(root);
}

/*
Function Name: Menu
Method Description: Display a menu
Return Value: none
Incoming Parameters: none
Outgoing Parameters: none
*/
void menu(){
	cout << "+ x - Insert x into the BST" << endl;
	cout << "i - Print the BST inorder" << endl;
	cout << "r - Print the BST preorder" << endl;
	cout << "o - Print the BST postorder" << endl;
	cout << "? x - Search for x in the BST" << endl;
	cout << "c - Print the item count in the BST" << endl;
	cout << "h - Print the height of the BST" << endl;
	cout << " a - Print the average of the values in the BST" << endl;
	cout << "< - Print the minimum value in the BST" << endl;
	cout << "> - Print the maximum value in the BST" << endl;
	cout << "m - Print menu" << endl;
	cout << "q - Quit" << endl;
}

//Main driver
int main(){
    //Create a BST object
	BST tree;

	//declare choice variable
	char choice = 'q';

	//display the menu
	menu();

	//enter the choice
	cin >> choice;

	//pick a method for the BST based on choice
	while (choice != 'q'){
		if (choice == '+'){
			int input;
			cin >> input;
			tree.Insert(input);
		}
		else if (choice == 'i')
			tree.PrintInOrder();


		else if (choice == 'r')
			tree.PrintPreOrder();
		else if (choice == 'o')
			tree.PrintPostOrder();
		else if (choice == '?'){
			int input;
			cin >> input;
			cout << "The value " << input << " is in the tree: " << boolalpha << tree.Search(input) << endl;
		}
		else if (choice == 'c')
			cout << "There are " << tree.Count() << " items in the tree" << endl;
		else if (choice == 'h')
			cout << "The height of this tree is "<< tree.CountHeight() << "." << endl;
		else if (choice == 'a')
			cout << "The average of the tree is: " << tree.GetAverage() << endl;
		else if (choice == '<')
			cout << "The minimum value of the tree is: " << tree.GetMin() << endl;
		else if (choice == '>')
			cout << "The maximum value of the tree is: " << tree.GetMax() << endl;
		else if (choice == 'm')
			menu();
		else{
			cout << "Invalid instruction" << endl;
			menu();
		}
		cout << "-------------------------------------------------" << endl;
		tree.PrintInOrder();
		cout << "-------------------------------------------------" << endl;
		cin >> choice;
	}

    return 0;
}
