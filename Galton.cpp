/*
-------------------------------------------------------------------------------------------------
File name       :   GaltonBoard.cpp
Laboratory name :
Author(s)       :   Richard SIERRA
Creation date   :   11.01.22
Description     :   <What does this program do ?>
Remarks         :   <Is there a bug or something ?>
Compiler        :   Apple clang version 13.0.0 (clang-1300.0.29.30)
-------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <random>

#include "Galton.h"

using namespace std;
using vect = vector<int>;

void emptyBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

ostream &operator<<(ostream &os, const vect &v) {
    cout << "(";
    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i;
        if (next(i) != v.end()) {
            cout << ", ";
        }
    }
    cout << ")";

    return os;
}

int readIntBetween(
        const string &message,
        int minVal,
        int maxVal,
        const string &errorMessage
) {
    int  input;
    bool error;

    do {
        cout << message << " [" << minVal << ".." << maxVal << "] : ";

        if (cin >> input)
            error = false;
        else {
            cin.clear();
            error = true;
        }

        if (input < minVal || input > maxVal || error)
            cout << errorMessage << endl;

        emptyBuffer();

    } while (input < minVal || input > maxVal || error);

    return input;
}
