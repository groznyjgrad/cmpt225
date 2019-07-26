/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Node.h"

Node::Node() : customer_(), parent_(nullptr), left_(nullptr), right_(nullptr) {}

bool Node::isExternal() const { return (left_ == nullptr && right_ == nullptr); }

bool Node::hasOneChild() const { return ((left_ == nullptr && right_ != nullptr) || (left_ != nullptr && right_ == nullptr)); }

bool Node::isRoot() const { return (parent_ == nullptr); }

void Node::setParentTo(Node* input_parent) { parent_ = input_parent; }