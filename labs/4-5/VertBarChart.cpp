#include <iostream>
#include <vector>
#include "HorizBarChart.h"

using namespace std;

void VertBarChart::draw() {
	cout << endl;

	vector<int> vec_data(data, data+num);
	vector<string> vec_labels(labels, labels+num);

	VectorGraph* new_vector_graph = VectorGraph(vec_data, vec_labels, scale);
	VectorGraph::draw(std::out);
}