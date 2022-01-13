//
// Created by Richard Sierra on 13.01.22.
//

#include <iostream>
#include <random>
#include "GaltonBoard.h"

using namespace std;

GaltonBoard::GaltonBoard(size_t boardLevel, size_t numberOfBalls) {
    this->boardLevel    = boardLevel;
    this->numberOfBalls = numberOfBalls;
}

void GaltonBoard::setBoardLevel(size_t level) {
    boardLevel = level;
}

void GaltonBoard::setNumberOfBalls(size_t balls) {
    numberOfBalls = balls;
}

//_________________


size_t GaltonBoard::randDistrib_LR() {
    random_device              rd;  //Will be used to obtain a seed for the random number engine
    mt19937                    gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 1);

    return distrib(gen);
}

size_t GaltonBoard::rightFallCounter() {
    // Counts every time the ball falls to the right side
    size_t result = 0;

    // The level is the number of layers of decisions that the ball traverse,
    for (size_t i = 0; i < boardLevel; ++i) {
        result += randDistrib_LR(); // The ball either goes left(0) or right(1)
    }
    return result;
}

void GaltonBoard::createGaussianArray() {
    // Initialise a vector of size level and filled with 0
    vector<size_t> gaussianArray(boardLevel);

    for (size_t i = 0; i < numberOfBalls; ++i) {
        // The total number of rights it made is the index of where it lands
        gaussianArray.at(rightFallCounter()) += 1;    // So we add one ball
    }
    gaussArray = gaussianArray;
}

void GaltonBoard::displayBoard() {
    for (auto i = gaussArray.begin(); i != gaussArray.end(); ++i) {
        for (size_t j = 0; j < *i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

void GaltonBoard::startSimulation() {
    createGaussianArray();
}
