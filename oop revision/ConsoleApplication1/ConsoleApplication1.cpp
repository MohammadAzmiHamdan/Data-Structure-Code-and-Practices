#include "rectangleType.h"
#include < iostream >
#include < string >
using namespace std; 

void  main() {
	 
	rectangle r1;
	cout << "r1\n";
	r1.print();
	rectangle r2(4, 3);
	cout << "r2\n";
	r2.print();
	r1.setDimensions(2,3);
	cout << "r1 after editing \n";
	r1.print();
	rectangle r3;
	r3 = r2;
	cout << "r3\n";
	r3.print();
	r2.setDimensions(7, 8);
	cout << "r2 aftre editing\n";
	r2.print();
	cout << "r3\n";
	r3.print();






}