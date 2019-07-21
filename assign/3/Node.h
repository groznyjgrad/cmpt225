/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"
#include <list>

class Node {
public:
	Customer customer;
	Node* parent;
	Node* left;
	Node* right;
	Node() : customer(), parent(NULL), left(NULL), right(NULL) {}
};

class Position {
public:
	Position(Node* input_node = NULL);
	Customer& operator*(); 
	Position left() const;
	Position right() const;
	Position parent() const;
	bool isRoot() const;
	bool isExternal() const;
private:
	Node* node; 
};
typedef std::list<Position> PositionList;

#endif /* NODE_H_ */

