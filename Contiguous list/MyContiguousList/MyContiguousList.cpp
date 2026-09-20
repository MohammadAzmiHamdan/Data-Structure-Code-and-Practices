
#include <iostream>
using namespace std;
const int Size = 6;
enum errorCode{overflow,underflow,out,success};
template <class t>
class list {
    int length;
    t l[Size];
public:
    list() {
        length = 0;

    }
    ~list() {
        cout << "\ndeconstructor worked\n";
    }
    bool is_empty() {
        return length == 0;
    }
    bool is_full() {
        return length == Size;
    }
    errorCode add_begin(t el) {
        if (is_full())return overflow;
        for (int i = length - 1;i >= 0;i--)
            l[i + 1] = l[i];
        l[0] = el;
        length++;
        return success;
    }
    errorCode add_end(t el) {
        if (is_full())return overflow;
        l[length] = el;
        length++;
        return success;

    }
    errorCode add_pos(t el,int pos) {
        if (is_full())return overflow;
        if (pos<0 || pos>length)return out;
        for (int i = length-1;i >= pos;i--) {
            l[i + 1] = l[i];
        }
        l[pos] = el;
        length++;
        return success;


    }
    errorCode delete_begin() {
        if (is_empty())return underflow;
        for (int i = 1;i < length;i++)
            l[i - 1] = l[i];
        length--;
        return success;
    }
    errorCode delete_end() {
        if(is_empty())return underflow;
        length--;
        return success;

    }
    errorCode delete_pos(int pos) {
        if (is_empty())return underflow;
        if (pos<0 || pos>length - 1)return out;
        for (int i = pos + 1;i < length;i++) {
            l[i - 1] = l[i];
        }length--;
        return success;
    }
    int  search(t el) {
        for (int i = 0;i < length;i++)
            if (el == l[i]) return i;
        return -1;

    }
    errorCode delete_el(t el) {
        if (is_empty())
            return underflow;

        int index = search(el);
        if (index == -1)
            return out;

        delete_pos(index);
        return success;
    }

    void print() {
        cout << endl;
        for (int i = 0;i < length;i++) {
            cout << l[i] << " ";

        }
    }





};
int main()
{
    list<int>mylist;
    mylist.add_end(1);
    mylist.add_end(2);
    mylist.add_end(3);
    mylist.add_begin(3);
    mylist.add_begin(555);


    mylist.print();

    mylist.add_pos(555,5);
    mylist.delete_el(555);
    mylist.print();
}

