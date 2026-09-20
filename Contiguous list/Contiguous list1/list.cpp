#include "list.h"
#include <iostream>
using namespace std;
template <class t>
list<t>::list() {
    length = 0;
}
template <class t>

list<t>::~list() {

}
template <class t>

bool list<t>::is_empty() {
    return length == 0;
}
template <class t>

bool list<t>::is_full() {
    return length == Size;
}
template <class t>

void list<t>::print() {
    for (int i = 0; i < length; i++) {
        std::cout << l[i] << " " ;
    }
}
template <class t>

void list<t>::add_begin(t el) {
    if (is_full()) cout << "the list is full\n";
    else {
        for (int i = length - 1;i >= 0;i--) {
            l[i + 1] = l[i]; 
        }
        l[0] = el;
        length++;
        cout << "Addition Performed\n";
    }

}
template <class t>

bool list<t>::add_end(t el) {
    if (is_full()) 
        return false;

    l[length] = el;

    length++;
    return true;

}
template <class t>

error list<t>::add_pos(t el, int pos) {
    if (is_full())
        return overflow;
    if (pos<0 || pos>length)
        return out;
    for (int i = length - 1;i >= pos;i--)
        l[i + 1] = l[i];
    l[pos] = el;
    length++;
    return success;



}
template <class t>

void list<t>::add_position(t element, int poition) {

    switch (add_pos(element, poition)) {
    case overflow:cout << "the list is full ! \n";
        break;
    case out:cout << "the position is out of range ! \n";
        break;
    case success:cout << "addetion performed succssefully \n";
        break;


    }


}
template <class t>

bool list<t>::delete_begin() {

    if(is_empty())
        return false;
    for (int i = 1;i < length;i++)
        l[i - 1] = l[i];
    length--;
    return true;

}
template <class t>

bool list<t>::delete_end() {
    if (is_empty())return false;
    length--;
    return true;
}
template <class t>

error list<t>::delete_pos(int pos) {
    if (is_empty())
        return underflow;
    if (pos<0 || pos>length - 1)
        return out;
    for (int i = pos+1;i < length;i++)
    
        l[i-1] = l[i];

    
    length--;
    return success;
}
template <class t>

int list<t>::search(t el) {
    for (int i = 0;i < length;i++) {
        if (i == el)return i;
    }
    return -1;

}
template <class t>

error list<t>::delete_el(t el) {
    int p = search(el);
    if (is_empty())return underflow  ;
    if (p == -1) return out;
    delete_pos(p);


}