#include"BoardGame_Classes.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


class Pyramid : public Board {
public:
    Pyramid( )  {
        n_cols= 5;
        n_rows= 3;
         board = new char*[n_rows];
         zero_postion='#';
        for (int i = 0; i < n_rows; ++i) {
            board[i] = new char[n_cols];
        }

        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                if (valid_move(i,j))board[i][j]='#';
                else board[i][j]=' ';
            }
        }

    }
    bool valid_move(int x , int y ) override{
        if (x==0&&y==2)return true;
        else if (x==1&&y<=3&&y>=1)return true;
        else if (x==2&&y<=4&&y>=0)return true;
        return false;
    }

    char winner;
    bool update_board (int x, int y, char symbol) override{
        if (x==0&&y==2){
            if (board[x][y]!='#'){
                return false;
            }
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
        string ans = "";
        for (int i = 0; i < 3; ++i) {
            check+=board[i][2];
        }
        if (board[0][2]==board[1][2]&&board[1][2]==board[2][2]&&board[0][2]!='#')
        {
            return true;
        }


        if (board[1][1]==board[1][2]&&board[1][2]==board[1][3]&&board[1][3]!='#')
        {
            return true;
        }



        for (int i = 0; i < 3; ++i) {
            check+=board[i][2-i];
        }
        if (board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]!='#')
        {
            return true;
        }




        for (int i = 0; i < 3; ++i) {
            check+=board[i][2+i];
        }
        if (board[0][2]==board[1][3]&&board[1][3]==board[2][4]&&board[2][4]!='#')
        {
            return true;
        }


        for (int i = 0; i < 4; ++i) {
            if (board[2][i]==board[2][i-1]&&board[2][i]==board[2][i+1]&&board[2][i]!='#'){winner = board[2][i];return true;}
        }
        return false;
    }

    bool is_draw() override {
        if (n_moves==9){return true;}
        else return false;
    }
    void display_board() override{
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                cout << board[i][j]<<" ";
            }cout <<endl;
        }
    }
    void clear_grid(int x,int y) override{
        n_moves--;
        board[x][y]='#';
    }

   bool game_is_over() override{
        if(is_winner()){return true;}
        else if(is_draw()){return true;}
        return false;
    }
};
