// Test Customer.cpp
#include "Customer.h"

int main() {
	Customer cust_a = Customer("Smith", 'B', 5000);
	cout << cust_a << endl;

	cust_a.setBalance(2500);
	cout << cust_a << endl;

	Customer cust_b = Customer("Smith", 'A', 5000);
	if (cust_a <= cust_b) cout << "a <= b" << endl;
	else cout << "not true" << endl;
}