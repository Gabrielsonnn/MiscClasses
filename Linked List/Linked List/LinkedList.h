//
//#ifndef LINKEDLIST_H
//#define LINKEDLIST_H
//
//#include <iostream>
//
//using namespace std;
//
//template<class T>
//class DLLNode {//the individual nodes within the linked list
//public:
//	T info;
//	DLLNode *next, *prev;//declares next and previous which are pointers to other nodes
//
//	DLLNode() {
//		next = nullptr;//constructor for node sets next and prev to null
//		prev = nullptr;
//	}
//
//	DLLNode(const T& el, DLLNode *n = nullptr, DLLNode *p = nullptr) {//constructor for node sets values to specified values
//		info = el;
//		next = n;
//		prev = p;
//	}
//
//};
//
//template<class T>
//class DoublyLinkedList {//linked list class for contaning nodes
//protected:
//	DLLNode<T> *head, *tail, *current;//declares head and tail variables
//	int length;
//
//public:
//
//	DoublyLinkedList() {//constructor for class
//		head = nullptr;//sets head and tail to null
//		tail = nullptr;
//		current = nullptr;
//		length = 0;
//	}
//
//	int getLength() { return length; }//gets length
//
//	T getCurrent();//gets current value
//	T getNthNode(int);//gets nth node
//	int incCurrent();//increments current value
//	int decCurrent();//decrements current value
//	void addTail(const T&);
//	void deleteTail();
//	void deleteHead();
//	int deleteNode(const T&);
//	void sortList();
//	void swapData(DLLNode<T>*, DLLNode<T>*);
//	DLLNode<T>* findNode(const T&);
//	int isEmpty();
//	void printAll();
//
//};
//
//template<class T>
//void DoublyLinkedList<T>::addTail(const T& el) {
//	if (tail != nullptr) {//if list is not empty
//		tail = new DLLNode<T>(el, 0, tail);
//		tail->prev->next = tail;
//	}
//	else {//if list is empty
//		head = new DLLNode<T>(el);
//		tail = head;
//		current = head;
//	}
//	length++;//increases length
//}
//
//template<class T>
//void DoublyLinkedList<T>::deleteTail() {
//	//T el = tail->info;
//	if (head == tail) {//if only one node in the list
//		delete head;//deletes the node
//		head = nullptr;//sets head and tail to null
//		tail = nullptr;
//		current == nullptr;
//	}
//	else {//otherwise
//		if (current == tail) //if current is pointing to the node getting deleted
//			current = current->prev;//sets current to previous value
//
//		tail = tail->prev;//sets previous node value to tail
//		delete tail->next;//deletes last node
//		tail->next = nullptr;//sets next in new last node to null
//	}
//	length--;//decreases length
//}
//
//template<class T>
//void DoublyLinkedList<T>::deleteHead() {
//	if (head == tail) {//if only one node in the list
//		delete head;//deletes the node
//		head = nullptr;//sets head and tail to null
//		tail = nullptr;
//		current == nullptr;
//	}
//	else {//otherwise
//		if (current == head) //if current is pointing to the node getting deleted
//			current = current->next;//sets current to next value
//
//		head = head->next;//sets head to next node
//		delete head->prev;//deletes first node
//		head->prev = nullptr;//sets previous to null
//	}
//	length--;//decreases length
//}
//
//template<class T>
//int DoublyLinkedList<T>::deleteNode(const T& el) {
//	DLLNode<T> *tmp;
//
//	tmp = findNode(el);
//	if (tmp == nullptr) {
//		return 0;
//	}
//	if (tmp == tail) {
//		deleteTail();
//	}
//	else if (tmp == head) {
//		deleteHead();
//	}
//	else {
//		if (current == head) //if current is pointing to the node getting deleted
//			current = current->next;//sets current to next value
//
//		tmp->prev->next = tmp->next;//changes prev nodes next to point to next node
//		tmp->next->prev = tmp->prev;//changes next nodes prev to point to prevoius node
//		delete tmp;//deletes node
//		length--;//decreases length
//	}
//	return 1;
//}
//
//template<class T>
//DLLNode<T>* DoublyLinkedList<T>::findNode(const T& el) {
//	DLLNode<T> *tmp;
//	
//	if (isEmpty())//checks if list is empty
//		return nullptr;
//	else {//if not empty
//		tmp = head;//starts temp at head
//
//		if (tmp->info == el)//case for if only one node
//			return tmp;
//
//		while (tmp != tail) {
//			tmp = tmp->next;
//
//			if (tmp->info == el)//check next node
//				return tmp;
//		}
//		return nullptr;//didnt find flNum
//	}
//}
//
//template<class T>
//void DoublyLinkedList<T>::sortList() {
//	int i, j;
//	
//	for (i = 0; i < length - 1; i++) {//n is the size of the array
//
//		//last i elements are already in place
//		for (j = 0; j < length - i - 1; j++) {
//			if ((getNthNode(j)) > (getNthNode(j+1))) {
//				swapData(findNode(getNthNode(j)), findNode(getNthNode(j + 1)));//swaps the two nodes
//			}
//		}
//	}
//}
//
//template<class T>
//void DoublyLinkedList<T>::swapData(DLLNode<T> *node1, DLLNode<T> *node2) {
//	T tmpT;
//
//	tmpT = node1->info;
//	node1->info = node2->info;
//	node2->info = tmpT;
//}
//
//template<class T>
//T DoublyLinkedList<T>::getNthNode(int n) {
//	current = head;
//
//	for (int i = 0; i < n; i++)
//		incCurrent();
//
//	return current->info;
//}
//
//
//template<class T>
//T DoublyLinkedList<T>::getCurrent() {
//	if (current == nullptr) {
//		if (head != nullptr) {
//			current = head;//sets current to first point
//		}
//	}
//	return current->info;
//}
//
//template<class T>
//int DoublyLinkedList<T>::incCurrent() {//increments current value
//	if (current == nullptr || current->next == nullptr || current == tail) {//doesn't increment under following conditions
//		return -1;
//	}
//	else {
//		current = current->next;//increments to next node
//		return 0;
//	}
//}
//
//template<class T>
//int DoublyLinkedList<T>::decCurrent() {//decrements current value
//	if (current == nullptr || current->prev == nullptr || current == head) {//doesn't decrement under following conditions
//		return -1;
//	}
//	else {
//		current = current->prev;//decrements to prev node
//		return 0;
//	}
//}
//
//template<class T>
//int DoublyLinkedList<T>::isEmpty() {//returns 1 if list is empty, returns 0 if list is not empty
//	if (head == nullptr && tail == nullptr)
//		return 1;
//	else
//		return 0;
//}
//
//template<class T>
//void DoublyLinkedList<T>::printAll() {//prints all the information starting from head
//	current = head;
//
//	for (int i = 1; i <= length; i++) {//prints all names
//		cout << i << ") " << getCurrent() << endl;//prints name nicely
//		incCurrent();//increments current
//	}
//	cout << endl;
//}
//
//#endif // !LINKEDLIST_H
//
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template<class T>
class DLLNode {//the individual nodes within the linked list
public:
	T info;
	DLLNode *next, *prev;//declares next and previous which are pointers to other nodes

	DLLNode() {
		next = nullptr;//constructor for node sets next and prev to null
		prev = nullptr;
	}

	DLLNode(const T& el, DLLNode *n = nullptr, DLLNode *p = nullptr) {//constructor for node sets values to specified values
		info = el;
		next = n;
		prev = p;
	}

};

template<class T>
class DoublyLinkedList {//linked list class for contaning nodes
protected:
	DLLNode<T> *head, *tail, *current;//declares head and tail variables
	int length;

public:

	DoublyLinkedList() {//constructor for class
		head = nullptr;//sets head and tail to null
		tail = nullptr;
		current = nullptr;
		length = 0;
	}

	int getLength() { return length; }//gets length

	T getCurrent();//gets current value
	T getNthNode(int);//gets nth node
	int incCurrent();//increments current value
	int decCurrent();//decrements current value
	void addTail(const T&);//adds tail
	void deleteHead();//deletes head
	void deleteTail();//deletes tail
	int deleteNode(const T&);//finds and deletes node
	void sortList();//sorts nodes
	void swapData(DLLNode<T>*, DLLNode<T>*);//swaps two nodes data values
	int searchNode(const T& el);//search nodes and returns a 1 or a 0 if found
	DLLNode<T>* findNode(const T&);//searches for a node and return the node
	int isEmpty();//retruns 1 if empty and 0 if not
	void printAll();//prints all the data in the nodes

};

/*
template<class T>
void DoublyLinkedList<T>::addTail(const T& el) {
	if (tail != nullptr) {//if list is not empty
		tail = new DLLNode<T>(el, 0, tail);
		tail->prev->next = tail;
	}
	else {//if list is empty
		head = new DLLNode<T>(el);
		tail = head;
		current = head;
	}
	length++;//increases length
}

template<class T>
void DoublyLinkedList<T>::deleteHead() {
	if (head == tail) {//if only one node in the list
		delete head;//deletes the node
		head = nullptr;//sets head and tail to null
		tail = nullptr;
		current = nullptr;
	}
	else {//otherwise
		if (current == head) //if current is pointing to the node getting deleted
			current = current->next;//sets current to next value

		head = head->next;//sets head to next node
		delete head->prev;//deletes first node
		head->prev = nullptr;//sets previous to null
	}
	length--;//decreases length
}

template<class T>
void DoublyLinkedList<T>::deleteTail() {
	//T el = tail->info;
	if (head == tail) {//if only one node in the list
		delete head;//deletes the node
		head = nullptr;//sets head and tail to null
		tail = nullptr;
		current = nullptr;
	}
	else {//otherwise
		if (current == tail) //if current is pointing to the node getting deleted
			current = current->prev;//sets current to previous value

		tail = tail->prev;//sets previous node value to tail
		delete tail->next;//deletes last node
		tail->next = nullptr;//sets next in new last node to null
	}
	length--;//decreases length
}

template<class T>
int DoublyLinkedList<T>::deleteNode(const T& el) {
	DLLNode<T> *tmp;

	tmp = findNode(el);
	if (tmp == nullptr) {
		return 0;
	}
	if (tmp == tail) {
		deleteTail();
	}
	else if (tmp == head) {
		deleteHead();
	}
	else {
		if (current == head) //if current is pointing to the node getting deleted
			current = current->next;//sets current to next value

		tmp->prev->next = tmp->next;//changes prev nodes next to point to next node
		tmp->next->prev = tmp->prev;//changes next nodes prev to point to prevoius node
		delete tmp;//deletes node
		length--;//decreases length
	}
	return 1;
}

template<class T>
int DoublyLinkedList<T>::searchNode(const T& el) {//returns 1 if node found, returns 0 if not
	DLLNode<T> *tmp;

	if (isEmpty())//checks if its empty
		return 0;
	else {//if not empty
		tmp = head;//starts temp at head

		if (tmp->info == el)//case for if only one node
			return 1;//found it

		while (tmp != tail) {//continues searching while tmp != tail
			tmp = tmp->next;//increments to next node

			if (tmp->info == el)//check next node
				return 1;//found it
		}
		return 0;//didnt find info
	}
}

template<class T>
DLLNode<T>* DoublyLinkedList<T>::findNode(const T& el) {
	DLLNode<T> *tmp;

	if (isEmpty())//checks if list is empty
		return nullptr;
	else {//if not empty
		tmp = head;//starts temp at head

		if (tmp->info == el)//case for if only one node
			return tmp;

		while (tmp != tail) {
			tmp = tmp->next;

			if (tmp->info == el)//check next node
				return tmp;
		}
		return nullptr;//didnt find flNum
	}
}

template<class T>
void DoublyLinkedList<T>::sortList() {
	int i, j;

	for (i = 0; i < length - 1; i++) {//n is the size of the array

									  //last i elements are already in place
		for (j = 0; j < length - i - 1; j++) {
			if ((getNthNode(j)) >(getNthNode(j + 1))) {
				swapData(findNode(getNthNode(j)), findNode(getNthNode(j + 1)));//swaps the two nodes
			}
		}
	}
}

template<class T>
void DoublyLinkedList<T>::swapData(DLLNode<T> *node1, DLLNode<T> *node2) {
	T tmpT;

	tmpT = node1->info;
	node1->info = node2->info;
	node2->info = tmpT;
}

template<class T>
T DoublyLinkedList<T>::getNthNode(int n) {
	current = head;

	for (int i = 0; i < n; i++)
		incCurrent();

	return current->info;
}


template<class T>
T DoublyLinkedList<T>::getCurrent() {
	if (current == nullptr) {
		if (head != nullptr) {
			current = head;//sets current to first point
		}
	}
	return current->info;
}

template<class T>
int DoublyLinkedList<T>::incCurrent() {//increments current value
	if (current == nullptr || current->next == nullptr || current == tail) {//doesn't increment under following conditions
		return -1;
	}
	else {
		current = current->next;//increments to next node
		return 0;
	}
}

template<class T>
int DoublyLinkedList<T>::decCurrent() {//decrements current value
	if (current == nullptr || current->prev == nullptr || current == head) {//doesn't decrement under following conditions
		return -1;
	}
	else {
		current = current->prev;//decrements to prev node
		return 0;
	}
}

template<class T>
int DoublyLinkedList<T>::isEmpty() {//returns 1 if list is empty, returns 0 if list is not empty
	if (head == nullptr && tail == nullptr)
		return 1;
	else
		return 0;
}

template<class T>
void DoublyLinkedList<T>::printAll() {//prints all the information starting from head
	current = head;

	for (int i = 1; i <= length; i++) {//prints all names
		cout << i << ") " << getCurrent() << endl;//prints name nicely
		incCurrent();//increments current
	}
	cout << endl;
}
*/
#include"LinkedList.cpp"
#endif // !LINKEDLIST_H