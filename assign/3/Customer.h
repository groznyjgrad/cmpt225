/*
 * Customer.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	Customer();
	Customer(string input_name, char input_initial, int input_account);
	Customer(const Customer& customer);
	Customer& operator=(const Customer& customer);
	const string& getName() const;
	const char& getInitial() const;
	const int& getAccount() const;
	void setAccount(const int input_account);

	bool operator<(const Customer& customer) const;
	bool operator<=(const Customer& customer) const;
	bool operator>(const Customer& customer) const;
	bool operator>=(const Customer& customer) const;
	bool operator==(const Customer& customer) const;
	bool operator!=(const Customer& customer) const;
private:
	friend ostream& operator<<(ostream& output, Customer& customer);
	string name;
	char initial;
	int account;
};

#endif /* CUSTOMER_H_ */
