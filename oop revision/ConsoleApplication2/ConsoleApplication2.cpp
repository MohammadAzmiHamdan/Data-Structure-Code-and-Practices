#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main() {
	string name1, name2, name3;
	double grade1, grade2, grade3;
	char temp;
	ifstream input("input.txt");

	getline(input, name1);
	input >> grade1;
	input.get(temp);//input.ignore();

	getline(input, name2);
	input >> grade2;
	input.get(temp);//input.ignore();


	getline(input, name3);  
							
	input >> grade3;
	
	input.close();

	ofstream passed("passed.txt");//cout
	ofstream failed("failed.txt");//cout

	int g = grade1 / 10;//any thing /double =double 

	char sympol;
	switch (g) {
	case 10: 
	case 9: sympol = 'A'; break;
	case 8: sympol = 'B'; break;
	case 7: sympol = 'C'; break;
	case 6: sympol = 'D'; break;
	default:sympol = 'f';
}

	if (grade1 >= 50)
		passed << name1 << "\t" << grade1 << "\t" << sympol << "\t" << " ناجح" << endl;
	else
		failed << name1 << "\t" << grade1 << "\t" << sympol << "\t" << " راسب" << endl;

	 g = grade2 / 10;//double 

	switch (g) {
	case 10:
	case 9: sympol = 'A'; break;
	case 8: sympol = 'B'; break;
	case 7: sympol = 'C'; break;
	case 6: sympol = 'D'; break;
	default:sympol = 'f';
	}

	if (grade2 >= 50)
		passed << name2 << "\t" << grade2 << "\t" << sympol << "\t" << " ناجح" << endl;
	else
		failed << name2 << "\t" << grade2 << "\t" << sympol << "\t" << " راسب" << endl;




	g = grade3 / 10;//double 


	switch (g) {
	case 10:
	case 9: sympol = 'A'; break;
	case 8: sympol = 'B'; break;
	case 7: sympol = 'C'; break;
	case 6: sympol = 'D'; break;
	default:sympol = 'f';
	}

	if (grade3 >= 50)
		passed << name3 << "\t" << grade3 << "\t" << sympol << "\t" << " ناجح" << endl;
	else
		failed << name3 << "\t" << grade3 << "\t" << sympol << "\t" << " راسب" << endl;
	passed << "\n*****تم التصنيف بنجاح *****\n";
	failed << "\n*****تم التصنيف بنجاح *****\n";
	passed.close();
	failed.close();

	return 0;
}