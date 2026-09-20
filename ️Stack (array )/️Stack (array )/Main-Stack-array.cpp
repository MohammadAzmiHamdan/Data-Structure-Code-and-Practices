#include"stack.h"
#include <iostream>
using namespace std;
void main() {
	stack s;int x;
	cout << s.is_empty() << endl;
	cout << s.is_full() << endl;
	if (s.top(x))
		cout << "top : " << x << endl;
	else cout << " there is no top " << endl;;
	cout << "----------------------------------\n";
	s.push(9);
	s.push(2);
	s.push(3);
	s.push(4);
	if (s.top(x))
		cout << "top : " << x << endl;
	else cout << " there is no top ";
	s.pop();
	if (s.top(x))
		cout << "top : " << x << endl;
	else cout << " there is no top ";
	s.print_fromTop();
	s.print_fromBottom();

	s.pop();
	s.pop();
	s.print_fromBottom();
	if (s.top(x))
		cout << "top : " << x << endl;
	else cout << " there is no top ";


	s.clear();
	cout << "clear " << endl;
	s.print_fromBottom();
	cout << s.stack_length();
	cout << endl << "-----------" << endl;
	
	s.push(4);
	s.push(3);
	s.push(5);
	s.push(7);
	s.push(6);
	s.print_fromBottom();
	s.swapTopBottom();
	s.print_fromBottom();

}