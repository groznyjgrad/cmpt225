/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
friend class BSTree;
public:
	Node() : customer_(), parent_(NULL), left_(NULL), right_(NULL) {}
	Node* left() const { return left_; }
	Node* right() const { return right_; }
	Node* parent() const { return parent_; }
private:
	Customer customer_;
	Node* parent_;
	Node* left_;
	Node* right_;
};

#endif /* NODE_H_ */

