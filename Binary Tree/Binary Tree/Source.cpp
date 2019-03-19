
#include "BinaryTree.h"
#include<iostream>

using namespace std;

int main() {

	BinaryTree<int> bt;

	bt.insertNode(5);
	bt.insertNode(4);
	bt.insertNode(8);
	bt.insertNode(10);
	bt.insertNode(6);
	bt.insertNode(1);

	bt.preorderPrint();
	
	cout << bt.searchNode(1) << endl;

	system("pause");
}