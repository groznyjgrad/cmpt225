/*
 * BSTree.h
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
public:
	BSTree();
	BSTree(const BSTree& copy_tree); // Copy constructor
	virtual ~BSTree();

	Node* getRoot();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string input_name, char input_initial, int input_balance);

	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string input_name, char input_initial);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string input_name, char input_initial);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string start_name, char start_initial, string end_name, char end_initial);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();

private:
	Node* insertHelper(Node* node, const Customer& insert_customer);
	Node* copyHelper(const Node* to_copy);
	Node* removeHelper(Node* node, const Customer& remove_customer, bool& found);
	bool searchHelper(Node* node, const Customer& find_customer);
	void rangeSearchHelper (Node* node, vector<Customer>& range_customers, 
																			const Customer& start_customer,
																			const Customer& end_customer);
	void printHelper(Node* node);
	Node* root;
	int size;
};

#endif /* BSTREE_H_ */

// It seems like the tree should be ordered with respect to ASCII value, since most of the functions 
// take the name and initial as parameters, so we would want to quickly traverse the tree using the
// order of the name. 