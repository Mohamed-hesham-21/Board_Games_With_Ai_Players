//
// Created by mohamed on 12/10/2023.
//

#ifndef OOP_XO_5X5_BOARD_H
#define OOP_XO_5X5_BOARD_H
#include"BoardGame_Classes.hpp"
class XO_5x5_board : public Board {
public:
    XO_5x5_board();
    void display_board() ;
    bool is_draw() ;
    bool is_winner() ;
    bool check_winner(int , int  ,int  , int );
    bool update_board(int x,int y, char symbol) ;
    bool game_is_over() ;
    bool valid_move(int,int) ;
    unsigned long long count_winner(char);
    void clear_grid(int, int) override;
};

#endif //OOP_XO_5X5_BOARD_H
