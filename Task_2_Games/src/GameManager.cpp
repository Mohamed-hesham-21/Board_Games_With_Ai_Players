// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;
GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}
void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                 players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
    if (boardPtr->get_rows().first==5&&boardPtr->get_rows().second==5)
    {
        int s1 = boardPtr->count_winner(players[0]->get_symbol());
        int s2 = boardPtr->count_winner(players[1]->get_symbol());
        if (s1==s2)
        {
            cout <<"Draw!\n";
        }
        else if (s1>=s2)
        {
            cout  << players[0]->to_string() << " wins\n";
                return;
        }
        else {cout  << players[1]->to_string() << " wins\n";
                return;}
        
    }
    
}
