// implement radix sort
// author: Luan Pham
// date: 04:07 27-Apr-18
#include <iostream>
#include <cstdlib>
using namespace std;

void radix (int* a, int size);
void printArr (int* arr, int size);
int* createRandomArray (int size);
int  getMax (int *a, int size);
void countSort(int* a, int size, int exp);


int main(){
	srand(time(0));
	int size = 15;

	int* a = createRandomArray(size);
	cout << "\nBefore sort: ";
	printArr(a, size);

	radix(a, size);
	
	cout << "\nAfter sort: ";
	printArr(a, size);
	

	cout << endl;
	return 0;
}


void radix(int* a, int size){
	// Find the maximum number to know number of digits
    int m = getMax(a, size);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(a, size, exp);	
}

void countSort(int* a, int size, int exp){
	int* res = new int[size]; // result array
	int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++)
        count[(a[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        res[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < size; i++)
        a[i] = res[i];	

}

void printArr(int* arr, int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* createRandomArray(int size){
	int* a = new int[size];

	for(int i = 0; i < size; i++)
		a[i] = rand() % 2000;

	return a;
}

int getMax (int *a, int size){
	int max = a[0];
	for(int i = 1; i < size; i++)
		if(a[i] > max)
			max = a[i];
	return max;
}
