
#include "HeapSort.h"
#include <iostream>

using namespace std;

int main() {

	HeapSort<int> HP;

	int array1[] = { 5,8,1,7,8,4,9,2,0,0,4,8,5 };


	for (int i = 0; i < 13; i++) {
		cout << array1[i] << endl;
	}

	HP.decHeapsort(array1, 13);

	cout << endl << endl;

	for (int i = 0; i < 13; i++) {
		cout << array1[i] << endl;
	}

	system("pause");
}