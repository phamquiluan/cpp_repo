#include <iostream>
using namespace std;

int fibo_recursive(int n);
int fibo_array(int n);


int main(){
	
//	cout << fibo_recursive(43);
	cout << fibo_array(43);
	
	cout << endl;
	return 0;
}


int fibo_recursive(int n){
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

int fibo_array(int n){
	int arr[n + 1];
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i < n + 1; i++)
		arr[i] = arr[i-1] + arr[i-2];

	return arr[n];
}
