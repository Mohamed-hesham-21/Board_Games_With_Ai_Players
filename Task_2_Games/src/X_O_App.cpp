// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "Pyramid_X_O.cpp"
#include"Player.cpp"
#include"RandomPlayer.cpp"
#include"GameManager.cpp"
#include"X_O_Board.cpp"
#include"Connect_4_Board.cpp"
#include"XO_5x5_board.cpp"

using namespace std;

int main() {
    
    

    cout <<"Which Game do you want to play?"<<endl;
    cout <<"1. Connect 4"<<endl;
    cout <<"2. 5x5 Tic Tac Toe"<<endl;
    cout <<"3. Pyramid Tic Tac Toe"<<endl;
    int op ;
    cin >> op;

        if (op==1)
        {
        Player* players[2];
        players[0] = new Player (1, 'x');
        cout <<"Do you want to play against a Computer or Another Player?\n";
        cout <<"1. Computer"<<endl;
        cout <<"2. Another Player"<<endl;
        int choice;
        cin >> choice;
        if (choice==1){players[1]= new RandomPlayer(2,'o');}
        else players[1]= new Player(2, 'o');
        GameManager x_o_game (new Connect_4_Board(), players);
        x_o_game.run();
        }
        else if (op==2)
        {
        Player* players[2];
        players[0] = new Player (1, 'x');
        cout <<"Do you want to play against a Computer or Another Player?\n";
        cout <<"1. Computer"<<endl;
        cout <<"2. Another Player"<<endl;
        int choice;
        cin >> choice;
        if (choice==1){players[1]= new RandomPlayer(2, 'o');}
        else players[1]= new Player(2, 'o');
        GameManager x_o_game (new XO_5x5_board(), players);
        x_o_game.run();
        }
        else if (op==3)
        {
        Player* players[2];
        players[0] = new Player (1, 'x');
        cout <<"Do you want to play against a Computer or Another Player?\n";
        cout <<"1. Computer"<<endl;
        cout <<"2. Another Player"<<endl;
        int choice;
        cin >> choice;
        if (choice==1){players[1]= new RandomPlayer(2, 'o');}
        else players[1]= new Player(2, 'o');
        GameManager x_o_game (new Pyramid(), players);
        x_o_game.run();
        }
    
    
       

    
        
    
    
    
}
