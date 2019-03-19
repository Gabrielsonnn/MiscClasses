#include<iostream>
#include<string>

#include "LinkedList.h"


using namespace std;

int main() {
	DoublyLinkedList <string> DL;
	
	DL.addTail("Justin");
	//cout << DL.getLength() << endl;
	DL.addTail("Johnson,Gabe");
	//cout << DL.getLength() << endl;
	DL.addTail("queen");
	//cout << DL.getLength() << endl;
	DL.addTail("queenn");
	//cout << DL.getLength() << endl;
	DL.addTail("Jalam");
	//cout << DL.getLength() << endl;
	//cout << DL.getNthNode(0) << endl;
	DL.sortList();
	for(int i = 0; i < 5; i++)
		cout << DL.getNthNode(i) << endl;
	
	
	


	system("pause");


}
