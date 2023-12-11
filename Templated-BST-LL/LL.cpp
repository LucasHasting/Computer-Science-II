#include "LL.h"

//Node implementation
template <class T>
Node<T>::Node(T d):data(d), next(nullptr){}

template <class T>
Node<T>::Node(T d, Node<T>* n):data(d), next(n){}

//Linked List Implementation
template <class T>
LL<T>::LL():head(nullptr){}

template <class T>
void LL<T>::Copy(const LL<T>& right){
	if (right.head == nullptr)
       head = nullptr;
    else{
       Node<T>* curRight = right.head;
       Node<T>* curLeft = nullptr;
       head = new Node<T>(curRight->data);
       curLeft = head; //curLeft points to node we just created
       curRight = curRight->next;
       while(curRight != nullptr){
           curLeft->next = new Node<T>(curRight->data);
           curRight = curRight->next;
           curLeft = curLeft->next; //curLeft points to node we just created
       }
    }
}
template <class T>
void LL<T>::Destroy(){
	while (head != nullptr){
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template <class T>
LL<T>::LL(const LL<T>& right){
    Copy(right);
}
template <class T>
LL<T>::~LL(){
    Destroy();
}

template <class T>
LL<T>& LL<T>::operator=(const LL<T>& right){
	if (this != &right){
		Destroy();
		Copy(right);
	}
	return *this;
}

template <class U>
ostream& operator<<(ostream& os, const LL<U>& right){
     Node<U>* curr = right.head;
     while (curr != nullptr){
           os << curr->data << "\t";
           curr = curr->next;
     }
     return os;
}

template <class T>
//WORK ON IT
bool LL<T>::operator<(LL right){
    return Count() <= right.Count();
}

template <class T>
bool LL<T>::operator>(LL right){
    return Count() >= right.Count();
}

template <class T>
bool LL<T>::operator==(LL right){
    bool success = true;
    Node<T>* curr = head;
    Node<T>* curr2 = right.head;

    if (Count() != right.Count())
        success = false;

    while (curr != nullptr && success){
           if (curr->data != curr2->data)
               success = false;
           curr = curr->next;
           curr2 = curr2->next;
     }
    return success;
}

template <class T>
bool LL<T>::Insert(T item){
    bool success = true;
    if (head == nullptr || item < head->data){
       head = new Node<T>(item, head);
    }
    else{
        Node<T> *temp = head;
        Node<T> *prev = nullptr;
        while (temp!= nullptr && item > temp->data){
            prev = temp;
            temp = temp->next;
        }
        prev->next = new Node<T>(item, temp);
    }
    return success;
}

template <class T>
void LL<T>::Print()const{
     Node<T>* curr = head;
     while (curr != nullptr){
           cout << curr->data << endl;
           curr = curr->next;
     }
}

template <class T>
int LL<T>::Count()const{
     Node<T>* curr = head;
     int count = 0;
     while (curr != nullptr){
           count++;
           curr = curr->next;
     }
     return count;
}

template <class T>
void LL<T>::Tinker()const{ //only to be used as is with 3 items inserted
    if (head == nullptr)
        return;
    cout<< head->next->next->data << endl;
}


