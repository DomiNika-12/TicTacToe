//
// Created by domi on 12/24/21.
//

#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

class Player {
private:
    char* name;
    bool isX;
    int score;
public:
    Player(char* name, bool isX);
    bool move(char array[3][3], char* command);
    string getName();
};

#endif //TICTACTOE_PLAYER_H
