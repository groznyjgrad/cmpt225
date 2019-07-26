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
	Node();
	bool isExternal() const;
	bool hasOneChild() const;
	bool isRoot() const;
	void setParentTo(Node* input_parent);
private:
	Customer customer_;
	Node* parent_;
	Node* left_;
	Node* right_;
};

#endif /* NODE_H_ */
