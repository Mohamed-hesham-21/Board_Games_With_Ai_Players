// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#ifndef BoardGame_CLASSES_H
#define BoardGame_CLASSES_H
#include <bits/stdc++.h>
using namespace std;
 int dx[8] = {0, -1, 0, 1, 1, 1, -1, -1};
int dy[8] = {-1, 0, 1, 0, 1, -1, -1, 1};
class Board {
protected:
  int n_rows{}, n_cols{};
   char** board{};
   int  n_moves = 0;
   char zero_postion=0;
    set<set<pair<int,int>>>set_winner;
    set<pair<int,int>>set;
friend class GameManager;
public:
   // Return true  if move is valid and put it on board
   // within board boundaries in empty cell
   // Return false otherwise
   virtual bool valid_move(int , int )=0;
   virtual void clear_grid(int,int)=0;
    virtual bool is_winner() = 0;
   virtual bool update_board (int x, int y, char symbol) = 0;
   // Returns true if there is any winner
   // either X or O
   // Written in a complex way. DO NOT DO LIKE THIS.
  virtual unsigned long long count_winner(char){return 0;};
   // Return true if all moves are done and no winner
   virtual bool is_draw() = 0;
   // Display the board and the pieces on it
   virtual void display_board() = 0;
   // Return true if game is over
   virtual bool game_is_over() = 0;
   virtual pair<int,int> get_rows(){ return {n_rows,n_cols};}
};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board:public Board {
public:
   X_O_Board ();
   bool valid_move(int x, int y);
   bool update_board (int x, int y, char mark) override;
   void display_board() override;
   bool is_winner() override;
   bool is_draw() override;
   bool game_is_over()  override;
   void clear_grid(int,int)  override;

};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
    protected:
        string name;
        char symbol;
    public:
        // Two constructors to initiate player
        // Give player a symbol to use in playing
        // It can be X or O or others
        // Optionally, you can give him ID or order
        // Like Player 1 and Player 2
        explicit Player (char symbol); // Needed for computer players
        Player (int order, char symbol);
        // Get desired move: x y (each between 0 and 2)
        // Virtual (can change for other player types)
        virtual void get_move(int& x, int& y);
        // Give player info as a string
        string to_string();
        // Get symbol used by player
        [[nodiscard]] char get_symbol() const;
        virtual void get_enemy_symbol(char );
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
    protected:
        int dimension;
    public:
        // Take a symbol and pass it to parent
        RandomPlayer (char symbol, int dimension);
        // Generate a random move
        void get_move(int& x, int& y) override;

};

// class AiPlayer: public Player {
//     protected:
//         int dimension;
//     public:
//         // Take a symbol and pass it to parent
//         AiPlayer (char symbol, int dimension);
//         // Generate a random move
//         void get_move (char ** board,int d, bool ismx);
//         void whos_winner(char board [3][5]);
// };

///////////////////////////////////////////
class GameManager {
    private:
        Board* boardPtr;
        Player* players[2];
    public:
        GameManager(Board*, Player* playerPtr[2]);
        void run();
        // This method creates board and players
        // It displays board
        // While True
        //   For each player
        //      It takes a valid move as x, y pair (between 0 - 2)
        //      It updates board and displays otit
        //      If winner, declare so and end
        //      If draw, declare so and end

};

#endif
