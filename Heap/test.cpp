#include <iostream>
using namespace std;

int main(){
	int* a = new int;

	a[1] = 4;

	cout << a[1] << " " << a[0];
	cout << endl;
	return 0;
}
