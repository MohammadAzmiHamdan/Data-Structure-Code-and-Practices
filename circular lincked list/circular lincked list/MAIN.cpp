// circular lincked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"list.h"
#include <iostream>
using namespace std;
int main() {
	list l;
	l.add_begin(1);
	l.add_begin(2);
	l.add_begin(3);
	l.add_begin(4);

	l.add_begin(4);l.add_begin(4);

	l.print();
	l.delete_end();
	l.print();



}