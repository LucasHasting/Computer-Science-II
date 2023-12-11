#include "GoBST.cpp"
#include "LL.cpp"

int main(){
    BST<int> objB1;
    objB1.Insert(5);
    objB1.Insert(4);
    objB1.Insert(6);
    BST<int> objB2 = objB1;
    BST<int> objB3;
    objB3.Insert(5);
    objB3 = objB1;
    cout << objB1 << endl; objB1.Insert(7); objB1.Insert(3);
    cout << objB2 << endl; objB2.Insert(10);
    cout << objB3 << endl;
    cout << endl;
    LL<int> objL1;
    objL1.Insert(5);
    objL1.Insert(4);
    objL1.Insert(6);
    LL<int> objL2 = objL1;
    LL<int> objL3;
    objL3.Insert(5);
    objL3 = objL1;
    cout << objL1 << endl; objL1.Insert(7); objL1.Insert(3);
    cout << objL2 << endl; objL2.Insert(10);
    cout << objL3 << endl;

    LL<BST<int>> objL;
    objL.Insert(objB1);
    objL.Insert(objB2);
    objL.Insert(objB3);
    BST<LL<int>> objB;
    objB.Insert(objL1);
    objB.Insert(objL2);
    objB.Insert(objL3);
    cout << endl << endl;
    cout << "Linked List of BSTs: " << objL << endl << endl;
    cout << "BST of Linked Lists 1: " << objB << endl;
    objB.Remove(objL1);
    cout << "BST of Linked Lists 2: " << objB << endl;
    objB.Remove(objL2);
    cout << "BST of Linked Lists 3: " << objB << endl;
    objB.Remove(objL3);
    cout << "BST of Linked Lists 4: " << objB << endl;
}
