/*
-------------------------------------------------------------------------------------------------
File name       :   annex.h
Author(s)       :   Richard SIERRA
Creation date   :   18.1.21
Description     :   This file contains functions declarations of various functions
                    used in the program
Comments        :   -
Compiler        :   Apple clang version 13.0.0 (clang-1300.0.29.30)
-------------------------------------------------------------------------------------------------
*/

#ifndef LAB_08_GALTON_BOARD_ANNEX_H
#define LAB_08_GALTON_BOARD_ANNEX_H

#include "vector"   // vector<size_t>

using namespace std;
using vect = vector<size_t>;

/**
 * Compact function to empty the buffer
 */
void emptyBuffer();

/**
 * Displays a Vector in the format (v1, v2, ..., vn)
 * @param os Output stream
 * @param v Vector
 * @return Output stream
 */
ostream &operator<<(ostream &os, const vect &v);

/**
 * Read an input of type int between a minimum and maximum value with control of the stream
 * @param message String with invite message
 * @param minVal Minimal value
 * @param maxVal Maximum value
 * @param errorMessage Error message for broken stream
 * @return int input
 */
int readIntBetween(
        const string &message,
        int minVal,
        int maxVal,
        const string &errorMessage
);

/**
 * Read an input of type char
 * @return Character input
 */
char readChar();

/**
 *
 * @param question String with question message
 * @param errorMessage String with wrong input error message
 * @param yes Char for the "yes" value
 * @param no Char for the "no" value
 * @return True if char input match the "yes" value
 */
bool restart(
        const string &question,
        const string &errorMessage,
        const char &yes,
        const char &no
        );


#endif //LAB_08_GALTON_BOARD_ANNEX_H
