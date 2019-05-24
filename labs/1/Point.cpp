#include "Point.h"
#include <math.h>

using namespace std;


Point::Point(double r, double theta) {
    this->r = r;
    this->theta = theta;
}

Point* Point::makeCartesian(double x, double y) {
	double r = hypot(x,y);
	double theta = atan2(x,y);
    return new Point(r, theta);
}

Point* Point::makePolar(double r, double theta) {
    return new Point(r, theta);
}

double Point::getX() {
    return r*cos(theta);
}

double Point::getY() {
    return r*sin(theta);
}

double Point::getR() {
    return r;
}

double Point::getTheta() {
    return theta;
}

Point* Point::rotate(double alpha){
	return new Point(r, theta+alpha);
}

Point* Point::translate(double dx, double dy){
	double x = getX();
	double y = getY();
	return makeCartesian(x,y);
}

Point* Point::scale(double scaleFactor){
	return new Point(r*scaleFactor, theta);
}
