#ifndef HEAPSORT_H
#define HEAPSORT_H


template<class T>
class HeapSort {

public:
	void ascHeapsort(T[], int);
	void decHeapsort(T[], int);

private:
	void moveDown(T[], int, int);
	void moveUp(T[], int, int);
	void swap(T&, T&);


};

#include "HeapSort.cpp"
#endif //!HEAPSORT_H