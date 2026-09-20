#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;

    int i = 0;
    while (i < 3) {

        int inner = 0;
        while (inner < 2) {

            int x = s;
            if ((x + inner) % 2 == 0) {
                s = x++ + ++x - (x--);
            }
            else {
                s = (--x) + (x++) + (x--);
            }

            if (s % 3 == 1) {
                int t = s;
                s += (t++ + --t);
            }
            else {
                int t = s;
                s -= (--t - t--);
            }

            inner++;
        }

        if (s % 5 == 0) ++s; else --s;

        i++;
    }

    int r = (s % 4 + 4) % 4;

    switch (r) {
    case 0: cout << static_cast<char>(s + 40) << "\n";
    case 1: cout << static_cast<int>(s * 3) << "\n";
    case 2: cout << static_cast<double>(s / 1.4) << "\n";
    case 3: cout << static_cast<long>(s - 5) << "\n";
    default: cout << static_cast<long long>(s) << "\n";
    }

    return 0;
}
