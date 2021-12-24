/*
 * Author: Dominika Bobik
 * dbobik@mtu.edu
 * Created on: 12/24/2021
 */

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H


#include "Player.h"
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

class Game {
private:
    Player* player1;
    Player* player2;
    char board[3][3]{};
    int drawWinner;
    char fields[9][3] = {"TL", "TM", "TR", "ML", "MM", "MR", "BL", "BM", "BR"};
    void printCheckerboard(char array[3][3]);
    bool checkWin(char array[3][3]);
    bool isBoardFull(char array[3][3]);
    void printFields();
    void adjustFields(char* command);
public:
    Game(Player *player1, Player *player2);
    void start();
    void draw();
    void play();
};

#endif //TICTACTOE_GAME_H
