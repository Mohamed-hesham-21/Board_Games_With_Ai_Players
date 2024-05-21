//
// Created by mohamed on 12/10/2023.
//
#include <bits/stdc++.h>
#include "XO_5x5_board.h"
using  namespace    std;
bool XO_5x5_board::game_is_over() {
    return !n_moves;
}
XO_5x5_board::XO_5x5_board() {
    n_rows=n_cols=5;
    n_moves=24;
    board =new char*[n_rows];
    for(int i=0; i<n_rows; i++){
        board[i]=new char[n_cols];
    }
    for (int i = 0; i < n_rows; ++i) {
        for(int j = 0;j<n_cols;j++) {
         board[i][j]=' ';
        }
    }
}
bool XO_5x5_board::valid_move(int x,int y){
    return x<n_rows && y<n_cols && x>=0 && y>=0;
}
void XO_5x5_board::display_board() {

    for (int i = 0; i <= n_rows; ++i) {
        for (int j = 0; j <= n_cols; ++j) {
            if(i==0 || j== 0){
                cout <<"|"<<(j>9?"":" ")<< i + j  << " |";
                continue;
            }

            else  {
                cout<<"| "<<board[i-1][j-1] <<" |";
            }

        }
        cout<<endl;
        for (int j = 0; j < n_cols; ++j) {
            cout<<"-----";
        }
        cout<<endl;

    }
}
bool XO_5x5_board::is_draw() {
    return false;
}
bool XO_5x5_board::check_winner(int row, int col ,int check , int sum = 2) {
    set.insert({row, col});
    if(sum==0){
        return true;
    }
    int current_row = row+dx[check],current_col = col+dy[check];
    if(!(valid_move(current_row,current_col) && board[current_row][current_col] == board[row][col]) ) {
        return false;
    }
    sum--;
    return check_winner(current_row,current_col,check,sum);
}
unsigned long long XO_5x5_board::count_winner(char symbol){

    for(int i = 0; i < n_rows; i++) {

        for (int j = 0; j < n_cols; ++j) {
            if(board[i][j]!=symbol)continue;
            for (int k = 0; k < 8; ++k) {

                if(check_winner(i,j,k)){
                    set_winner.insert(set);
                }
                set.clear();
            }
        }
    }
    return set_winner.size();
}
bool XO_5x5_board::is_winner() {
return false ;
}
bool XO_5x5_board::update_board(int x,int y, char symbol) {
    y--,x--;
    if(!( valid_move(x,y) && board[x][y]==' ')) {
        return false;
    }
    board[x][y] = symbol;
    n_moves--;
    return true;
}
void XO_5x5_board::clear_grid(int x, int y) {
board[x-1][y-1] =' ';
n_moves++;
}