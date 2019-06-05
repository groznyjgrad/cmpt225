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

bool CharList::empty() const {				// returns 1 if empty, 0 if not empty
	return head_->next_ == tail_;
}

void CharList::append(char c) {
 	CharDLL* new_char = new CharDLL;
 	new_char->element_ = c;

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
		list_as_string.push_back(current_node->element_);
		current_node = current_node->next_;
	}
	return list_as_string;
}

void CharList::insert(char c) {
 	CharDLL* new_char = new CharDLL;
 	new_char->element_ = c;

	CharDLL* old_first = head_->next_;		// get pointer to the current first node
	head_->next_ = new_char;				// set first node to newly-inserted node
	old_first->prev_ = new_char;			// set the old first node to point to the new first node

	new_char->prev_ = head_;				
	new_char->next_ = old_first;
}

void CharList::insert(char c, char d) {
	CharDLL* new_char = new CharDLL;
 	new_char->element_ = c;
 	CharDLL* current_node = head_->next_;

 	while (current_node != tail_ && current_node->element_ != d)
 	{
 		current_node = current_node->next_;
 	}
 	// now current node is positioned AT first occurrence of 'd', or tail if 'd' does not occur

 	current_node->prev_->next_ = new_char;
 	new_char->prev_ = current_node->prev_;

 	current_node->prev_ = new_char;
 	new_char->next_ = current_node;
}

void CharList::insert(char c, char d, int n) {

}

void CharList::remove(char c) {
	CharDLL* current_node = head_->next_;
	while (current_node != tail_)
	{
		if (current_node->element_ == c)
		{
			current_node->prev_->next_ = current_node->next_;
			current_node->next_->prev_ = current_node->prev_;
			delete current_node;
			return;							// immediate return means no subsequent 'c' will be removed
		}
		current_node = current_node->next_; // traverse list while current node does not have 'c'
	}
}

void CharList::remove(char c, int n) {
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




int CharList::size() const {}
void CharList::append(char c, char d) {}
void CharList::append(char c, char d, int n) {}

