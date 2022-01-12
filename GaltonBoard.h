/*
-------------------------------------------------------------------------------------------------
File name       :   GaltonBoard.h
Laboratory name :   
Author(s)       :   Richard SIERRA
Creation date   :   11.01.22
Description     :   <What does this program do ?>
Remarks         :   <Is there a bug or something ?>
Compiler        :   Apple clang version 13.0.0 (clang-1300.0.29.30)
-------------------------------------------------------------------------------------------------
*/

#ifndef LAB_08_GALTON_BOARD_GALTONBOARD_H
#define LAB_08_GALTON_BOARD_GALTONBOARD_H

using vect = std::vector<int>;

/**
 * Read an input of type int between a minimum and maximum value with control of the stream
 * @param message String with invite message
 * @param minVal Minimal value
 * @param maxVal Maximum value
 * @param errorMessage Error message for broken stream
 */
int readIntBetween(
        const std::string &message,
        int minVal,
        int maxVal,
        const std::string &errorMessage
);

/**
 *
 * @return return a 1 for right and a 0 for left
 */
int randDistrib_LR();

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
std::ostream &operator<<(std::ostream &os, const vect &v);


int rightFallCounter(int boardLevel);

std::vector<int> gaussianArray(int boardLevel,int numberOfBalls );

#endif //LAB_08_GALTON_BOARD_GALTONBOARD_H
