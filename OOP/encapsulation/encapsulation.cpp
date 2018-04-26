/*
 * Encapsulation is a important principle of OOP, which state that
 * different components of a software system should not reveal the
 * internal details of their respective implementations.
 */

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Human {
	private:
		double height;
		double weight;
	
	public: 
		Human(){
			this->height = 0;
			this->weight = 0;	
		}
		void 	setHeight(double height) { this->height = height; }
		double 	getHeight()	{ return this->height; }
		void 	setWeight(double weight) { this->weight = weight; }
		double 	getWeight() { return this->weight; }
};

int main(){
	Human a;
	
	a.setWeight(65);
	a.setHeight(1.76);
	cout << "Height of Nam: " <<  a.getHeight()  << endl;
	cout << "Weight of Nam: " <<  a.getWeight()  << endl;

	return 0;
}
