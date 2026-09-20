#include<iostream>
#include "rectangleType.h"
using namespace std;
rectangle::rectangle() {
	width = 0;
	length = 0;
}
rectangle::rectangle(int l, int w) {
	length = l;
	width = w;
}
int rectangle::getLength() {
	return length;
}
int rectangle::getWidth() {
	return width;
}
void rectangle::setLength(int l) {
	length = l;
}
void rectangle::setWidth(int w) {
	width = w;
}
void rectangle::setDimensions(int l, int w) {
	length = l;
	width = w;
}
int rectangle::rectangleArea() {
	return (length * width);
}
int rectangle::rectanglePerimeter() {
	return((2 * length) + (2 * width));
}
int rectangle::rectangleArea(int l, int w) {
	return l * w;
}
int rectangle::rectanglePerimeter(int l, int w) {
	return ((2 * l) + (2 * w));
}
void rectangle::print() {
	cout << "length: " << length << ", width: " << width << " ,area:" << rectangleArea();
	cout << " ,premiter: " << rectanglePerimeter() << endl;
}
rectangle::~rectangle(){
	cout<<"rectangle object has been destroyed!\n";
}
