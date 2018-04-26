#include <iostream>
#include <cstdlib>
using namespace std;

void radix(int* a);
void printArr(int* arr, int size);
int* createRandomArray(int size);

int main(){
	srand(time(0));

	int* a = createRandomArray(10);
	printArr(a, 10);
		


	return 0;
}


void radix(int* a){
	
}

void printArr(int* arr, int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* createRandomArray(int size){
	int* a = new int[size];

	for(int i = 0; i < size; i++)
		a[i] = rand() % 1000;

	return a;
}
