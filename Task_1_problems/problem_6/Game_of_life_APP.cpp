#include <bits/stdc++.h>
#include "Universe.h"
#include <unistd.h>
using namespace std;



string opt[] = {
        "New Game", "Load last game", "Exit"
};
string start[] = {
        "initialize the cells","display the universe","Next Generation","Run for certain number of of moves", "Run until halt", "main menu" , "Exit"
};
void main_menu();
void checkmate();
void play(int x, int y);
void Game_universe_making();
int main() {
main_menu();
}
void checkmate()
{
    system("cls");
    cout << "Hope You Enjoyed ^^\n";
    cout << "This Program Was Written By: \n";
    cout << "Sherif Youssef, Ahmed Yosry, and Mohamed Hesham\n";
    cout << "FCAI - CU [2022 - 2026]";
    usleep(INT32_MAX);
}
void play(int x, int y)
{
    Universe game(x, y);
    while (1) {
        int op;
        cout << "------------Play-----------\n";
        for (int i = 0; i < 7; i++) {
            cout << (i + 1) % 7 << ". " << start[i] << endl;
            cout << "-----------------------------\n";
        }

        while (true) {
            cout << "choice : ";
            cin >> op;
            if (op < 7 && op >= 0) {
                break;
            }
        }
        switch (op) {
            case 0:{
                system("cls");
                checkmate();
                return;
            }
            case 1: {
                system("cls");
                cout << "how many cells u want to change : ";
                cin >> op;
                game.initialize(op);
                break;
            }
            case 2: {
                system("cls");
                game.display();
                break;
            }
            case 3: {
                system("cls");
                game.next_generation();
                break;
            }
            case 4: {
                system("cls");
                double delay=0;
                int ch;
                cout<<"how many generations you want to display : "<<endl;
                cin>>op;
                cout<<"if u want a delay between generations :\n"
                      "1.No delay\n"
                      "2.custom delay\n";
                cout<<"--------------------------------";
                while (true){ cout<<"choice : ";
                    cin>>ch;
                    if(ch>0 && ch< 3) break;
                }
                if(ch==2){
                    cout<<"delay u want in seconds : ";
                    cin>>delay;
                }
                system("cls");
                game.run(op,delay);
                break;
            }
            case 5: {
                for(int i=0; i<1000 ; i++){
                    system("cls");
                    game.next_generation();
                }
            }
            case 6: {

                system("cls");
                main_menu();
                return;
            }
        }
    }
}
void Game_universe_making(){
    int x,y,op;
    cout<<"please enter the size of the game's universe u want to make :\n";
    cout<<"1. 20 rows x 50 columns \n"
          "-----------------------------\n"
          "2. 30 x 30 columns\n"
          "-----------------------------\n"
          "3. 20 x 20\n"
          "-----------------------------\n"
          "4. custom size\n"
          "-----------------------------\n"
          "5. main_menu\n"
          "-----------------------------\n";
    while (true){  cout<<"choice : ";
        cin>>op;
        if(op<6 && op>0) {
            break;
        }
    }
    switch(op){
        case 1: {
            system("cls");
            play(20, 50);
            break;
        }
        case 2: {
            system("cls");
            play(30,30);
            break;
        }
        case 3: {
            system("cls");
            play(20,20);
            break;
        }
        case 4: {

            cout<<"enter no. of rows :";cin>>x;
            cout<<"enter no. of columns :";cin>>y;
            system("cls");
            play(x, y);
            break;
        }
        case 5: {
            system("cls");
            main_menu();
            return;
        }
    }

}
void main_menu() {
    cout << "---------------Game of life-----------------" << endl;
    int op;
    for(int i =0; i < 3 ;i++) {
        cout <<(i+1)%3 << "." << opt[i] << endl;
        cout<<"-----------------------------\n";
    }
    while(1){
        cout<<"Choice : ";
        cin>>op;
        if(op==1){
            system("cls");
            Game_universe_making();
            break;
        }
        else if(op==2){
            cout<<"this feature is unavailable now please choose another one \n";
        }
        else if(op==0){
            checkmate();
            return ;

        }
    }
}
