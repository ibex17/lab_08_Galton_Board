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
#include <random>
#include "GaltonBoard.h"

using namespace std;

int main() {

    //-------------------------------------------------------------------------------------------
    //  Constants
    //-------------------------------------------------------------------------------------------

    const string MSG_WELCOME                = "Ce programme permet de ...";
    const string MSG_INVITE_BOARD_LEVEL     = "Hauteur";
    const string MSG_INVITE_NBR_BALLS       = "Nombre de billes";
    const string MSG_BROKEN_STREAM          = "Erreur de saisie, veuillez recommencer";
    const string MSG_EXIT                   = "Presser ENTER pour QUITTER";

    const unsigned MIN_VALUE_ARRAY_LENGTH   = 1;
    const unsigned MAX_VALUE_BOARD_LEVEL    = 100;
    const unsigned MAX_VALUE_NBR_BALLS      = 1000;

    //-------------------------------------------------------------------------------------------
    //  Welcome message
    //-------------------------------------------------------------------------------------------
    cout << "\t\tGALTON BOARD: A simulation\n";
    cout << "\t\t===========================\n\n";

    cout << MSG_WELCOME << endl << endl;

    //-------------------------------------------------------------------------------------------
    //  User input
    //-------------------------------------------------------------------------------------------

    int boardLevel = readIntBetween(
            MSG_INVITE_BOARD_LEVEL,
            MIN_VALUE_ARRAY_LENGTH,
            MAX_VALUE_BOARD_LEVEL,
            MSG_BROKEN_STREAM
    );

    int numberOfBalls = readIntBetween(
            MSG_INVITE_NBR_BALLS,
            MIN_VALUE_ARRAY_LENGTH,
            MAX_VALUE_NBR_BALLS,
            MSG_BROKEN_STREAM
    );

    //-------------------------------------------------------------------------------------------
    //  Algorithm
    //-------------------------------------------------------------------------------------------

    vector<int> gaussArray = gaussianArray(boardLevel,numberOfBalls);


    //TODO effacer ce commentaire
    /*
    // Initialise a vector of size boardLevel and filled with 0
    vector<int> gaussianArray(boardLevel);

    // Counts every time the ball falls to the right side
    int rightFallCounter;

    for (int i = 0; i < numberOfBalls; ++i) {

        rightFallCounter = 0; // Reinitialised at every outside loop

        // The boardLevel is the number of layers of decisions that the ball traverse,
        for (int j = 0; j < boardLevel; ++j) {
            rightFallCounter += randDistrib_LR(); // The ball either goes left(0) or right(1)
        }
        // The total number of rights it made is the index of where it lands
        gaussianArray.at(rightFallCounter) += 1;    // So we add one ball
    }

    */

    //-------------------------------------------------------------------------------------------
    //  Displaying the simulation of the galton board
    //-------------------------------------------------------------------------------------------

    cout << "\n\n\tResults\n"; //
    cout << "-------------------------\n\n";

    cout << "Gaussian Array :" << endl << gaussArray << endl;


    //TODO faire la fonction pour afficher correctement sur la console
    /* ancienne boucle, fonctionne
    for (auto i = gaussArray.begin(); i != gaussArray.end(); ++i) {
        for (int j = 0; j < *i; ++j) {
            cout << "*";
        }
        cout << endl;
    }*/
    int makeshiftt = 50; //valeur arbitraire placeholder. devra corespondre au nombre
                         //max de colonne

    for (auto i = 0; i<=makeshiftt; ++i){
       for (auto i = gaussArray.begin(); i != gaussArray.end(); ++i) {
          if(/*cas!= vide?cout << "*";:rien""*/)
             cout << "*";
       }
    }

    //-------------------------------------------------------------------------------------------
    //  Program's end
    //-------------------------------------------------------------------------------------------

    cout << endl << MSG_EXIT;
    emptyBuffer();

    return EXIT_SUCCESS;
}
