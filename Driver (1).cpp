#include "GoBST.cpp"

void menu();

int main(){
	BST<int> tree;
	char choice = 'q';
	menu();
	cin >> choice;
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
		else if (choice == '-'){
			int input;
			cin >> input;
			cout << "The value " << input << " has been removed from the tree: " << boolalpha << tree.Remove(input) << endl;
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

void menu(){
	cout << "+ x - Insert x into the BST" << endl;
	cout << "- x - Remove x into the BST" << endl;
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
