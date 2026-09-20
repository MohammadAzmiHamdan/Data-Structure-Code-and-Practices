#include"stack.h"
#include <iostream>
using namespace std;
stack::stack() {
	length = 0;
}
bool stack::is_empty() const {

	return length == 0;

}
bool stack::is_full() const {
	return length == ::size;



}
bool stack::push(int el) {
	if (is_full())return false;
	s[length] = el;
	length++;
	return true;
}
bool stack::pop() {
	if (is_empty())return false;
	length--;
	return true;


}
bool stack::top(int& el) const {
	if (is_empty())return false;
	el = s[length - 1];
	return true;


}

void stack::print_fromBottom() const {
	cout << "From Bottom to Top  : ";
	for (int i = 0;i < length;i++)
		cout << s[i] << " ";
	cout <<" "<< endl;


}	
void stack::print_fromTop() const{
	cout << "From Top to Bottom  : ";

	for (int i = length - 1;i >= 0;i--) {
		cout << s[i] << " ";

	}cout <<" "<< endl;

}
void stack::clear() {
	length = 0;
}

int stack::stack_length()
{
	return length;
}

int stack::search(int el)
{
	if (is_empty()) {
		cout << "underflow!!" << endl; 	return -1;
	}
	else {
		for (int i = length - 1;i >= 0;i++) {
			if (el == s[i])
				return i;
		}


		}
	return -1;
}

void stack::copy(stack& a, stack& b)
{
	b.length = 0;
	for (int i = 0;i < a.length;i++)
		b.push(a.s[i]);

}

void stack::deleteGreaterThan(int el)
{
	stack t;
	while (!is_empty()) {
		int x; top(x);
			pop();
			if(x<=el)
		    t.push(x);





	}while (!t.is_empty()) {
		int x; t.top(x);
		push(x);
		t.pop();



	}



}

void stack::deleteUsingPop()
{
	while (!is_empty())pop();
}

void stack::keepEventOnly()
{
	stack tmp;int el;
	while (!is_empty()) {
		top(el);
		pop();
		if (el % 2 == 0)
			tmp.push(el);

	}while (!tmp.is_empty()) {
		tmp.top(el);tmp.pop();
		push(el);



	}
}

void stack::deleteSmallest_All()
{
	if (is_empty())return;
	int el, smallest;top(smallest);stack tmp;
	while (!is_empty()) {
		top(el);
		pop();
		if (el < smallest)smallest = el;
		tmp.push(el);



	}while (!tmp.is_empty()) {
		tmp.top(el);
		tmp.pop();
		if (el != smallest)
		push(el);

	}

}

void stack::deleteFirstSmallest()
{
	if (is_empty())
		return;
	int el, smallest;
	stack tmp;
	top(smallest);
	while (!is_empty()) {
		top(el);
		pop();
		if (el < smallest)
			smallest = el;
		tmp.push(el);

	}
	bool deleted = false;
	while (!tmp.is_empty()) {
		tmp.top(el);
		tmp.pop();
		if (el == smallest && !deleted) {
			deleted = true;
			continue;

		}

		push(el);

	}


}

void stack::moveTopToBottom()
{
	if (is_empty())
		return;
	stack tmp;
	int topEl,el;
	top(topEl);
	pop();
	while (!is_empty())
	{
		top(el);
		pop();
		tmp.push(el);


	}	tmp.push(topEl);

	while (!tmp.is_empty()) {
		tmp.top(el);
		tmp.pop();
		push(el);



	}



}

void stack::reverseStack_useTmpStack()
{
	if (is_empty())return;
	stack s;
	int el;
	while (!is_empty()) {
		top(el);
		pop();
		s.push(el);
	}
	stack reversed;
	while (!s.is_empty()) {
		s.top(el);
		s.pop();
		reversed.push(el);

	} 

	while (!reversed.is_empty()) {
		reversed.top(el);
		reversed.pop();
		push(el);

	}

}
//void stack::reverseStack_NoTmpStack()
//{
//}
void stack::swapTopBottom()
{
	if (is_empty())return;
	int topEl, bottomEl, el;
	stack tmp;
	top(topEl);
	pop();
	while (!is_empty()) {
		top(el);
		pop();
		tmp.push(el);
	}
	bottomEl = el;
	tmp.pop();
	push(topEl);
	while (!tmp.is_empty()) {
		tmp.top(el);
		tmp.pop();
		push(el);
	}push(bottomEl);


}


