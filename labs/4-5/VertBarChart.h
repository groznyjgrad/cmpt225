#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "BarChart.h"
#include "VectorGraph.h"

class VertBarChart : public BarChart {
public:
	void setN(int n) { size = n; }			
    void setData(int* data) { this->data = data; }		
    void setLabels(string* labels) { this->labels = labels; }	
    void setScale(int scale) { this->scale = scale; }	
    void draw();
private:	
	int size;
    int* data;
    string* labels;
    int scale;
};

void VertBarChart::draw() {
	cout << endl;

	vector<int> vec_data(data, data+size);
	vector<string> vec_labels(labels, labels+size);

	VectorGraph new_vector_graph(vec_data, vec_labels, scale);
	new_vector_graph.draw(cout);

	cout << endl << endl;
}