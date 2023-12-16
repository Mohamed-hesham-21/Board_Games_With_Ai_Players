//
// Created by mohamed on 12/6/2023.
//

#ifndef CLION_LEARN_CONNECT_4_BOARD_H
#define CLION_LEARN_CONNECT_4_BOARD_H
#include"../include/BoardGame_Classes.hpp"
#include <bits/stdc++.h>
class Connect_4_Board : public Board{
int curr_av[7]{};

public:
    Connect_4_Board();
    void display_board() ;
    bool is_draw() ;
    bool is_winner() ;
     bool check_winner(int , int  ,int  , int );
    bool update_board(int ,int , char ) ;
    bool game_is_over() ;
    bool valid_move(int x,int y) ;
};
#endif //CLION_LEARN_CONNECT_4_BOARD_H