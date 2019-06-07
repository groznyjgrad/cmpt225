class Laboratory {
public:
	void execute() throw (LaboratoryException) {
		throw LaboratoryException("execute() throwing");
		cout << "execute() failed to throw" << endl;
	}
};