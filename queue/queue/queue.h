#pragma once
const int size = 5;
class queue {
	int q[::size];
	int front, rear, length;
public:
	queue();
	bool is_empty();
	bool is_full();
	bool append(int el);
	bool retrieve(int& el);
	int retrieve();
	bool serve();
	void print();
	void print2();
	void moveLastToFront();
	int search(int el);
};