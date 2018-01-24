//
//  Stack.cpp
//  DataStructurePractice
//
//	Implementation Stack with LinkedList
//
//  Created by Iqbal Ansyori on 1/19/18.
//  Copyright © 2018 Iqbal Ansyori. All rights reserved.
//

#include <iostream>
using namespace std;

class Node {
	
public:
	Node(int value) {
		this->value = value;
	}
	
	int value;
	Node *next;
};

class Stack {
	
public:
	Stack();
	Stack(int value);
	~Stack();
	
	void push(int value);
	int pop();
	
private:
	Node *top;
};

Stack::Stack() {
	top = nullptr;
}

Stack::Stack(int value) {
	Node *node = new Node(value);
	top = node;
}

Stack::~Stack() {
	Node *node = top;
	
	while (node) {
		Node *toDelete = node;
		node = node->next;
		delete toDelete;
	}
}

void Stack::push(int value) {
	
	Node *node;
	node = new Node(value);
	
	if(top) {
		node->next = top;
	}
	
	top = node;
}

int Stack::pop() {
	
	struct Node *temp;
	
	if(!top) {
		cout << "\nThe stack is empty!!";
		return 0;
	}
	
	temp = top;
	int value = temp->value;
	top = top->next;
	
	delete temp;
	
	return value;
}

int main() {
	
	Stack *stack = new Stack(5);
	
	stack->push(10);
	stack->push(20);
	stack->push(50);
	
	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
	cout << stack->pop() << endl;
}

