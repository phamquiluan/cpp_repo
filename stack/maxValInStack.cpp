#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int data;
	int max;
	node* next;

	node(int data, int max){
		this->data 	= data;
		this->max 	= max;
		this->next 	= NULL;
	}
};

struct stack{
	node* top;
	int size;

	stack(){
		top = NULL;
		size = 0;
	}

	bool isEmpty(){
		return top == NULL;
	}
	
	int getSize(){
		return size;
	}

	void push(int val){
		if(isEmpty()){
			top = new node(val, val);
			return;
		}
		else{
			if(val > top->max){
				node* newnode = new node(val, val);
				newnode->next = top;
				top = newnode;
			}
			else{
				node* newnode = new node(val, top->max);
				newnode->next = top;
				top = newnode;
			}
		}

		size++;
	}

	void pop(){
	 	node* temp = top;
		top = top->next;
		delete temp;
		size--;
	}
	
	int topVal(){
		return this->top->data;
	}

	int maxVal(){
		return this->top->max;
	}

};	

int main() {
	int n;
	cin >> n;

	stack* a = new stack;

	for(int i = 0; i < n; i++){
		int command;
		cin >> command;
		if(command == 1){
			cin >> command;
			a->push(command);
		}
		else if(command == 2){
			a->pop();
		}
		else if(command == 3){
			cout << a->maxVal() << endl;
		}
	}

	return 0;
}


