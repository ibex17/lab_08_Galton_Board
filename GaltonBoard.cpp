/*
-------------------------------------------------------------------------------------------------
File name       :   GaltonBoard.cpp
Author(s)       :   Richard SIERRA
Creation date   :   11.01.22
Description     :   Definition of the GaltonBoard class
Comments        :   -
Compiler        :   Apple clang version 13.0.0 (clang-1300.0.29.30)
-------------------------------------------------------------------------------------------------
*/

#include <iostream>     // cout, endl
#include <random>       // random_device, mt19937, gen(), uniform_int_distribution<>, distrib()
#include <algorithm>    // max_element()

#include "GaltonBoard.h"

using namespace std;

//-----------------------------------------------------------------------------------------------
//  Constructor
//-----------------------------------------------------------------------------------------------

GaltonBoard::GaltonBoard(size_t boardLevel, size_t numberOfBalls) {
    this->boardLevel    = boardLevel;
    this->numberOfBalls = numberOfBalls;
}

//-----------------------------------------------------------------------------------------------
//  Setters
//-----------------------------------------------------------------------------------------------

void GaltonBoard::setBoardLevel(size_t level) {
    this->boardLevel = level;
}

void GaltonBoard::setNumberOfBalls(size_t balls) {
    this->numberOfBalls = balls;
}

//-----------------------------------------------------------------------------------------------
//  Random distribution
//-----------------------------------------------------------------------------------------------

size_t GaltonBoard::randDistrib_LR() {
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    random_device              rd;  // Will be used to obtain a seed for the random number engine
    mt19937                    gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 1);

    return distrib(gen);
}

//-----------------------------------------------------------------------------------------------
//  Algorithm
//-----------------------------------------------------------------------------------------------

size_t GaltonBoard::rightFallCounter() const {
    // Counts every time the ball falls to the right side of the peg
    size_t result = 0;

    // The boardLevel is the number of layers of decisions (right/left) that the ball traverse
    for (size_t i = 0; i < boardLevel; ++i) {
        result += randDistrib_LR(); // The ball either goes left(0) or right(1)
    }
    return result;
}

void GaltonBoard::fillGaussianVector() {
    for (size_t i = 0; i < numberOfBalls; ++i) {
        // The total number of rights the ball made is the index of where it lands
        gaussVector.at(rightFallCounter()) += 1;    // So we add one ball
    }
}

//-----------------------------------------------------------------------------------------------
//  Action methods
//-----------------------------------------------------------------------------------------------

void GaltonBoard::displayBoard() {
    size_t indexMaxVal = max_element(
            gaussVector.begin(),
            gaussVector.end()
    ) - gaussVector.begin();

    // We go through the gaussian curve "floor by floor"
    for (size_t maxVal = gaussVector[indexMaxVal]; maxVal > 0; --maxVal) {
        for (size_t &i: gaussVector) {
            // If one of the value is equal to the floor value
            // we write a star '*' and lower it from one
            // until we reach the value 0, meaning all floors have been
            // converted to stars
            if (i == maxVal) {
                cout << "*";
                --i;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

}

void GaltonBoard::startSimulation() {
    // The vector has to be empty to start a new simulation
    gaussVector.clear();

    // Resize the vector to a size of boardLevel + 1 (because the board level is the number of
    // pegs and at the last row there is 1 extra column (see image of a Galton Board)
    gaussVector.resize(boardLevel + 1);

    fillGaussianVector();
}
