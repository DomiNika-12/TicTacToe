#include <iostream>
#include <cstring>
#include "Player.h"
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

void printCheckerboard(char array[3][3]);

int main() {
    fprintf(stdout, "Welcome to the Tic-Tac-Toe game!\n");

    char* name1 = new char[32];
    char* name2 = new char[32];
    fprintf(stdout, "Player 1 enter your name:\n");
    scanf("%s", name1);

    char* choicePlayer1 = new char[32];
    bool isX1 = false;
    fprintf(stdout, "X or O:\n");
    scanf("%s", choicePlayer1);

    fprintf(stdout, "Player 2 enter your name:\n");
    scanf("%s", name2);

    if (strcmp(choicePlayer1, "X") == 0){
        isX1 = true;
    }

    Player player1 (name1, isX1);
    Player player2 (name2, !isX1);

    fprintf(stdout, "Fields are marked as follows: \n");
    fprintf(stdout, " TL | TM | TR \n");
    fprintf(stdout, "----+----+----\n");
    fprintf(stdout, " ML | MM | MR \n");
    fprintf(stdout, "----+----+----\n");
    fprintf(stdout, " BL | BM | BR \n");
    fprintf(stdout, "Each time indicate your choice by typing in one of the following:\n");
    fprintf(stdout, "TL, TM, TR, ML, MM, MR, BL, BM, BR");
    fprintf(stdout, "Prompt will tell you which fields are still available");
    fprintf(stdout, "--------------------------------------------------------------------\n");
    fprintf(stdout, "Let's start!\n");
    fprintf(stdout, "Draw in progress...");
    int draw = rand() % 2 + 1;
    sleep_for(3s);
    if (draw == 1){
        fprintf(stdout, "%s starts", player1.getName().c_str());
    }
    else {
        fprintf(stdout, "%s starts", player2.getName().c_str());
    }
    char board[3][3] = {{' ',' ',' '},
                     {' ',' ',' '},
                     {' ',' ',' '}};

    bool won = false;
    while (!won){

    }
    return 0;
}

/*
 *  Prints the checkerboard
 *  Example:
 *   o |   | x
 *  ---+---+---
 *   o |   | x
 *  ---+---+---
 *   o |   | x
 *
 */
void printCheckerboard(char array[3][3]) {
    fprintf(stdout, " %c | %c | %c \n", array[0][0], array[0][1], array[0][2]);
    fprintf(stdout, "---+---+---\n");
    fprintf(stdout, " %c | %c | %c \n", array[1][0], array[1][1], array[1][2]);
    fprintf(stdout, "---+---+---\n");
    fprintf(stdout, " %c | %c | %c \n", array[2][0], array[2][1], array[2][2]);
}

bool checkWin(char array[3][3]){
    // 8 possibilities:
    // Cross (x2)
    // Horizontal (x3)
    // Vertical (x3)
    bool won = false;
    // Horizontal check
    if (array[0][0] == array[0][1] && array[0][1] == array[0][2] && array[0][0]){
        won = true;
    }
    if (array[1][0] == array[1][1] && array[1][1] == array[1][2]){
        won  = true;
    }
    if (array[2][0] == array[2][1] && array[2][1] == array[2][2]){
        won = true;
    }

    // Vertical check
    if (array[0][0] == array[0][1] && array[0][1] == array[0][2]){
        won = true;
    }
    if (array[1][0] == array[1][1] && array[1][1] == array[1][2]){
        won  = true;
    }
    if (array[2][0] == array[2][1] && array[2][1] == array[2][2]){
        won = true;
    }

    // Cross-check
    if (array[0][0] == array[0][1] && array[0][1] == array[0][2]){
        won = true;
    }
    if (array[1][0] == array[1][1] && array[1][1] == array[1][2]){
        won  = true;
    }
    if (array[2][0] == array[2][1] && array[2][1] == array[2][2]){
        won = true;
    }

    return won;
}

