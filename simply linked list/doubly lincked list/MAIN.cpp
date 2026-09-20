#include"list.h"
#include <iostream>
using namespace std;
void main()
{

	list l;
	l.add_begin(1);
	l.add_begin(2);
	l.add_begin(3);
	l.add_begin(4);
	l.print_f();
	l.print_b();
	l.print_b();
	l.add_end(0);
	l.print_b();
	cout << l.size() << endl;
	 l.print_f();
	 l.add_pos(555,1);
	 l.print_f();
	 l.delete_end();
	 l.print_f();
	 l.delete_begin();
	 l.print_f();
	 l.add_begin(7);
	 l.add_begin(9);
	 l.add_begin(5);
	 l.add_begin(1);
	 l.print_f();
	 l.delete_pos(l.size());
	 l.print_f();



}