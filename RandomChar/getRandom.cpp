/* Purpose of his program is get random character from a array */
/* And I also implement insertion sort here */

#include <iostream>
#include <cstdlib>
using namespace std;

char getRandChar 	();
void InsertionSort 	(char*, int);

int main(){
	char a[10] = {'d','c','a','b','r','e','f','g','j','h'};
	srand(time(0));

	for (int i = 0; i < 10; i++) 
		a[i] = getRandChar();

	cout << "Before sort" << endl;
	for (int i = 0; i < 10; i++) 
		cout << " " << a[i];
	cout << endl;

	InsertionSort(a,10);

	cout << "Sorted" << endl;
	for (int j = 0; j < 10; j++)
		cout << " " << a[j];
	cout << endl;

	return 0;
}

/*------ BEGIN FUNCTION GET RANDOM CHARACTER IN ALPHABET ------*/
char getRandChar(){

	char a[52] = {'q','w','e','r','t','y','u','i','o','p','l','k','j','h','g','f','d','s','a','z','x','c','v','b','n','m','Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
	return a[rand() % 52];
}

/*------ BEGIN SORT FUNCTION USING INSERTION SORT ALGORITHMS ------*/
void InsertionSort(char* a, int n){

	for (int i = 1; i < n; i++){
		char cur = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > cur){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = cur;
	}
}
