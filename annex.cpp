/*
-------------------------------------------------------------------------------------------------
File name       :   annex.cpp
Author(s)       :   Richard SIERRA
Creation date   :   18.1.21
Description     :   This file contains functions declarations of various functions
                    used in the program
Comments        :   -
Compiler        :   Apple clang version 13.0.0 (clang-1300.0.29.30)
-------------------------------------------------------------------------------------------------
*/

#include <iostream> // cout, cin
#include <limits>   // numeric_limits

#include "annex.h"

using namespace std;
using vect = vector<size_t>;

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

char readChar() {
    char input;
    cin >> input;
    if (cin.fail()) {
        cin.clear();
    }
    emptyBuffer();
    return input;
}

bool restart(
        const string &question,
        const string &errorMessage,
        const char &yes,
        const char &no
) {
    bool repeat  = false;
    bool restart = false;
    do {
        cout << endl << question << "[" << yes << "|" << no << "] : ";

        char input = readChar();
        if (input == yes) {
            restart = true;
            repeat = false;
        } else if (input != no) {
            cout << errorMessage << endl;
            repeat = true;
        }
    } while (repeat);
    return restart;
}