// implement heap
#include <iostream>
#include "heap.h"
using namespace std;

int main() {
	int arr[9] = {4,7,3,5,1,8,2,6,9};
	
	heap* a = buildHeap(arr, 9);	
	
	cout << "My Heap: \n";
   	a->print();
	
	cout << endl;
    return 0;
}

