#include <string>
using namespace std;

class RuntimeException {
private:
    string errorMsg;
public:
    RuntimeException(const string& err) { errorMsg = err; }
    string getMessage() const { return errorMsg; }
};

class LaboratoryException : public RuntimeException {
public:
	LaboratoryException(const string& err)
	  : RuntimeException(err) {}
};