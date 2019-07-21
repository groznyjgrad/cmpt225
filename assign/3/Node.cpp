/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Node.h"

Position::Position(Node* input_node) : node(input_node) {}

Customer& Position::operator*() { return node->customer; }

Position Position::left() const { return node->left; }

Position Position::right() const { return node->right; }

Position Position::parent() const { return node->parent; }

bool Position::isRoot() const { return (node->parent == NULL); }

bool Position::isExternal() const { return (node->left == NULL && node->right == NULL); }