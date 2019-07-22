/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "BSTree.h"
#include "Node.h"

BSTree::BSTree() : root(NULL), size(0) {}

Node* BSTree::copyHelper(const Node* to_copy) {
	if (to_copy == NULL) return NULL;
	Node* copy_node = new Node;
	// Copy the edges of the node
	copy_node->parent_ = to_copy->parent_;
	copy_node->left_ = to_copy->left_;
	copy_node->right_ = to_copy->right_;
	// Copy the Customer object
	copy_node->customer_ = Customer( to_copy->customer_.getName(),
		                               to_copy->customer_.getInitial(),
		                               to_copy->customer_.getBalance() );
	// Recursively construct rest of tree
	copyHelper(to_copy->left_);
	copyHelper(to_copy->right_);
	return copy_node;
}

// Use copyHelper method to recursively construct a copy of the input binary tree
// copyHelper will return a pointer to the root of the (deep) copied tree
BSTree::BSTree(const BSTree& copy_tree) { 
	root = copyHelper(copy_tree.root); 
	size = copy_tree.size;
}

BSTree::~BSTree() {
// Probably use another helper method to do post-order traversal and delete 
// the Customer objects followed by the Node objects
}

Node* BSTree::insertHelper(Node* node, const Customer& insert_customer) {
	if (node == NULL) {  // Reached insertion position
		Node* new_node = new Node();
		new_node->customer_ = insert_customer;
		return new_node;
	}
	// Otherwise, traverse tree to find insertion position
	if (insert_customer < node->customer_) node->left_ = insertHelper(node->left_, insert_customer);
	else node->right_ = insertHelper(node->right_, insert_customer);
	return node;
}

// Find the correct insertion position based on ASCII value and add a new external
// node at that position
bool BSTree::insert(string input_name, char input_initial, int input_balance) {
	if (root == NULL) {  // Empty tree
		Node* current_node = new Node();
		current_node->customer_ = Customer(input_name, input_initial, input_balance);
		root = current_node;
		return true;
	}
	Customer insert_customer(input_name, input_initial, input_balance); // To use overloaded operators
	insertHelper(root, insert_customer);
	return false;
}


bool BSTree::remove(string x, char y) {
	return false;
}


bool BSTree::search(string x, char y) {
	return false;
}


vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
}


void BSTree::inOrderPrint() {
}


