/*
Data abstraction is one of the most essential and important feature of object oriented programming in C++. Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.

 Consider a real life example of a man driving a car. The man only knows that pressing the accelerators will increase the speed of car or applying brakes will stop the car but he does not know about how on pressing accelerator the speed is actually increasing, he does not know about the inner mechanism of the car or the implementation of accelerator, brakes etc in the car. This is what abstraction is.
 */

#include <iostream>
using namespace std;
 
class implementAbstraction{
    private:
        int a, b;
 
    public:
        void set(int a, int b){
            this->a = a;
            this->b = b;
        }
         
        void display(){
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
        }
};
 
int main() {
    implementAbstraction obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}



