//
// Created by domi on 12/24/21.
//

#include "Player.h"

Player::Player(char* name, bool isX) {
    score = 0;
    this->isX = isX;
    this->name = name;
}

bool Player::move(char (*array)[3], char* command) {
    char ch = ' ';
    if (isX){
        ch = 'X';
    }
    else {
        ch = 'O';
    }

    if (strcmp(command, "TL") == 0){
        if(array[0][0] == ' '){
            array[0][0] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else if (strcmp(command, "TM") == 0){
        if(array[0][1] == ' '){
            array[0][1] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else if (strcmp(command, "TR") == 0){
        if(array[0][2] == ' '){
            array[0][2] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else if (strcmp(command, "ML") == 0){
        if(array[1][0] == ' '){
            array[1][0] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else if (strcmp(command, "MM") == 0){
        if(array[1][1] == ' '){
            array[1][1] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else if (strcmp(command, "MR") == 0){
        if(array[1][2] == ' '){
            array[1][2] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else if (strcmp(command, "BL") == 0){
        if(array[2][0] == ' '){
            array[2][0] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else if (strcmp(command, "BM") == 0){
        if(array[2][1] == ' '){
            array[2][1] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else if (strcmp(command, "BR") == 0){
        if(array[2][2]== ' '){
            array[2][2] = ch;
            return true;
        }
        else{
            fprintf(stdout, "%s is already filled, pick again\n", command);
            return false;
        }
    }
    else{
        fprintf(stdout, "Invalid choice\n");
        return false;
    }
}

string Player::getName() {
    return name;
}

