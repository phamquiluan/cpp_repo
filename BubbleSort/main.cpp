#include <iostream>
using namespace std;

void swap(int* a, int* b);
void BubbleSort(int* a, int size);
void printArr(int* arr, int size);

int main(){
	int a[11] = {6,12,4,19,22,3,2,15,13,17,30};

	cout << "Before sort:\n";
	printArr(a, 11);	

	BubbleSort(a, 11);
	cout << "After sort:\n";
	printArr(a, 11);


	return 0;
}

void swap(int* a, int* b){ int temp = *a; *a = *b; *b = temp; }

void BubbleSort(int* a, int size){
	bool flag = false;
	for(int i = 0; i < size; i++){
		if(flag == true)
			break;
		flag = true;
		for(int j = size - 1; j > i; j--){
			if(a[j] < a[j - 1]){
				flag = false;
				swap(a + j, a + j - 1);
			}
		}
	}	
}

void printArr(int* arr, int size){
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
