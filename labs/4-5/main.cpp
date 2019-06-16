#include "VertBarChart.h" 
//#include "HorizBarChart.h"

int n1 = 5;
int data1[] = {12, 19, 42, 24, 35};
std::string label1[] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
int scale1 = 4;

void makeGraph1(BarChart& chart) {
    chart.setN(n1);
    chart.setData(data1);
    chart.setLabels(label1);
    chart.setScale(scale1);
    chart.draw();
}

int n2 = 12;
int data2[] = {98, 52, 33, 47, 86, 89, 29, 45, 62, 74, 58, 42};
std::string label2[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int scale2 = 10;

void makeGraph2(BarChart& chart) {
    chart.setN(n2);
    chart.setData(data2);
    chart.setLabels(label2);
    chart.setScale(scale2);
    chart.draw();
}



int main(int argc, char** argv) {
    BarChart* vert_chart = new VertBarChart();
    //BarChart* horiz_chart = new HorizBarChart();

    //makeGraph1(*horiz_chart);
    makeGraph1(*vert_chart);

    //makeGraph2(*horiz_chart);
    makeGraph2(*vert_chart);

    delete vert_chart;
    //delete horiz_chart;
}

