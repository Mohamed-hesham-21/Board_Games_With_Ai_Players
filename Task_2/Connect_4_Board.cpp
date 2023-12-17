//
// Created by mohamed on 12/6/2023.
//
#include <bits/stdc++.h>
#include "Connect_4_Board.h"
using  namespace    std;
Connect_4_Board::Connect_4_Board() {
n_rows= 6,n_cols= 7;
board = new char*[n_rows];
n_moves=42;
    for(int i=0; i<n_rows; i++) {
        board[i]=new char [n_cols];
    }
    for(int i=0; i< n_rows;i++) {
    for(int j=0; j<n_cols; j++) {
    board[i][j]=' ';
    }
    }
    for(int i=0; i<n_cols; i++) {
        curr_av[i] =  5 ;
    }

}
bool Connect_4_Board::valid_move (int x,int y){
    return x<n_rows && y<n_cols && x>=0 && y>=0;
}
void Connect_4_Board::display_board() {
for(int i=0; i<n_cols; i++){

        cout <<"|"<<(i>9?"":" ")<< i +1 << " |";

}
    cout <<endl;
    for (int j = 0; j < n_cols; ++j) {
        cout<<"-----";
    }
cout <<endl;
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {

                cout<<"| "<<board[i][j] <<" |";

        }
        cout<<endl;
        for (int j = 0; j < n_cols; ++j) {
            cout<<"-----";
        }
        cout<<endl;
    }
}

bool Connect_4_Board::is_draw() {
    if (n_moves<42)
    {
        return false ;
    }
    
return !is_winner();
}
bool Connect_4_Board::check_winner(int row, int col ,int check , int sum = 3) {
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
bool Connect_4_Board::is_winner() {

    for(int i = 0; i < n_rows; i++) {

        for (int j = 0; j < n_cols; ++j) {
            if(board[i][j]==' ')continue;
            for (int k = 0; k < 8; ++k) {

                if(check_winner(i,j,k)){
                return true;
                }
            }
        }
    }
    return false;
}
bool Connect_4_Board::update_board(int x,int y, char symbol) {
      y--;
    if(!( valid_move(curr_av[y],y) && board[0][y]==' ')) {

        return false;
    }
    board[curr_av[y]][y] = symbol;
    curr_av[y]--;
    n_moves--;
    return true;
}
bool Connect_4_Board::game_is_over() {
    return !n_moves;
}
void Connect_4_Board::clear_grid(int x, int y) {
    y--;
    curr_av[y] ++;

   board[curr_av[y]][y]=' ';
   n_moves++;

}