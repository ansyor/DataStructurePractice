//
//  LinkedList2.cpp
//  DataStructurePractice
//
//  Created by Iqbal Ansyori on 1/18/18.
//  Copyright © 2018 Iqbal Ansyori. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
	Node *previous;
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
	
	void addValue(int value) {
		
		Node *node = new Node();
		node->value = value;
		node->next = head;
		
		head = node;
	}
	
	int popValue() {
		
		Node *node = head;
		int value = node->value;
		
		head = node->next;
		delete node;
		
		return value;
	}
	
	// Add to last value
	void addLastValue(int value) {
		
		Node *node = head;
		
		while(node->next) {
			node = node->next;
		}
		
		Node *newNode = new Node();
		newNode->value = value;
		node->next = newNode;
	}
	
private:
	Node *head;
};

int main() {
	
	LinkedList list;
	
	list.addValue(20);
	list.addValue(50);
	list.addValue(70);
	list.addLastValue(15);
	
	cout << list.popValue() << endl;
	cout << list.popValue() << endl;
	cout << list.popValue() << endl;
	cout << list.popValue() << endl;
	
}
