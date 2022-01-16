/*
-------------------------------------------------------------------------------------------------
File name       :   main.cpp
Laboratory name :   Galton Board
Author(s)       :   Richard SIERRA, Lucas LEISSING
Creation date   :   11.01.22
Description     :   This program simulates a Galton Board.
                    The user is asked to enter the board level (number of row of pegs)
                    and the number of balls to throw.
                    At the end of the program, a graphic representation is offered
                    in the console.
Comments        :   This simulation doesn't take in count the interaction between each ball
                    as would be the case in a real Galton Board.
                    This program computes the probabilities ball by ball
Compiler        :   Apple clang version 13.0.0 (clang-1300.0.29.30)
-------------------------------------------------------------------------------------------------
*/

#include <iostream> // cout, endl

#include "annex.h"
#include "GaltonBoard.h"

using namespace std;

int main() {

    //-------------------------------------------------------------------------------------------
    //  Constants
    //-------------------------------------------------------------------------------------------

    const string MSG_WELCOME            = "Ce programme permet de ...";
    const string MSG_INVITE_BOARD_LEVEL = "Hauteur";
    const string MSG_INVITE_NBR_BALLS   = "Nombre de billes";
    const string MSG_BROKEN_STREAM      = "Erreur de saisie, veuillez recommencer votre saisie";
    const string MSG_RESTART_QUESTION   = "Voulez-vous recommencer ? ";
    const char   YES_VALUE_CHAR         = 'o';
    const char   NO_VALUE_CHAR          = 'n';

    const string MSG_EXIT = "Presser ENTER pour QUITTER";

    const unsigned MIN_VALUE_BOARD_LEVEL = 1;
    const unsigned MAX_VALUE_BOARD_LEVEL = 100;
    const unsigned MAX_VALUE_NBR_BALLS   = 1000;

    //-------------------------------------------------------------------------------------------
    //  Welcome message
    //-------------------------------------------------------------------------------------------

    cout << MSG_WELCOME << endl << endl;


    do {

        //---------------------------------------------------------------------------------------
        //  Galton simulation
        //---------------------------------------------------------------------------------------

        GaltonBoard galton(
                readIntBetween(
                        MSG_INVITE_BOARD_LEVEL,
                        MIN_VALUE_BOARD_LEVEL,
                        MAX_VALUE_BOARD_LEVEL,
                        MSG_BROKEN_STREAM
                ),
                readIntBetween(
                        MSG_INVITE_NBR_BALLS,
                        MIN_VALUE_BOARD_LEVEL,
                        MAX_VALUE_NBR_BALLS,
                        MSG_BROKEN_STREAM
                )
        );

        //---------------------------------------------------------------------------------------
        //  Start simulation
        //---------------------------------------------------------------------------------------

        galton.startSimulation();

        //---------------------------------------------------------------------------------------
        //  Displaying the simulation
        //---------------------------------------------------------------------------------------

        galton.displayBoard();

    } while (restart(MSG_RESTART_QUESTION, MSG_BROKEN_STREAM, YES_VALUE_CHAR, NO_VALUE_CHAR));

    //-------------------------------------------------------------------------------------------
    //  Program's end
    //-------------------------------------------------------------------------------------------

    cout << endl << MSG_EXIT;
    emptyBuffer();

    return EXIT_SUCCESS;
}
