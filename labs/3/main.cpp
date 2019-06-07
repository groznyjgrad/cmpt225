#include <iostream>
#include "RuntimeException.h" // has <string> and using namespace std
#include "Laboratory.h"

void test1() {
    try {
        throw RuntimeException("Some error");
        cout << "failed to throw in test1" << endl;
    }
    catch (RuntimeException& exception) {
        cout << "test1() passed. " << exception.getMessage() << endl;
    }
}

void test2() {
	for (int i = 1; i < 11; ++i) {
		try {
			if (i == 4) {
				throw RuntimeException("Throwing at i = 4.");
			}
		}
		catch (RuntimeException& exception) {
			cout << "test2() passed at i = " << i << endl;
			return;
		}
	}
	cout << "failed to throw in test2()" << endl;
}

void test3() {
	for (int i = 1; i < 11; ++i) {
		try {
			if (i == 4) {
				throw LaboratoryException("Throwing at i = 4.");
			}
		}
		catch (RuntimeException& exception) {
			cout << "test3() passed at i = " << i << endl;
			return;
		}
	}
	cout << "failed to throw in test3()" << endl;
}

void test4() {
	try {
		Laboratory lab_object;
		lab_object.execute();
	}
	catch (LaboratoryException& exception) {
		cout << "test4() passed with error " << exception.getMessage() << endl;
		// Note that the object that exists here is not type Laboratory but
		// is the object thrown by execute(), which is type LaboratoryException 
		// Therefore, we call the method on 'exception', not 'new_lab_obj'
	}
}


int main() {
	test1();
	test2();
	test3();
	test4();
}