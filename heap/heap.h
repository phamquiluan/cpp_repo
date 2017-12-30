struct heap{
	int* arr;
	int  last;

	heap();
	heap(int capacity);
	void insertHeap(int data);
	void deleteHeap();
	void print();
};

void reHeapUp	(int* arr, int pos);
void reHeapDown	(int* arr, int pos, int last);
void testfunc();
void swap(int* a, int* b);

heap* buildHeap(int* arr,int size);
