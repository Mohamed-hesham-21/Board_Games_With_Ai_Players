// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include "Pyramid_X_O.cpp"
#include"Player.cpp"
#include"RandomPlayer.cpp"
#include"GameManager.cpp"
#include"X_O_Board.cpp"
#include"Connect_4_Board.cpp"
#include"XO_5x5_board.cpp"
#include"AI_player.cpp"

using namespace std;
void checkmate()
{
    system("cls");
    cout << "Hope You Enjoyed ^^\n";
    cout << "This Program Was Written By: \n";
    cout << "Mohamed Hesham and Ahmed Yosry\n";
    cout << "FCAI - CU [2022 - 2026]";
    system("pause");
}
int main() {
    int op;
    Board* Game;
    bool Ai_Players[2];
    Player* players[2];
    GameManager* GameRunner;
    char symbol;
    while (true) {
        cout << "------------------Welcome ya A7la user :)!------------------" << endl;
        cout << "1.X_O:3x3 game\n"
                "2.X_O:pyramidic game\n"
                "3.X_O:Connect 4 game\n"
                "4.X_O:5x5 tic tac game\n"
                "0. Exit\n";
        while (1) {
            cout << "choice : ";
            cin >> op;
            if (op < 5 && op > -1) {
                break;
            }
        }
        switch (op) {
            case 1: {
                Game = new X_O_Board;
                break;
            }
            case 2: {
                Game = new Pyramid;
                break;
            }
            case 3: {
                Game = new Connect_4_Board;
                break;
            }
            case 4: {
                Game = new XO_5x5_board;
                break;
            }
            default: {
                checkmate();
            }
        }
        for (int i = 0; i < 2; i++) {
            cout << "Player " << i + 1 << " :" << endl;
            cout << "1.Real player \n"
                    "2.ez Bot\n"
                    "3.Ai Bot\n";
            while (1) {
                cout << "choice : ";
                cin >> op;
                if (op < 4 && op > 0) {
                    break;
                }
            }
            switch (op) {
                case 1: {
                    cout << "enter your symbol : ";
                    cin >> symbol;
                    players[i] = new Player(i + 1, symbol);
                    break;
                }
                case 2: {

                    players[i] = new RandomPlayer(i % 2 == 0 ? 'x' : 'o', 10);
                    break;
                }
                case 3: {
                    players[i] = new AI_player(Game,i % 2 == 0 ? 'x' : 'o');
                    Ai_Players[i]= true;
                    break;
                }
            }
        }
        for (int i = 0; i<2;i++){
            if(Ai_Players[i]){
                players[i]->get_enemy_symbol(players[i%2?0:1]->get_symbol());
            }
        }
        system("cls");
        GameRunner = new GameManager(Game, players);
        GameRunner->run();
        delete GameRunner;
        delete* players;
        cout<<"\n1.New Game \n"
              "2.Exit\n";
        while(1) {
            cout<<"choice : "<<endl;
            cin >> op;
            if(op==1){
                break;
            }
            else if(op==2){
               checkmate();
                break;
            }
        };
    }
    }




