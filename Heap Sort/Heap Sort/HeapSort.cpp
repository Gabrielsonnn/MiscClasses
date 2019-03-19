template<class T>//sorts in ascending order
void HeapSort<T>::ascHeapsort(T data[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)//turns the array into a heap;
		moveDown(data, i, n - 1);

	for (int i = n - 1; i >= 1; i--) {
		swap(data[0], data[i]);
		moveDown(data, 0, i - 1);
	}
}

template<class T>//heapify's array
void HeapSort<T>::moveDown(T data[], int first, int last) {
	int largest;
	largest = 2 * first + 1;

	while (largest <= last) {
		if (largest < last && data[largest] < data[largest + 1])//finds the largest child
			largest++;

		if (data[first] < data[largest]) {//if child is greater than parent
			swap(data[first], data[largest]);//swap them
			first = largest;//move down
			largest = 2 * first + 1;
		}
		else
			largest = last + 1;//exits while loop
	}
}

template<class T>//sorts in descending order
void HeapSort<T>::decHeapsort(T data[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)//turns the array into a heap;
		moveUp(data, i, n - 1);

	for (int i = n - 1; i >= 1; i--) {
		swap(data[0], data[i]);
		moveUp(data, 0, i - 1);
	}
}

template<class T>//heapify's array
void HeapSort<T>::moveUp(T data[], int first, int last) {
	int smallest;
	smallest = 2 * first + 1;

	while (smallest <= last) {
		if (smallest < last && data[smallest] > data[smallest + 1])//finds the smallest child
			smallest++;

		if (data[first] > data[smallest]) {//if child is greater than parent
			swap(data[first], data[smallest]);//swap them
			first = smallest;//move down
			smallest = 2 * first + 1;
		}
		else
			smallest = last + 1;//exits while loop
	}
}

template<class T>//swaps variables
void HeapSort<T>::swap(T &a, T &b) {
	T tmp;//tmp variable for swapping

	tmp = a;//swaps values
	a = b;
	b = tmp;
}
