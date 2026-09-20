#include"stack.h"
#include<iostream>
using namespace std;

stack::stack()
{
	top_p = 0;

}

void stack::push(int el)
{  
	top_p = new node(el, top_p);

}

bool stack::pop()
{ if(is_empty())
	return false;
node* t = top_p;
top_p = top_p->next;
delete t;
return true;
}

bool stack::top(int& el)
{
	if(is_empty())
	return false;
	el = top_p->data;
	return true;

}

void stack::print() const
{
	node* t = top_p;
	while (t!=0) {
		cout << t->data<<" ";
		t = t->next;

	}
	cout << endl;

}
bool stack::is_empty() const { return top_p == 0; }
stack::~stack()
{
	while (!is_empty())
		pop();


}

stack::stack(stack& o)
{
	if (o.is_empty())
		top_p = 0;
	else {
		node* t1, * t2;
		t2 = o.top_p;
		top_p = new node(t2->data);
		t1 = top_p;
		t2 = t2->next;//we add this line befor loop because we may have just one node in o stack
		while(t2 != 0) {
			t1->next = new node(t2->data);
			t2 = t2->next;
			t1 = t1->next;

		}

	}

}

stack& stack::operator=(stack& o)
{
	if (this == &o) return;
	if(!is_empty())
	clear();
	node* t1, * t2;
	t2 = o.top_p;
	if (t2 != 0) {
		top_p = new node(t2->data);
		t1 = top_p;
		t2 = t2->next;
		while (t2 != 0) {
			t1->next = new node(t2->data);
			t2 = t2->next;
			t1 = t1->next;


		}


	}
	
	return *this;


}

int stack::Size() const
{ if(is_empty())
	return 0;
node* t = top_p;int count = 0;
while (t != 0) {
	count++;
	t = t->next;

}
return count;


}
void stack::clear() {
	while (!is_empty())
		pop();
}

bool stack::bottom(int &el) const
{
	if (is_empty())return false;
	node* t = top_p;
	while (t->next != 0)
		t = t->next;
			el=t->data;
			return true;

}

bool stack::contains(int value) const
{
	if (is_empty())return false;
	node* t = top_p;
	while (t != 0) {
	if (t->data == value)return true;
	t = t->next;
	}
	return false;
}

void stack::duplicateTop()
{
	int el;
	if(!top(el))return;
	push(el);
}

void stack::swapTop()
{
	if (is_empty())return;
	if (Size() < 2)return;
	int t;
	top(t);
	pop();
	int t2;top(t2);
	pop();
	push(t);
	push(t2);
}

void stack::reverse()
{
	if (is_empty())return;
	stack tmp;
	int el;
	while (!is_empty()) {
		top(el);
		pop();
		tmp.push(el);


	}
	*this = tmp;

}

int stack::sum()
{
	int sum = 0, el;
	stack tmp;
	while (!is_empty()) {
		top(el);
		pop();
		tmp.push(el);
		sum += el;

	}
	while (!tmp.is_empty()) {
		tmp.top(el);
		tmp.pop();
		push(el);


	}
	return sum;

}

double stack::average()
{
	if (is_empty()) return 0;
	return double(sum())/Size();
}

void stack::removeFristSameElement(int value)
{
	if (is_empty())return;
	int el;stack tmp; bool deleted = false;
	while (!is_empty()) {
		top(el);
		pop();
		if (el == value && !deleted) {
			deleted = true;
			continue;
		}
		tmp.push(el);


	}while (!tmp.is_empty()) {
		tmp.top(el);
		tmp.pop();
		push(el);
	}



}

void stack::removeAllSameElement(int value)
{   
	if (is_empty()) return;
	while (contains(value) ) {

		removeFristSameElement(value);

	}


}

void stack::printReverse() 
{
	reverse();
	print();
	reverse();


}




