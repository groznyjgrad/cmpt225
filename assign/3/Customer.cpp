/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"

Customer::Customer()
: name(NULL),
  initial(NULL),
  balance(0) {}

Customer::Customer(string input_name, char input_initial, int input_balance)
: name(input_name),
  initial(input_initial),
  balance(input_balance) {}

Customer::Customer(const Customer& customer)
: name(customer.getName()),
  initial(customer.getInitial()),
  balance(customer.getBalance()) {}

void Customer::operator=(const Customer& other_customer) {
	name = other_customer.getName();
	initial = other_customer.getInitial();
	balance = other_customer.getBalance();
}

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

ostream& operator<<(ostream& output, Customer& customer) {
	output << customer.getName() << ", " 
	<< customer.getInitial() << ". " 
	<< "(" << customer.getBalance() << ")";
	return output;
}