//
// Created by domi on 12/24/21.
//

#include "Player.h"

Player::Player(char* name, bool isX) {
    score = 0;
    this->isX = isX;
    this->name = name;
}

void Player::move(char (*array)[3], string command) {

}

string Player::getName() {
    return name;
}

