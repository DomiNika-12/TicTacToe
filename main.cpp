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
bool checkWin(char array[3][3]);
bool isBoardFull(char array[3][3]);

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
    fprintf(stdout, "TL, TM, TR, ML, MM, MR, BL, BM, BR\n");
    fprintf(stdout, "Prompt will tell you which fields are still available\n");
    fprintf(stdout, "--------------------------------------------------------------------\n");
    sleep_for(3s);
    fprintf(stdout, "Let's start!\n");
    fprintf(stdout, "Draw in progress...\n");
    int draw = rand() % 2 + 1;
    sleep_for(3s);
    if (draw == 1){
        fprintf(stdout, "%s starts\n", player1.getName().c_str());
    }
    else {
        fprintf(stdout, "%s starts\n", player2.getName().c_str());
    }
    fprintf(stdout, "--------------------------------------------------------------------\n");

    char board[3][3] = {{' ',' ',' '},
                     {' ',' ',' '},
                     {' ',' ',' '}};

    bool won = false;
    while (!won){
        if (draw == 1){
            // Player1's move
            char* command = new char[32];
            bool correctMove = false;
            while (!correctMove){
                fprintf(stdout, "%s make your move\n", player1.getName().c_str());
                fprintf(stdout, "TL, TM, TR, ML, MM, MR, BL, BM, BR\n");
                scanf("%s", command);
                correctMove = player1.move(board, command);
            }
            won = checkWin(board);
            if (won){
                fprintf(stdout, "%s won!", player1.getName().c_str());
                break;
            }
        }
        else {
            // Player2's move
            char* command = new char[32];
            bool correctMove = false;
            while (!correctMove){
                fprintf(stdout, "%s make your move\n", player2.getName().c_str());
                fprintf(stdout, "TL, TM, TR, ML, MM, MR, BL, BM, BR\n");
                scanf("%s", command);
                correctMove = player2.move(board, command);
            }
            won = checkWin(board);
            if (won){
                fprintf(stdout, "%s won!\n", player2.getName().c_str());
                break;
            }
        }
        if (isBoardFull(board)){
            fprintf(stdout, "Draw! No one won.\n");
            break;
        }
        fprintf(stdout, "Current board:\n");
        printCheckerboard(board);
        if (draw == 1){
            // Player2's move
            char* command = new char[32];
            bool correctMove = false;
            while (!correctMove){
                fprintf(stdout, "%s make your move\n", player2.getName().c_str());
                fprintf(stdout, "TL, TM, TR, ML, MM, MR, BL, BM, BR\n");
                scanf("%s", command);
                correctMove = player2.move(board, command);
            }
            won = checkWin(board);
            if (won){
                fprintf(stdout, "%s won!\n", player2.getName().c_str());
                break;
            }
        }
        else{
            // Player1's move
            char* command = new char[32];
            bool correctMove = false;
            while (!correctMove){
                fprintf(stdout, "%s make your move\n", player1.getName().c_str());
                fprintf(stdout, "TL, TM, TR, ML, MM, MR, BL, BM, BR\n");
                scanf("%s", command);
                correctMove = player1.move(board, command);
            }
            won = checkWin(board);
            if (won){
                fprintf(stdout, "%s won!\n", player1.getName().c_str());
                break;
            }
        }
        if (isBoardFull(board)){
            fprintf(stdout, "Draw! No one won.\n");
            break;
        }
        fprintf(stdout, "Current board:\n");
        printCheckerboard(board);
    }
    fprintf(stdout, "Final board:\n");
    printCheckerboard(board);
    fprintf(stdout, "Game ended, Thanks for playing!\n");
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
    if (array[0][0] == array[0][1] && array[0][1] == array[0][2] && array[0][0] != ' '){
        won = true;
    }
    else if (array[1][0] == array[1][1] && array[1][1] == array[1][2] && array[1][0] != ' '){
        won  = true;
    }
    else if (array[2][0] == array[2][1] && array[2][1] == array[2][2] && array[2][0] != ' '){
        won = true;
    }
    // Vertical check
    else if (array[0][0] == array[1][0] && array[1][0] == array[2][0] && array[0][0] != ' '){
        won = true;
    }
    else if (array[0][1] == array[1][1] && array[1][1] == array[2][1] && array[0][1] != ' '){
        won  = true;
    }
    else if (array[0][2] == array[1][2] && array[1][2] == array[2][2] && array[0][2] != ' '){
        won = true;
    }
    // Cross-check
    else if (array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[0][0] != ' '){
        won = true;
    }
    else if (array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[0][2] != ' '){
        won  = true;
    }

    return won;
}

bool isBoardFull(char array[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (array[i][j] == ' '){ return false; }
        }
    }
    return true;
}

