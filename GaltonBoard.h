//
// Created by Richard Sierra on 13.01.22.
//

#ifndef LAB_08_GALTON_BOARD_GALTONBOARD_H
#define LAB_08_GALTON_BOARD_GALTONBOARD_H

#include <vector>


class GaltonBoard {
public:
    GaltonBoard(size_t boardLevel, size_t numberOfBalls);

    void setBoardLevel(size_t level);

    void setNumberOfBalls(size_t balls);

    void displayBoard();

    void startSimulation();

private:
    size_t boardLevel;
    size_t numberOfBalls;

    std::vector<size_t> gaussArray;

    size_t randDistrib_LR();

    size_t rightFallCounter();

    void createGaussianArray();
};


#endif //LAB_08_GALTON_BOARD_GALTONBOARD_H
