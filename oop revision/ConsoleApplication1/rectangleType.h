#pragma once
class rectangle {
	int length;
	int width;
public:
	rectangle();
	rectangle(int l, int w);
	int getLength();
	int getWidth();
	void setLength(int l);
	void setWidth(int w);
	void setDimensions(int l,int w);
	int rectangleArea();
	int rectanglePerimeter();
	void print();
	int rectangleArea(int l, int w);
	int rectanglePerimeter(int l, int w);
	~rectangle();
};