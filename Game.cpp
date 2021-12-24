//
// Created by domi on 12/24/21.
//

#include "Game.h"

Game::Game(Player *player1, Player *player2){
    this->player1 = player1;
    this->player2 = player2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    drawWinner = 0;
}

void Game::start() {
    fprintf(stdout, "Thanks %s and %s! Here is how the game work:\n", player1->getName().c_str(), player2->getName().c_str());
    fprintf(stdout, "--------------------------------------------------------------------\n");
    fprintf(stdout, "Fields are marked as follows: \n");
    fprintf(stdout, " TL | TM | TR \n");
    fprintf(stdout, "----+----+----\n");
    fprintf(stdout, " ML | MM | MR \n");
    fprintf(stdout, "----+----+----\n");
    fprintf(stdout, " BL | BM | BR \n");
    fprintf(stdout, "Each time indicate your choice by typing in one of the following:\n");
    printFields();
    fprintf(stdout, "Prompt will tell you which fields are still available\n");
    fprintf(stdout, "--------------------------------------------------------------------\n");
    fprintf(stdout, "Let's start!\n");
    sleep_for(3s);
}

void Game::draw(){
    sleep_for(3s);
    fprintf(stdout, "Draw in progress...\n");
    drawWinner = rand() % 2 + 1;
    sleep_for(3s);
    if (drawWinner == 1) {
        fprintf(stdout, "%s starts\n", player1->getName().c_str());
    } else {
        fprintf(stdout, "%s starts\n", player2->getName().c_str());
    }
    fprintf(stdout, "--------------------------------------------------------------------\n");
}

void Game::play() {
    bool won = false;
    while (!won) {
        if (drawWinner == 1) {
            // Player1's move
            char *command = new char[32];
            bool correctMove = false;
            while (!correctMove) {

                fprintf(stdout, "%s make your move - you are %c \n", player1->getName().c_str(), player1->getCh());
                printFields();
                scanf("%s", command);
                correctMove = player1->move(board, command);
                adjustFields(command);
            }
            fprintf(stdout, "\n");
            won = checkWin(board);
            if (won) {
                fprintf(stdout, "%s won!", player1->getName().c_str());
                break;
            }
        } else {
            // Player2's move
            char *command = new char[32];
            bool correctMove = false;
            while (!correctMove) {
                fprintf(stdout, "%s make your move - you are %c\n", player2->getName().c_str(), player2->getCh());
                printFields();
                scanf("%s", command);
                correctMove = player2->move(board, command);
                adjustFields(command);
            }
            fprintf(stdout, "\n");
            won = checkWin(board);
            if (won) {
                fprintf(stdout, "%s won!\n", player2->getName().c_str());
                break;
            }
        }
        if (isBoardFull(board)) {
            fprintf(stdout, "Draw! No one won.\n");
            break;
        }
        fprintf(stdout, "Current board:\n");
        printCheckerboard(board);
        fprintf(stdout, "\n");
        if (drawWinner == 1) {
            // Player2's move
            char *command = new char[32];
            bool correctMove = false;
            while (!correctMove) {
                fprintf(stdout, "%s make your move - you are %c \n", player2->getName().c_str(), player2->getCh());
                printFields();
                scanf("%s", command);
                correctMove = player2->move(board, command);
                adjustFields(command);
            }
            fprintf(stdout, "\n");
            won = checkWin(board);
            if (won) {
                fprintf(stdout, "%s won!\n", player2->getName().c_str());
                break;
            }
        } else {
            // Player1's move
            char *command = new char[32];
            bool correctMove = false;
            while (!correctMove) {
                fprintf(stdout, "%s make your move - you are %c\n", player1->getName().c_str(), player1->getCh());
                printFields();
                scanf("%s", command);
                correctMove = player1->move(board, command);
                adjustFields(command);
            }
            fprintf(stdout, "\n");
            won = checkWin(board);
            if (won) {
                fprintf(stdout, "%s won!\n", player1->getName().c_str());
                break;
            }
        }
        if (isBoardFull(board)) {
            fprintf(stdout, "Draw! No one won.\n");
            break;
        }
        fprintf(stdout, "Current board:\n");
        printCheckerboard(board);
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "Final board:\n");
    printCheckerboard(board);
    fprintf(stdout, "Game ended, Thanks for playing!\n");
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
void Game::printCheckerboard(char array[3][3]) {
    fprintf(stdout, " %c | %c | %c \n", array[0][0], array[0][1], array[0][2]);
    fprintf(stdout, "---+---+---\n");
    fprintf(stdout, " %c | %c | %c \n", array[1][0], array[1][1], array[1][2]);
    fprintf(stdout, "---+---+---\n");
    fprintf(stdout, " %c | %c | %c \n", array[2][0], array[2][1], array[2][2]);
}

bool Game::checkWin(char array[3][3]) {
    // 8 possibilities:
    // Cross (x2)
    // Horizontal (x3)
    // Vertical (x3)
    bool won = false;
    // Horizontal check
    if (array[0][0] == array[0][1] && array[0][1] == array[0][2] && array[0][0] != ' ') {
        won = true;
    } else if (array[1][0] == array[1][1] && array[1][1] == array[1][2] && array[1][0] != ' ') {
        won = true;
    } else if (array[2][0] == array[2][1] && array[2][1] == array[2][2] && array[2][0] != ' ') {
        won = true;
    }
        // Vertical check
    else if (array[0][0] == array[1][0] && array[1][0] == array[2][0] && array[0][0] != ' ') {
        won = true;
    } else if (array[0][1] == array[1][1] && array[1][1] == array[2][1] && array[0][1] != ' ') {
        won = true;
    } else if (array[0][2] == array[1][2] && array[1][2] == array[2][2] && array[0][2] != ' ') {
        won = true;
    }
        // Cross-check
    else if (array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[0][0] != ' ') {
        won = true;
    } else if (array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[0][2] != ' ') {
        won = true;
    }

    return won;
}

bool Game::isBoardFull(char array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == ' ') { return false; }
        }
    }
    return true;
}

void Game::printFields() {
    for (int i = 0; i < 10; i++){
        fprintf(stdout, "%s ",fields[i]);
    }
    fprintf(stdout, "\n");
}

void Game::adjustFields(char* command) {
    if (strcmp(command, "TL") == 0){
        fields[0][0] = ' ';
        fields[0][1] = ' ';
    }
    else if (strcmp(command, "TM") == 0){
        fields[1][0] = ' ';
        fields[1][1] = ' ';
    }
    else if (strcmp(command, "TR") == 0){
        fields[2][0] = ' ';
        fields[2][1] = ' ';
    }
    else if (strcmp(command, "ML") == 0){
        fields[3][0] = ' ';
        fields[3][1] = ' ';
    }
    else if (strcmp(command, "MM") == 0){
        fields[4][0] = ' ';
        fields[4][1] = ' ';
    }
    else if (strcmp(command, "MR") == 0){
        fields[5][0] = ' ';
        fields[5][1] = ' ';
    }
    else if (strcmp(command, "BL") == 0){
        fields[6][0] = ' ';
        fields[6][1] = ' ';
    }
    else if (strcmp(command, "BM") == 0){
        fields[7][0] = ' ';
        fields[7][1] = ' ';
    }
    else if (strcmp(command, "BR") == 0){
        fields[8][0] = ' ';
        fields[8][1] = ' ';
    }
}


