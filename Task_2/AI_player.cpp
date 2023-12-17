//
// Created by mohamed on 12/14/2023.
//

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com/
#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
class AI_player : public Player{
Board* Game;
bool valid=1;
int n_rows{},n_cols{},eva{},dept{};
char en_symbol{};

public:
    AI_player(Board* current, char symbol):Player(symbol),Game(current){
        n_rows=Game->get_rows().first,n_cols=Game->get_rows().second;
        if(n_rows>5 || n_cols >6){
            dept=4;
        }
        else{
            dept=INT32_MAX;
        }
    };
    void get_enemy_symbol(char symbol) override{
        en_symbol = symbol;
    }
    void get_move(int& x,int& y) override {
        int best_score=INT32_MIN;
        int score;
        for(int i=0;i<=n_rows;i++){
            for(int j=0;j<=n_cols;j++){
                if(Game->update_board(i,j,symbol)){
                    score=MinMax(dept, INT32_MIN, INT32_MAX, false);
                    if(score>best_score){
                      best_score=score;
                      x=i,y=j;
                  }
                  Game->clear_grid(i,j);
                }
            }
        }
    };
    int MinMax(int depth, int alpha,int beta,bool isMax) {
        if(Game->is_winner() && n_rows != 5){
            return isMax?-1:1;
        }
        else if(Game->game_is_over() || depth == 0){
            return (n_rows!=5)?0: Game->count_winner(symbol) >= Game->count_winner(en_symbol)? 1 : -1;
        }
if(isMax){
            int max_eval=INT32_MIN;
            for(int i=0;i<=n_rows;i++) {
                for (int j = 0; j <= n_cols; j++) {

                    if (Game->update_board(i, j, symbol)) {

                       eva = MinMax(depth-1,alpha,beta, false);
                        max_eval = max(eva, max_eval);
                        alpha =max(alpha,eva);
                        Game->clear_grid(i, j);
                        if(beta<= alpha){
                            return max_eval;
                        }
                    }
                }
            }
            return max_eval;
        }
else {
            int min_eval=INT32_MAX;
            for(int i=0;i<=n_rows;i++) {
                for (int j = 0; j <=n_cols; j++) {
                    if (Game->valid_move(i,j)&&Game->update_board(i, j, en_symbol)) {
                        eva = MinMax(depth-1,alpha,beta, true);
                        min_eval = min(eva, min_eval);
                        beta=min(beta,min_eval);
                        Game->clear_grid(i, j);
                        if(beta<= alpha){
                            return min_eval;
                        }
                    }
                }
            }
            return min_eval;
        }
    }

};
