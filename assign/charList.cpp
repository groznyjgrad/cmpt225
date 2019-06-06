// charList class implementation

// Spencer Sixuan Zeng (301383115)
// CMPT225 Summer 2019
// Assignment 1: Due June 12 2019

#include "charList.h"

using namespace std;

// CharDLL methods

CharDLL::CharDLL() {
	element_ = NULL;
	prev_ = NULL;
	next_ = NULL;
}

CharDLL::~CharDLL() {}

// CharList methods

bool CharList::Empty() const {        // returns 1 if empty, 0 if not empty
	return (head_->next_ == tail_);
}

void CharList::Append(char c) {
	CharDLL* new_char = new CharDLL;
	new_char->element_ = c;

	CharDLL* old_last = tail_->prev_;   // get pointer to the current last node
	tail_->prev_ = new_char;        		// set last node to newly-appended node
	old_last->next_ = new_char;      	  // set the old last node to point to the new last node

	new_char->prev_ = old_last;       
	new_char->next_ = tail_;
}

void CharList::Append(char c, char d) {
	CharDLL* new_char = new CharDLL;
	new_char->element_ = c;
	CharDLL* current_node = head_->next_;

	while (current_node != tail_ && current_node->element_ != d) {
		current_node = current_node->next_;
	}
	// current_node is positioned at first occurrence of 'd',
	// or tail if 'd' did not occur

	if (current_node == tail_) {
		tail_->prev_->next_ = new_char; 	// connect rest of list to new node first
		new_char->prev_ = tail_->prev_;

		new_char->next_ = tail_;
		tail_->prev_ = new_char;
		return;
	}

	// current_node is at 'd'
	current_node->next_->prev_ = new_char;  // nb: this is undefined if current_node == tail_
	new_char->next_ = current_node->next_;  

	new_char->prev_ = current_node;
	current_node->next_ = new_char;
}


void CharList::Append(char c, char d, int n) {
	CharDLL* new_char = new CharDLL;
	new_char->element_ = c;
	CharDLL* current_node = head_->next_;
	int count = 0;

	while (current_node != tail_ && count < n) {
		if (current_node->element_ == d) {
			count++;
			if (count == n) {break;}
		}
		current_node = current_node->next_;
	}

	if (current_node == tail_) {
		tail_->prev_->next_ = new_char; 
		new_char->prev_ = tail_->prev_;

		new_char->next_ = tail_;
		tail_->prev_ = new_char;
		return;
	}

	current_node->next_->prev_ = new_char;  
	new_char->next_ = current_node->next_;  

	new_char->prev_ = current_node;
	current_node->next_ = new_char;
}

CharList::CharList(string str) {
	head_ = new CharDLL;
	tail_ = new CharDLL;
	head_->next_ = tail_;
	tail_->prev_ = head_;

	for (int i = 0; i < str.length(); ++i) { Append(str.at(i)); } 
}

CharList::~CharList() {
	while (!Empty())
	{
		CharDLL* remove_node = head_->next_;  // unlink the first node 
		head_->next_ = remove_node->next_;    // link the rest of the list back to the head sentinel
		delete remove_node;
	}
	// now all internal nodes are deleted, so delete sentinel nodes
	delete head_;
	delete tail_;
}

string CharList::ToString() {
	string list_as_string;
	CharDLL* current_node = head_->next_;

	while (current_node != tail_)     // traverse list nodes and build string
	{
		list_as_string.push_back(current_node->element_);
		current_node = current_node->next_;
	}
	return list_as_string;
}

void CharList::Insert(char c) {
	CharDLL* new_char = new CharDLL;
	new_char->element_ = c;

	CharDLL* old_first = head_->next_;    // get pointer to the current first node
	head_->next_ = new_char;      		 	  // set first node to newly-inserted node
	old_first->prev_ = new_char;     		  // set the old first node to point to the new first node

	new_char->prev_ = head_;        
	new_char->next_ = old_first;
}

void CharList::Insert(char c, char d) {
	CharDLL* new_char = new CharDLL;
	new_char->element_ = c;
	CharDLL* current_node = head_->next_;

	while (current_node != tail_ && current_node->element_ != d)
	{
		current_node = current_node->next_;
	}
	// current_node is positioned at first occurrence of 'd',
	// or tail if 'd' did not occur

	current_node->prev_->next_ = new_char;
	new_char->prev_ = current_node->prev_;
	
	current_node->prev_ = new_char;
	new_char->next_ = current_node;
}

void CharList::Insert(char c, char d, int n) {
	CharDLL* new_char = new CharDLL;
	new_char->element_ = c;
	CharDLL* current_node = head_->next_;
	int count = 0;

	while (current_node != tail_)
	{
		if (current_node->element_ == d)
		{
			count++;
			if (count == n) {break;}
		}
		current_node = current_node->next_;
	}

	current_node->prev_->next_ = new_char;
	new_char->prev_ = current_node->prev_;

	current_node->prev_ = new_char;
	new_char->next_ = current_node;
}

void CharList::Remove(char c) {
	CharDLL* current_node = head_->next_;
	while (current_node != tail_)
	{
		if (current_node->element_ == c)
		{
			current_node->prev_->next_ = current_node->next_;
			current_node->next_->prev_ = current_node->prev_;
			delete current_node;
			return;             // immediate return means no subsequent 'c' will be removed
		}
		current_node = current_node->next_; 		// traverse list while current node does not have 'c'
	}
}

void CharList::Remove(char c, int n) {
	CharDLL* current_node = head_->next_;
	int count = 0;
	while (current_node != tail_)
	{
		if (current_node->element_ == c)
		{
			count++;
			if (count == n)
			{
				current_node->prev_->next_ = current_node->next_;
				current_node->next_->prev_ = current_node->prev_;
				delete current_node;
				return; 
			}         
		}
		current_node = current_node->next_; 
	}
}

int CharList::Size() const {
	int count = 0;
	CharDLL* current_node = head_->next_;
	if (current_node == tail_) {return 0;}

	while (current_node != tail_)
	{
		count++;
		current_node = current_node->next_;
	}
	return count;
}


// Notes
// - Copied and pasted test code without changing cout variable name, this led to us thinking
//   there was an error in the function, but there was not
// - A number of segmentation faults during testing were due to misassignment of node pointers 
//   by methods such that at runtime the program was trying to access methods of a NULL pointer
// - Use str.at(i) to return the char at index i of string 'str'. Do not use str.data()
// - There always exists a non-NULL current_node->prev_->next_ but this is not the case for
//   current_node->next_->prev_; if current_node == tail_ then the latter is undefined (seg faults)