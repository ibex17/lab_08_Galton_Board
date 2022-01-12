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

#include <cstdlib>
#include <iostream>
#include <random>

#include "GaltonBoard.h"

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

        if(input < minVal || input > maxVal || error)
            cout << errorMessage << endl;

        emptyBuffer();

    } while (input < minVal || input > maxVal || error);

    return input;
}

int randDistrib_LR() {
    random_device              rd;  //Will be used to obtain a seed for the random number engine
    mt19937                    gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 1);

    return distrib(gen);
}

int rightFallCounter(int boardLevel) {
    // Counts every time the ball falls to the right side
    int result = 0;

    // The boardLevel is the number of layers of decisions that the ball traverse,
    for (int i = 0; i < boardLevel; ++i) {
        result += randDistrib_LR(); // The ball either goes left(0) or right(1)
    }
    return result;
}

vector<int> gaussianArray(int boardLevel,int numberOfBalls ){
    // Initialise a vector of size boardLevel and filled with 0
    vector<int> gaussianArray(boardLevel);

    for (int i = 0; i < numberOfBalls; ++i) {
        // The total number of rights it made is the index of where it lands
        gaussianArray.at(rightFallCounter(boardLevel)) += 1;    // So we add one ball
    }
    return gaussianArray;
}