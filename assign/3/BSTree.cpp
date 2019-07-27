/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "BSTree.h"
#include "Node.h"

BSTree::BSTree() : root(nullptr), size(0) {}

// Copies a given node into a new node, and then recursively
// traverses the tree to copy the rest of the nodes. Returns a 
// pointer to the root of the copied tree upon completion.
Node* BSTree::copyHelper(const Node* to_copy) {
	if (to_copy == nullptr) return nullptr;
	Node* copy_node = new Node();
	copy_node->customer_ = to_copy->customer_; // Copies Customer object using overloaded operator.

	copy_node->left_ = copyHelper(to_copy->left_);
	copy_node->left_->setParentTo(copy_node);
	copy_node->right_ = copyHelper(to_copy->right_);
	copy_node->right_->setParentTo(copy_node);
	return copy_node;
}

// Use copyHelper method to create a deep copy of a tree. If the given tree
// is empty, creates an empty tree.
BSTree::BSTree(const BSTree& copy_tree) : root(copyHelper(copy_tree.root)), size(copy_tree.size) {}

// Deletes the tree through deleting each node by post-order.
void BSTree::deleteHelper(Node* node) {
	if (node == nullptr) return;
	deleteHelper(node->left_);
	deleteHelper(node->right_);
	delete node;
}

// Calls deleteHelper to delete the tree.
BSTree::~BSTree() {
	deleteHelper(root);
}

// Recursively traverses a tree according to Customer object comparisons until
// reaching an appropriate external node, then inserts a new node containing the
// input Customer object data. 
Node* BSTree::insertHelper(Node* node, const Customer& insert_customer) {
	if (node == nullptr) {  // Reached insertion position
		Node* new_node = new Node();
		new_node->customer_ = insert_customer;
		return new_node;
	}
	// Otherwise, traverse tree to find insertion position
	if (insert_customer < node->customer_) {
		node->left_ = insertHelper(node->left_, insert_customer);
		node->left_->setParentTo(node);
	}
	else if (insert_customer > node->customer_) { 
		node->right_ = insertHelper(node->right_, insert_customer);
		node->right_->setParentTo(node);
	}
	else node->customer_.setAccount(insert_customer.getAccount()); // Customer already exists.
	return node;
}

// Uses the insertHelper method to insert a new Customer into the tree. 
// If the tree is empty, sets the root to a new node with the given Customer object data.
// If the Customer already exists, their account is updated.
bool BSTree::insert(string input_name, char input_initial, int input_account) {
	Customer insert_customer(input_name, input_initial, input_account); 
	root = insertHelper(root, insert_customer);
	++size;
}

// Recursively traverse tree until the given Customer object is found. Then delete the node
// containing that Customer while restoring the Binary Search Tree structure if it is broken.
// If the Customer is found then set the reference parameter 'found' to true, otherwise it remains
// as false. 
Node* BSTree::removeHelper(Node* node, const Customer& remove_customer, bool& found) {
	if (node == nullptr) return nullptr; // Did not find the customer.
	// Find the customer by traversing the tree appropriately.
	if (remove_customer < node->customer_) node->left_ = removeHelper(node->left_, remove_customer, found);
	else if (remove_customer > node->customer_) node->right_ = removeHelper(node->right_, remove_customer, found);

	else { 
		found = true; 
		// To preserve the tree structure, deletion needs to account for the context of the node to be removed. 
		if (node->isExternal()) { delete node; return nullptr; } // Returning nullptr updates the parent node's child pointer.

		else if (node->hasOneChild()) {
			Node* child = (node->left_ == nullptr ? node->right_ : node->left_);  // Get the child that exists.
			if (node->isRoot()) { delete node; return child; } // Returning child updates the root node of the tree.
			child->setParentTo(node->parent_); delete node; return child; // Otherwise, node is internal.
		}

		else { // The removal node has two children, so find its inorder successor to replace it.
			Node* successor = node->right_;
			if (successor->left_ == nullptr) { // The successor is the right child of the node.
				successor->left_ = node->left_;
				successor->setParentTo(node->parent_);
				delete node; return successor; 
			}
			while (successor->left_ != nullptr) successor = successor->left_; // Left branch exists; travel to successor.
			node->customer_ = successor->customer_; // Place successor Customer into node Customer (swapping positions).
			if (successor->isExternal()) { delete successor; return node; }
			else { // The successor has a right subtree.
				successor->right_->setParentTo(successor->parent_);
				successor->parent_->left_ = successor->right_; 
				delete successor; return node;
			}
		}
	}
}

// Calls removeHelper to find and remove the Customer object with name 'input_name' and
// initial 'input_initial'. If the Customer is found and removed, returns true, otherwise returns false.
bool BSTree::remove(string input_name, char input_initial) {
	Customer remove_customer(input_name, input_initial, 0);  // Account value does not affect comparison.
	bool found = false;
	root = removeHelper(root, remove_customer, found);
  return found;
}

// Recursively traverse the tree to find the given Customer object. If the Customer
// is found then the function returns true, otherwise it returns false.
bool BSTree::searchHelper(Node* node, const Customer& find_customer) {
	if (node == nullptr) return false;
	if (find_customer == node->customer_) return true;
	if (find_customer > node->customer_) searchHelper(node->right_, find_customer);
	else searchHelper(node->left_, find_customer);
}

// Calls searchHelper to find the given Customer object. Returns the
// boolean that is returned by searchHelper.
bool BSTree::search(string input_name, char input_initial) {
	Customer find_customer(input_name, input_initial, 0);
	return searchHelper(root, find_customer);
}

// Searches through the tree and adds any Customer object X where start_customer <= X <= end_customer to the vector.
void BSTree::rangeSearchHelper (Node* node, vector<Customer>& range_customers, 
																						const Customer& start_customer,
																						const Customer& end_customer) {
	if (node == nullptr) return;
	if (node->customer_ > start_customer) rangeSearchHelper(node->left_, range_customers, start_customer, end_customer);
	if (node->customer_ >= start_customer && node->customer_ <= end_customer) range_customers.push_back(node->customer_);
	if (node->customer_ < end_customer) rangeSearchHelper(node->right_, range_customers, start_customer, end_customer);
} 

// Calls rangeSearchHelper to search through the tree for Customers between and including the input name
// and initials. Returns a vector containing any such Customers.
vector<Customer> BSTree::rangeSearch(string start_name, char start_initial, string end_name, char end_initial) {
	vector<Customer> range_customers;
	Customer start_customer(start_name, start_initial, 0);
	Customer end_customer(end_name, end_initial, 0);
	rangeSearchHelper(root, range_customers, start_customer, end_customer);
	return range_customers;
}

// Traverses tree inorder and prints Customer object data to cout.
void BSTree::printHelper(Node* node) {
	if (node == nullptr) return;
	printHelper(node->left_);
	cout << node->customer_ << endl;
	printHelper(node->right_);
}

// Calls printHelper to print Customer object data in order.
void BSTree::inOrderPrint() {
	printHelper(root);
}


