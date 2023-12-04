#include "Universe.h"
#include <bits/stdc++.h>
using namespace std;
#include <unistd.h>
int dx[] = {0, -1, 0, 1, 1, 1, -1, -1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};

bool Universe:: is_valid(int x, int y) const{
    return x>0 && y>0 && x<n_rows && y<n_cols;
}
Universe::Universe(int rows, int cols){
    n_rows=rows+1; n_cols=cols+1;
    grid  = new bool*[rows+1];
    temp = new bool*[rows+1];
    for (int i =    0; i < rows+1; i++){
        grid[i] = new bool[cols+1];
        temp[i] = new bool[cols+1];
    }
    reset();

}
void Universe::initialize(int num_of_changes){
    int x, y;
    while (num_of_changes--){

        cout<<"enter cell cordinates x and y to invert it's state : ";
        cin>>x>>y;
         if(is_valid(x,y)) {
             grid[x][y] = !grid[x][y];
             display();
             cout<<endl;

         }
         else num_of_changes++;

    }
}
void Universe::reset() {
    for (int i = 0; i < n_rows;i++){
        for (int j = 0; j < n_cols; j++){
            temp[i][j]=grid[i][j] = false;
        }
    }
}
int Universe::count_neighbors(int cordx, int cordy) {
    int cnt =0;
    for (int k = 0  ;k<8 ; k++) {
    int currx = cordx + dx[k], curry = cordy + dy[k];
    if(is_valid(currx,curry) && grid[currx][curry]){
        cnt++;
    }
    }
    return cnt;

}

void Universe::next_generation() {

    for (int i = 1; i < n_rows; i++) {
        for (int j = 1; j < n_cols; ++j) {
            int adj = count_neighbors(i, j);
            if (adj < 2 || adj > 3) { temp[i][j] = false; }
            else if (adj == 3) { temp[i][j] = true; }
            else { temp[i][j]=grid[i][j]; }
        }
    }
    swap(grid,temp);
    display();
}
void Universe::display() {

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
         if(i==0 || j== 0){
             cout <<"| "<< i + j  << " |";
             continue;
         }
         else  {
             cout<<"| "<<grid[i][j] <<" |";
         }
        }
       cout<<endl;
        for (int j = 0; j < n_cols; ++j) {
            cout<<"-----";
        }
        cout<<endl;

    }
}
void Universe::run(int run_for, double delay =0) {
    while(run_for--){
        next_generation();
        display();
        usleep(useconds_t (delay * 1000000));
    }
}
