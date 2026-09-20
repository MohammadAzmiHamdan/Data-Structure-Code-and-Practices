#include "list.cpp"
#include <iostream>
using namespace std;

int main() {
    list <int>gr;
    gr.add_end(0);
    gr.add_end(1); 
    gr.add_end(2);
    gr.add_end(3);
    gr.add_end(4);
    gr.print();
    cout << endl<<"==============" << endl;
    gr.delete_el(3);
    gr.delete_el(1);
    gr.print();
    cout << endl << "==============" << endl;
    list<string>names;
    names.add_end("mohammad");
    names.add_end("azmi");
    names.add_end("mohammad");
    names.add_end("yousef");
    names.add_end("hamdan");
    names.add_end("coco");

    cout << endl;
    names.print();
    names.delete_pos(3);
    cout << endl;
    names.print();
}
