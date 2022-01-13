/*
-------------------------------------------------------------------------------------------------
File name       :   main.cpp
Laboratory name :   Galton Board
Author(s)       :   Richard SIERRA, Lucas LEISSING
Creation date   :   11.01.22
Description     :   <What does this program do ?>
Remarks         :   <Is there a bug or something ?>
Compiler        :   Apple clang version 13.0.0 (clang-1300.0.29.30)
-------------------------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>

#include "Galton.h"
#include "GaltonBoard.h"

using namespace std;

int main() {

    //-------------------------------------------------------------------------------------------
    //  Constants
    //-------------------------------------------------------------------------------------------

    const string MSG_WELCOME            = "Ce programme permet de ...";
    const string MSG_INVITE_BOARD_LEVEL = "Hauteur";
    const string MSG_INVITE_NBR_BALLS   = "Nombre de billes";
    const string MSG_BROKEN_STREAM      = "Erreur de saisie, veuillez recommencer";
    const string MSG_EXIT               = "Presser ENTER pour QUITTER";

    const unsigned MIN_VALUE_BOARD_LEVEL = 1;
    const unsigned MAX_VALUE_BOARD_LEVEL = 100;
    const unsigned MAX_VALUE_NBR_BALLS   = 1000;

    //-------------------------------------------------------------------------------------------
    //  Welcome message
    //-------------------------------------------------------------------------------------------

    cout << MSG_WELCOME << endl << endl;

    //-------------------------------------------------------------------------------------------
    //  User input
    //-------------------------------------------------------------------------------------------

    int boardLevel = readIntBetween(
            MSG_INVITE_BOARD_LEVEL,
            MIN_VALUE_BOARD_LEVEL,
            MAX_VALUE_BOARD_LEVEL,
            MSG_BROKEN_STREAM
    );

    int numberOfBalls = readIntBetween(
            MSG_INVITE_NBR_BALLS,
            MIN_VALUE_BOARD_LEVEL,
            MAX_VALUE_NBR_BALLS,
            MSG_BROKEN_STREAM
    );

    //-------------------------------------------------------------------------------------------
    //  Algorithm
    //-------------------------------------------------------------------------------------------

    GaltonBoard galton(boardLevel, numberOfBalls);

    galton.startSimulation();

    //-------------------------------------------------------------------------------------------
    //  Displaying the simulation of the galton board
    //-------------------------------------------------------------------------------------------

    cout << "\n\n\tResults\n"; //
    cout << "-------------------------\n\n";

    cout << "Gaussian Array :" << endl;
    galton.displayBoard();

    //-------------------------------------------------------------------------------------------
    //  Program's end
    //-------------------------------------------------------------------------------------------

    cout << endl << MSG_EXIT;
    emptyBuffer();

    return EXIT_SUCCESS;
}
