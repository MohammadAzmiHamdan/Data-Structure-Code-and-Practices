#include <iostream>
using namespace std;
class c {
	int x;
	int y;
	int* p;
public:
	c();
	c(const c& x);
	~c();
	void setXY(int x, int y);
	void setP(int num);
	void print();
	void operator=(const c& x);



};
c::c() {
	x = 0;y = 0;p = 0;
	cout << "constructor called" << endl;

}
c::c(const c& x) {

	p = new int;
	*p = *(x.p);
	this->x = x.x;
	this->y = x.y;
	cout << "cope constructor called\n";


}
c::~c() {
	if (p != 0)delete p;
	cout << "destructor called\n";

}
void c::operator=(const c& x) {
	if (p != 0)delete p;
	p = new int(*(x.p));
	this->x = x.x;
	this->y = x.y;



}
void c::setXY(int x, int y) {

	this->x = x;
	this->y = y;


}
void c::setP(int num) {
	if (p != 0)delete p;
	p = new int;
	*p = num;


}
void c::print() {
	cout << "\n===================================\n";
	cout << "x: " << x<<"\t" << "y: " << y << endl;
	if (p != 0)
		cout << "p: " << p << "\t" << "*p: " << *p << endl;
	else cout << "P is null\n";
	
	cout << "\n===================================\n";

}
void f(c x) {
	cout << "\n---inside f()---\n";
	x.print();
	cout << "\n---leaving f()---\n";


}
int main() {
	
	cout << "\n=== Create o1 and set to x=5,y=10 ===" << endl;
	c o1;
	o1.setXY(5, 10);
	o1.setP(7);
	o1.print();
	cout << "\n=== Create o2 and set to x=555,y=112 ===" << endl;
	c o2;
	o2.setXY(555, 112);
	o2.setP(3);
	o2.print();
	cout << "\n=== Assign o2 = o1 (calls operator=) ===" << endl;
	o2 = o1;
	o1.print();
	o2.print();
	cout << "\n=== Pass o1 to f(o1) (calls copy constructor) ===" << endl;
	f(o1);

	cout << "\n=== End of main ===" << endl;
	return 0;



}