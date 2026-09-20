
#include <iostream>
#include"queue.h"
using namespace std;
/*
* add-rear ==>append(enqueue)
* delete-front ==> serve(dequeue)
* retrieve  ==> return front  element

*/

queue::queue()
{
	length = 0;
	front = 0;
	rear = ::size - 1;
}

bool queue::is_empty()
{
	return length == 0;
}

bool queue::is_full()
{
	return length == ::size;
}

bool queue::append(int el)
{   if(is_full() )
	return false;
	/*if (rear == ::size - 1)
		rear = 0;
	else
		rear++; */ 

      rear = (rear + 1) % ::size;

	q[rear] = el;
	length++;

	return true;
}

bool queue::retrieve(int& el)
{  
	if(is_empty())
	return false;

	el = q[front];
	return true;


}

int queue::retrieve()
{
	return q[front];
}

bool queue::serve()
{
	if (is_empty())
		return false;
	front = (front + 1) % ::size;
	length--;
	return true;
}

void queue::print()
{
	int count = 0, index = front;
	while (count < length) {
		cout << q[index] << " ";
		index = (index + 1) % ::size;
		count++;

	}cout << endl;
	
}

void queue::print2()
{
	queue tmp; int top;
	while (!is_empty()) {
		retrieve(top);
		serve();
		tmp.append(top);
		cout << top << "  ";


	}
	while (!tmp.is_empty()) {
		tmp.retrieve(top);
		tmp.serve();
		append(top);
		
	}

}

void queue::moveLastToFront()
{
	if(length<=1)
	return;
	queue tmp;
	int el;
	while (length > 1) {
		retrieve(el);
		serve();
		tmp.append(el);
	}
	
	while (!tmp.is_empty()) {
		tmp.retrieve(el);
		tmp.serve();
		append(el);

	}


}

int queue::search(int el)
{
	int pos = -1;
	if(!is_empty())
	{
		int count = 0, i = front;
		while (count < length) {

			if (q[i] == el) {
				pos = i;
				cout << "found in logical index : " << count;
				cout << " and physical index : "<< pos;
				return pos;
			}
			i = (i + 1) % ::size;
			count++;

		}



	}
	else cout << "underflow!! the queue is empty " << endl;
	return pos;
}


