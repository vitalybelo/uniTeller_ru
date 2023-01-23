#include <iostream>
#include "Ident.h"
using namespace std;

int main() {

    Ident ident1("A1.Z9.Z9");

    cout << "\nIDENTIFIER #1: " << ident1.getCurrentValue() << endl;
    cout << "\nSTART INCREMENTS:\n";
    for (int i = 0, n = 0; i < ident1.getBoundSize(); i++, n++) {
        cout << "(" << ident1.counterInc() << ") ";
        if (n == 9) {
            cout << endl;
            n = -1;
        }
    }

    Ident ident2;
    ident2.setCounter("U7.X2.W1");

    cout << "\n\nIDENTIFIER #1: " << ident2.getCurrentValue() << endl;
    cout << "\nSTART INCREMENTS:\n";
    for (int i = 0, n = 0; i < ident2.getBoundSize(); i++, n++) {
        cout << "(" << ident2.counterInc() << ") ";
        if (n == 9) {
            cout << endl;
            n = -1;
        }
    }

    return 0;
}
