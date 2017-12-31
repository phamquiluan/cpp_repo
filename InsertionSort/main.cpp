#include <iostream>
using namespace std;

void StraightSelectionSort(int* ai, int size);

void printArr(int* arr, int size);

int main(){
	int a[11] = {6,12,4,19,22,3,2,15,13,17,30};

	cout << "Before sort:\n";
	printArr(a, 11);	

	StraightSelectionSort(a, 11);
	cout << "After sort:\n";
	printArr(a, 11);


	return 0;
}

void StraightSelectionSort(int* a, int size){
	if(size > 1){
		int current = 1;
		while(current < size){
			int temp 	= a[current];
			int walker 	= current - 1;
			
			while(walker >= 0 && a[walker] > temp){
				a[walker + 1] = a[walker];
				walker--;
			}
			a[walker + 1] = temp;
			current++;
		}
	}
}

void printArr(int* arr, int size){
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
