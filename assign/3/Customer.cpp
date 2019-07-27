/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"

Customer::Customer()
: name(),
  initial(),
  account(0) {}

Customer::Customer(string input_name, char input_initial, int input_account)
: name(input_name),
  initial(input_initial),
  account(input_account) {}

Customer::Customer(const Customer& customer)
: name(customer.getName()),
  initial(customer.getInitial()),
  account(customer.getAccount()) {}

Customer& Customer::operator=(const Customer& other_customer) {
	if (this != &other_customer) {
		name = other_customer.getName();
 		initial = other_customer.getInitial();
		account = other_customer.getAccount();
	}
	return *this;
}

const string& Customer::getName() const { return name; }

const char& Customer::getInitial() const { return initial; }

const int& Customer::getAccount() const { return account; }

void Customer::setAccount(const int input_account) { account = input_account; }

bool Customer::operator<(const Customer& customer) const {
	if (name != customer.getName()) return (name < customer.getName());
	// otherwise, last names are the same so compare their initials
	return (initial < customer.getInitial());
}

bool Customer::operator<=(const Customer& customer) const {
	if (name == customer.getName()) return (initial <= customer.getInitial());
	if (name < customer.getName()) return true;
	return false;
}

bool Customer::operator>(const Customer& customer) const {
	if (name != customer.getName()) return (name > customer.getName());  
	return (initial > customer.getInitial());
}

bool Customer::operator>=(const Customer& customer) const {
	// Only if last names are equal do we care about comparing the initials
	if (name == customer.getName()) return (initial >= customer.getInitial());
	// Otherwise if the last name is greater, then the whole Customer object is 
	// greater, even if the initial is less than.
	if (name > customer.getName()) return true;
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
	<< "(" << customer.getAccount() << ")";
	return output;
}