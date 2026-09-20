#include "queue.h"
#include <iostream>
using namespace std;

queue::queue() {
	front = rear = 0;
}

bool queue::is_empty() const
{
	return front==0;
}

void queue::append(int el)
{
	if (front == 0) {
		front = rear = new node(el);
	}
	else {
		rear = rear->next = new node(el);

	}
}

bool queue::serve()
{ if(is_empty())
	return false;
if (front == rear) {
	delete front;
	front = rear = 0;

}
else {

	node* tmp = front;
	front = front->next;
	delete tmp;

}
return true;

}

bool queue::retrieve(int& el)
{    if(is_empty())
	return false;
	el = front->data;
	return true;
}

void queue::clearQueue()
{
	while ( ! is_empty()) {
		serve();
	}
	front = rear = 0;


}

const queue& queue::operator=(const queue& o)
{
	if(! is_empty())
	clearQueue();
	if (!o.is_empty())
	{
		node* t1,*t2;
		t2 = o.front;
		t1 = front = new node(t2->data);
		t2 = t2->next;
		while (t2 != 0) {
			t1->next = new node(t2->data);
			t1 = t1->next;
			t2 = t2->next;



		}
		rear = t1;

	}
	return *this;
}

queue::queue(queue& o)
{

	if (!o.is_empty())
	{
		node* t1, * t2;
		t2 = o.front;
		t1 = front = new node(t2->data);
		t2 = t2->next;
		while (t2 != 0) {
			t1->next = new node(t2->data);
			t1 - t1->next;
			t2 = t2->next;



		}
		rear = t1;

	}
}

queue::~queue()
{

	clearQueue();
}


