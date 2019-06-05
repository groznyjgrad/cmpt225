// charList class implementation

// Spencer Sixuan Zeng (301383115)
// CMPT225 Summer 2019
// Assignment 1: Due June 12 2019

#include "charList.h"
using namespace std;

// CharDLL methods
CharDLL::CharDLL() {
	c_ = NULL;
	prev_ = NULL;
	next_ = NULL;
}

CharDLL::~CharDLL() {}

// CharList methods

bool CharList::empty() const {				// returns 1 if empty, 0 if not empty
	return head_->next_ == tail_;
}

void CharList::append(char c) {
 	CharDLL* new_char = new CharDLL;
 	new_char->c_ = c;

	CharDLL* old_last = tail_->prev_;		// get pointer to the current last node
	tail_->prev_ = new_char;				// set last node to newly-appended node
	old_last->next_ = new_char;				// set the old last node to point to the new last node

	new_char->prev_ = old_last;				
	new_char->next_ = tail_;
}

CharList::CharList(string str) {
	head_ = new CharDLL;
	tail_ = new CharDLL;
	head_->next_ = tail_;
	tail_->prev_ = head_;

	for (int i = 0; i < str.length(); ++i)
	{
		append(str.at(i));			    	// construct CharList containing 's' through repeated appends
	}
}

CharList::~CharList() {
	while (!empty())
	{
		CharDLL* remove_node = head_->next_;	// unlink the first node and delete it
		head_->next_ = remove_node->next_;	// link the subsequent chain of nodes back to the head sentinel
		delete remove_node;
	}
	// now all nodes are deleted, so delete sentinel nodes
	delete head_;
	delete tail_;
}

string CharList::to_string() {
	string list_as_string;
	CharDLL* current_node = head_->next_;

	while (current_node != tail_)			// traverse list and append nodes
	{
		list_as_string.push_back(current_node->c_);
		current_node = current_node->next_;
	}
	return list_as_string;
}




int CharList::size() const {}
void CharList::insert(char c) {}
void CharList::insert(char c, char d) {}
void CharList::insert(char c, char d, int n) {}
void CharList::append(char c, char d) {}
void CharList::append(char c, char d, int n) {}
void CharList::remove(char c) {}
void CharList::remove(char c, int n) {}	


