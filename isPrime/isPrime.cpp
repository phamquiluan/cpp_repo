#include <iostream>
using namespace std;

bool isPrime(int);

int main(){

	for(int i = 0; i < 1000; i++)
		if (isPrime(i)) cout << i << endl;

	return 0;
}

bool isPrime(int a){
	if (a < 2) 		return false;
	if (a == 2) 	return true;
	if (a%2 == 0) 	return false;

	for (int i = 3; i*i <= a; i++)
		if (a%i == 0) return false;

	return true;
}
