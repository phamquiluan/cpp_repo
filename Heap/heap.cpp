// max heap
#include <iostream>
#include "heap.h"

using namespace std;

void swap(int* a, int* b){ int temp = *a; *a = *b; *b = temp; } 

heap::heap(){
	arr = new int;
	this->last = -1;
}


heap::heap(int capacity){
	arr = new int[capacity];
	this->last = -1;
}

void reHeapUp(int* arr, int pos){
	if(pos > 0){
		int parent = (pos - 1) / 2;
		if(arr[pos] > arr[parent]){
			swap(arr + pos, arr + parent);
			reHeapUp(arr, parent);
		}
	}
}

void reHeapDown(int* arr, int pos, int last){
	int leftChild 	= 2 * pos + 1;
	int rightChild 	= 2 * pos + 2;
	int largerChild;

	if(leftChild <= last){	// if have left child
		if(rightChild <= last){ // if have right child
			if(arr[leftChild] > arr[rightChild])
				largerChild = leftChild;	
			else
				largerChild = rightChild;
		}
		else{ // no right child
			largerChild = leftChild;	
		}

		// handle
		if(arr[pos] < arr[largerChild])
			swap(arr + pos, arr + largerChild);
	}	
}

heap* buildHeap(int* arr, int size){
	heap* res = new heap;
	for(int i = 0; i < size; i++){
		cout << "insert " << arr[i] << " to heap\n";
		res->arr[i] = arr[i];
		reHeapUp(res->arr, i);
	}
	res->last = size - 1;
	return res;
}

void heap::insertHeap(int data){
	last++;
	this->arr[last] = data;
	reHeapUp(this->arr, last);
}

void heap::deleteHeap(){
	if(this->last == 0){
		last = -1;
	}
	else if(this->last > 0){
		this->arr[0] = this->arr[last];
		last--;
		reHeapDown(this->arr, 0, last);
	}
}

void heap::print(){
	for(int i = 0; i < this->last; i++){	
		cout << this->arr[i] << " ";
	}
}


