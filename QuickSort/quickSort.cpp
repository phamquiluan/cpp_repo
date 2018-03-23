#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int* a, int* b);
void quickSort(int* a, int left, int right);
int* generateArray(int n);
void printArray(int* a, int size);

int main(){
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	cout << "Generating...\n";

	// generate random array with size n
	srand(time(0));
	int* a = generateArray(n);
	printArray(a, n);

	cout << "\nSorting....\n";
	quickSort(a, 0, n-1);
	printArray(a, n);

	return 0;
}

void printArray(int* a, int size){
	for(int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int* a, int left, int right){
	// local definitions

	if(right > left){
		int j, k;

		// statements
		j = left + 1; 
		k = right;

		// start partition
		while(j < k){
			while(a[j] < a[left] && j <= right){
			   	j++;
			}
			while(a[k] > a[left] && k > left){
			   	k--;
			}
			if(j < k)
				swap(&a[j], &a[k]);
		}
		swap(&a[left], &a[k]);
		// end partition
		quickSort(a, left, k - 1);
		quickSort(a, k + 1,	right);
	}
}

int* generateArray(int n){
	int* newArray = new int[n];

	while(n-- >	0)
		newArray[n] = rand() % 1000;

	return newArray;
}


