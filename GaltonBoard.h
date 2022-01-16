/*
-------------------------------------------------------------------------------------------------
File name       :   GaltonBoard.h
Author(s)       :   Richard SIERRA
Creation date   :   11.01.22
Description     :   Declaration of the GaltonBoard class
Comments        :   The setters are not used in this program, but are available
                    if necessary
Compiler        :   Apple clang version 13.0.0 (clang-1300.0.29.30)
-------------------------------------------------------------------------------------------------
*/

#ifndef LAB_08_GALTON_BOARD_GALTONBOARD_H
#define LAB_08_GALTON_BOARD_GALTONBOARD_H

#include "vector" // vector<size_t>

using namespace std;
using vect = vector<size_t>;

class GaltonBoard {

public:

    /**
     * Constructor of the GaltonBoard class
     * @param boardLevel Set the boardLevel value
     * @param numberOfBalls Set the numberOfBalls value
     */
    GaltonBoard(size_t boardLevel, size_t numberOfBalls);

    /**
     * Set a new value to the attribute boardLevel
     * @param level The number of levels in the board
     */
    void setBoardLevel(size_t level);

    /**
     * Set a new value to the attribute numberOfBalls
     * @param balls The number of balls
     */
    void setNumberOfBalls(size_t balls);

    /**
     * Display the Galton board in the console
     */
    void displayBoard();

    /**
     * Start a new simulation by resetting the gaussVector and redefining its new size
     */
    void startSimulation();

private:
    size_t boardLevel;
    size_t numberOfBalls;
    vect gaussVector;

    /**
     * Compute, thanks to the uniform_int_distribution class, if
     * the ball either goes left(0) or right(1)
     * @return 0 for left and 1 for right
     */
    static size_t randDistrib_LR();

    /**
     * Compute the number of times the ball fall to the right according
     * to the level of the board
     * @return the number of times the ball fell to the right
     */
    size_t rightFallCounter() const;

    /**
     * Fill the gaussVector with the balls after computing the probabilities
     */
    void fillGaussianVector();
};


#endif //LAB_08_GALTON_BOARD_GALTONBOARD_H
