//
//  BinaryTree.cpp
//  DataStructurePractice
//
//  Created by Iqbal Ansyori on 1/25/18.
//  Copyright © 2018 Iqbal Ansyori. All rights reserved.
//

#include <iostream>
using namespace std;

class Node {
	
public:
	Node() {
		left = nullptr;
		right = nullptr;
	}
	
	~Node() {
		delete left;
		delete right;
	}
	
	int value;
	Node *left;
	Node *right;
};

class BinaryTree {
	
public:
	BinaryTree();
	~BinaryTree();
	
	void insert(int value);
	void insert(Node *node, int value);
	
	Node *root;
};

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	delete root;
}

void BinaryTree::insert(int value) {
	
	Node *node = new Node();
	node->value = value;
	
	if(!root) {
		root = node;
		return;
	}
	
	if (value < root->value) {
		insert(root, value);
	} else {
		insert(root, value);
	}
}

void BinaryTree::insert(Node *node, int value) {
	
	Node *newNode = new Node();
	newNode->value = value;
	
	if (value < node->value) {
		
		if(!node->left) {
			node->left = newNode;
			return;
		}
		
		insert(node->left, value);
		
	} else {
		
		if(!node->right) {
			node->right = newNode;
			return;
		}
		
		insert(node->right, value);
	}
}

int main() {
	
	BinaryTree *tree = new BinaryTree();
	
	tree->insert(5);
	tree->insert(10);
	tree->insert(20);
	
	cout << tree->root->value << endl;
	cout << tree->root->right->value << endl;
	cout << tree->root->right->right->value << endl;
}
