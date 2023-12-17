//
// Created by mohamed on 12/6/2023.
//

#ifndef CLION_LEARN_CONNECT_4_BOARD_H
#define CLION_LEARN_CONNECT_4_BOARD_H
#include"BoardGame_Classes.hpp"
#include <bits/stdc++.h>
class Connect_4_Board : public Board{
int curr_av[7]{};

public:
    Connect_4_Board();
    void clear_grid(int, int) override;
    void display_board() override; ;
    bool is_draw() override;
    bool is_winner()  override;
     bool check_winner(int , int  ,int  , int ) ;
    bool update_board(int ,int , char ) override;
    bool game_is_over() override;
    bool valid_move(int x,int y) ;
};
#endif //CLION_LEARN_CONNECT_4_BOARD_H