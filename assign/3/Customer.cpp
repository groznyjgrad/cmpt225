/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"

Customer::Customer()
: name("empty"),
  initial(NULL),
  balance(0) {}

Customer::Customer(string input_name, char input_initial, int input_balance)
: name(input_name),
  initial(input_initial),
  balance(input_balance) {}

const string& Customer::getName() const { return name; }

const char& Customer::getInitial() const { return initial; }

const int& Customer::getBalance() const { return balance; }

void Customer::setBalance(int input_balance) { balance = input_balance; }

bool Customer::operator<(const Customer& customer) const {
	if (name != customer.getName()) return (name < customer.getName());
	// otherwise, last names are the same so compare their initials
	return (initial < customer.getInitial());
}

bool Customer::operator<=(const Customer& customer) const {
	if (name <= customer.getName()) return (initial <= customer.getInitial());
	return false;
}

bool Customer::operator>(const Customer& customer) const {
	if (name != customer.getName()) return (name > customer.getName());  
	return (initial > customer.getInitial());
}

bool Customer::operator>=(const Customer& customer) const {
	if (name >= customer.getName()) return (initial >= customer.getInitial());
	return false;
}

bool Customer::operator==(const Customer& customer) const {
	if (name == customer.getName()) return (initial == customer.getInitial());
	return false;
}

bool Customer::operator!=(const Customer& customer) const {
	if (name == customer.getName()) return (initial != customer.getInitial());
	return true;
}

ostream& operator<<(ostream& output, const Customer& customer) {
	output << customer.getName() << ", " 
	<< customer.getInitial() << ". " 
	<< "(" << customer.getBalance() << ")";
	return output;
}