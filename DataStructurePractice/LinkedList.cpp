//
//  main.cpp
//  DataStructurePractice
//
//  Created by Iqbal Ansyori on 1/15/18.
//  Copyright © 2018 Iqbal Ansyori. All rights reserved.
//

#include <iostream>
using namespace std;

class Node {
	
public:
	int value;
	Node *next;
};

class LinkedList {
	
public:
	LinkedList() {
		head = NULL;
	}
	
	~LinkedList() {
		Node *next = head;
		
		while (next) {
			Node *toDelete = next;
			next = next->next;
			delete toDelete;
		}
	}
	
	// Add to the first element
	void addValue(int value) {
		
		Node *newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		
		head = newNode;
	}
	
	// Pop the first value
	int popValue() {
		
		Node *node = head;
		int value = node->value;
		head = node->next;
		
		delete node;
		
		return value;
	}
	
private:
	Node *head;
};

int main() {
	
	LinkedList list;
	
	list.addValue(5);
	list.addValue(20);
	list.addValue(35);
	
	cout << list.popValue() << endl;
	cout << list.popValue() << endl;
	cout << list.popValue() << endl;
	
	return 0;
}
