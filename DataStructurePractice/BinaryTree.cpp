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
	
	Node *deleteNode(Node *node, int value);
	
	Node *root;
	
private:
	Node *findMin(Node *node);
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

Node* BinaryTree::deleteNode(Node *node, int value) {
	
	if (node == nullptr) {
		return node;
	}
	else if (value < node->value) {
		node->left = deleteNode(node->left, value);
	}
	else if (value > node->value) {
		node->right = deleteNode(node->right, value);
	} else {
		
		if (node->left == nullptr && node->right ==  nullptr) {
			delete node;
			node = nullptr;
		} else if (node->left == nullptr) {
			
			Node *temp = node;
			node = node->right;
			
			delete temp;
			
		} else if (node->right == nullptr) {
			
			Node *temp = node;
			node = node->left;
			
			delete temp;
			
		} else {
			
			Node *temp = findMin(node->right);
			node->value = temp->value;
			node->right = deleteNode(node->right, temp->value);
		}
		
	}
	
	return node;
	
}

Node* BinaryTree::findMin(Node* node) {
	
	Node *toFind = node;
	
	while (toFind->left != nullptr) {
		toFind = toFind->left;
	}
	
	return toFind;
}

int main() {
	
	BinaryTree *tree = new BinaryTree();
	
	tree->insert(5);
	tree->insert(10);
	tree->insert(20);
	tree->insert(7);
	
	cout << tree->root->value << endl;
	cout << tree->root->right->value << endl;
	cout << tree->root->right->right->value << endl;
	cout << tree->root->right->left->value << endl;
	
	tree->deleteNode(tree->root, 10);
	
	cout << "after delete" << endl;
	
	cout << tree->root->value << endl;
	cout << tree->root->right->value << endl;
}
