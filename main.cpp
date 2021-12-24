/*
 * Author: Dominika Bobik
 * dbobik@mtu.edu
 * Created on: 12/24/2021
 */

#include "Player.h"
#include "Game.h"
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

int main() {
    fprintf(stdout, "Welcome to the Tic-Tac-Toe game!\n");

    char* name1 = new char[32];
    char* name2 = new char[32];
    fprintf(stdout, "Player 1 enter your name:\n");
    scanf("%s", name1);
    fprintf(stdout, "Player 2 enter your name:\n");
    scanf("%s", name2);

    char chPlayer1;
    char chPlayer2;
    fprintf(stdout, "%s, do you pick X or O?\n", name1);
    char dump;
    scanf("%c", &dump);
    scanf("%c", &chPlayer1);

    if (chPlayer1 == 'X'){
        chPlayer2 = 'O';
    }
    else{
        chPlayer2 = 'X';
    }

    auto* player1 = new Player(name1, chPlayer1);
    auto* player2 = new Player(name2, chPlayer2);
    auto* game = new Game(player1, player2);

    game->start();
    game->draw();
    game->play();

    free(player1);
    free(player2);
    free(game);
    return 0;
}


