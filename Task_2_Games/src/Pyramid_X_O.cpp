#include"../include/BoardGame_Classes.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool in_range(int x , int y ){
    if (x==0&&y==2)return true;
    else if (x==1&&y<=3&&y>=1)return true;
    else if (x==2&&y<=4&&y>=0)return true;
    return false;
}
class Pyramid : public Board {
public:
    Pyramid( )  {
        n_cols= 5;
        n_rows= 3;
         board = new char*[n_rows];
        for (int i = 0; i < n_rows; ++i) {
            board[i] = new char[n_cols];
        }

        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                if (in_range(i,j))board[i][j]='#';
                else board[i][j]=' ';
            }
        }

    }
protected: char winner;
    bool update_board (int x, int y, char symbol){
        if (x==0&&y==2){
            if (board[x][y]!='#'){
                
                return false;}
            else board[x][y]=symbol;
            n_moves++;
            return true;
        }
        else if (x==1&&y<=3&&y>=1){
            if (board[x][y]!='#'){
                
                return false;}
            else board[x][y]=symbol;
            n_moves++;
            return  true;
        }

        else if (x==2&&y<=4&&y>=0){
            if (board[x][y]!='#'){
                
                return false;}
            else board[x][y]=symbol;
            n_moves++;
            return true;
        }

        else {
            
            return false;}
    }

    virtual bool is_winner(){
        string check = "";

        for (int i = 0; i < 3; ++i) {
            check+=board[i][2];
        }

        if (check=="xxx"||check=="ooo"){winner = check[0];return true;}
        else check = "";

        for (int i = 1; i < 4; ++i) {
            check+=board[1][i];
        }

        if (check=="xxx"||check=="ooo"){winner = check[0];return true;}
        else check = "";

        for (int i = 0; i < 3; ++i) {
            check+=board[i][2-i];
        }

        if (check=="xxx"||check=="ooo"){winner = check[0];return true;}
        else check = "";

        for (int i = 0; i < 3; ++i) {
            check+=board[i][2+i];
        }
        if (check=="xxx"||check=="ooo"){winner = check[0];return true;}
        else check = "";


        for (int i = 1; i < 3; ++i) {
            if (board[2][i]==board[2][i-1]&&board[2][i]==board[2][i+1]&&board[2][i]!='#'){winner = board[2][i];return true;}
        }
        return false;
    }

    virtual bool is_draw() {
        if (n_moves==9){return true;}
        else return false;
    }
    virtual void display_board(){
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                cout << board[i][j]<<" ";
            }cout <<endl;
        }
    }

    virtual bool game_is_over(){
       
       
        if(is_winner()){return true;}
        else if(is_draw()){return true;}
        return false;
}

};
