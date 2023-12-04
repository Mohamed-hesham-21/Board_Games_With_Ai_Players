
#ifndef GAME_OF_LIFE_UNIVERSE_H
#define GAME_OF_LIFE_UNIVERSE_H
#include <iostream>
using namespace std;
class Universe {
protected:
    int n_cols{}, n_rows{};
    bool ** grid=nullptr, ** temp=nullptr;
    int adj_cnt{};
public:
    explicit Universe(int n_cols=0, int n_rows=0);
    void initialize(int num_of_changes);
    void reset();
    void display();
    void run(int,double);
    void next_generation();
    bool is_valid(int,int) const;
    int count_neighbors(int , int );
};

#endif //GAME_OF_LIFE_UNIVERSE_H
