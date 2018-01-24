//
//  LinkedList3.cpp
//  DataStructurePractice
//
//  Created by Iqbal Ansyori on 1/23/18.
//  Copyright © 2018 Iqbal Ansyori. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
struct Node {
	Node<T> *next;
	T data;
};

template<class T>
class LinkedList {
	
public:
	LinkedList<T>();
	~LinkedList<T>();
	
	void add(T data);
	T get(int index);
	T operator[](int index);
	
private:
	Node<T> *first;
	Node<T> *last;
};

template<class T>
LinkedList<T>::LinkedList() {
	first = nullptr;
	last = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
	
	Node<T> *node = first;
	
	while(node->next) {
		Node<T> *toDelete = node;
		node = node->next;
		
		delete toDelete;
	}
	
	first = nullptr;
	last = nullptr;
}

template<class T>
void LinkedList<T>::add(T data) {
	
	Node<T> *newNode = new Node<T>();
	newNode->data = data;
	
	if(!first) {
		
		first = newNode;
		last = newNode;
		
		return;
	}
	
	Node<T> *node = first;
	
	while (node->next) {
		node = node->next;
	}
	
	node->next = newNode;
	last = newNode;
}

template<class T>
T LinkedList<T>::get(int index) {
	
	if(!first) {
		
		printf("The list is empty!");
		return nullptr;
	}
	
	if(index == 0) {
		return first->data;
	} else {
		
		Node<T> *node = first;
		
		for(int i = 0; i < index; i++) {
			node = node->next;
		}
		
		return node->data;
	}
}

template<class T>
T LinkedList<T>::operator[](int index) {
	return get(index);
}

int main() {
	
	LinkedList<string> list;
	list.add("Hello");
	list.add("Another message");
	list.add("Third message");
	
	cout << list[0] << endl;
	cout << list[1] << endl;
	cout << list[2] << endl;
}
