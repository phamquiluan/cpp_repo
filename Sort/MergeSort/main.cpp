#include <iostream>
using namespace std;

void swap(int* a, int* b);
void MergeSort(int* a, int left, int right);
void printArr(int* arr, int size);
void merge(int* a, int left, int middle, int right);

int main(){
	int a[11] = {6,12,4,19,22,3,2,15,13,17,30};

	cout << "Before sort:\n";
	printArr(a, 11);	

	MergeSort(a, 0, 10);
	cout << "After sort:\n";
	printArr(a, 11);


	return 0;
}

void swap(int* a, int* b){ int temp = *a; *a = *b; *b = temp; }

void merge(int* a, int left, int middle, int right){
	// local definition
	int eleArr1 = middle - left + 1;
	int eleArr2 = right  - middle;

	// create temp array	
	int tempArr1[eleArr1],
		tempArr2[eleArr2];
	
	// copy item from source to 2 temp arr
	for(int i = 0; i < eleArr1; i++){
		tempArr1[i] = a[left + i];
	}
	for(int i = 0; i < eleArr2; i++){
		tempArr2[i] = a[middle + i + 1];
	}
	
	int arrIndex = 0,
		ar1Index = 0,
		ar2Index = 0;

	while(ar1Index < eleArr1 && ar2Index < eleArr2){
		if(tempArr1[ar1Index] > tempArr2[ar2Index]){
			a[arrIndex] = tempArr2[ar2Index];
			ar2Index++;
		}
		else{
			a[arrIndex] = tempArr1[ar1Index];
			ar1Index++;
		}
		arrIndex++;
	}
	// copy arr1 remaining
	while(ar1Index < eleArr1){
		a[arrIndex] = tempArr1[ar1Index];
		ar1Index++;
		arrIndex++;
	}
	// copy arr1 remaining
	while(ar2Index < eleArr2){
		a[arrIndex] = tempArr2[ar2Index];
		ar2Index++;
		arrIndex++;
	}
}

void MergeSort(int* a, int left, int right){
	if(left < right){
		int middle = left + (right - 1) / 2;

		MergeSort(a, left, middle);
		MergeSort(a, middle + 1, right);

		merge(a, left, middle, right);
	}
}	

void printArr(int* arr, int size){
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
