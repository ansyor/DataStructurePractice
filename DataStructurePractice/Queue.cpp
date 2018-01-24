//
//  Queue.cpp
//  DataStructurePractice
//
//  Created by Iqbal Ansyori on 1/23/18.
//  Copyright © 2018 Iqbal Ansyori. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
};

class Queue {
	
public:
	Queue();
	~Queue();
	
	void enqueue(int value);
	int dequeue();
	
private:
	Node *front;
	Node *rear;
};

Queue::Queue() {
	front = nullptr;
	rear = nullptr;
}

Queue::~Queue() {
	
	Node *next = front;
	
	while(next) {
		Node *toDelete = next;
		next = next->next;
		delete toDelete;
	}
}

void Queue::enqueue(int value) {
	
	Node *node = new Node();
	node->value = value;
	node->next = nullptr;
	
	if(!front) {
		
		front = node;
		rear = node;
		
		return;
	}
	
	Node *next = front;
	
	while(next->next) {
		next = next->next;
	}
	
	next->next = node;
	rear = node;
}

int Queue::dequeue() {
	
	if(!front) {
		return 0;
	}
	
	Node *node = front;
	front = front->next;
	
	int value = node->value;
	
	delete node;
	
	return value;
}

int main() {
	
	Queue *queue = new Queue();
	
	queue->enqueue(10);
	queue->enqueue(20);
	queue->enqueue(500);
	
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
}
