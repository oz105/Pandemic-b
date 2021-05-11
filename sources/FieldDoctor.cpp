#include "FieldDoctor.hpp"
#include <iostream>
#include <sstream>

using namespace std;

namespace pandemic {

    Player& FieldDoctor::treat(City c){
        if(board[c] == 0 ){
            throw invalid_argument("you can not use treat");
        }

        bool flag = false;

        if(this->current_city == c){
            if(board.cures[board.cities[c].color]){
                board[c] = 0 ;
            }
            else{
                board[c] -- ;
            }
        }
        else{
            for (auto n : board.cities[this->current_city].connections){
                if(n==c){
                    flag = true ;
                    break;
                }
            }
            if(flag){
                if(board.cures[board.cities[c].color]){
                        board[c] = 0 ;
                }
                else{
                        board[c] -- ;
                }
            }
            else{
                throw invalid_argument("the city " +board.cities[this->current_city].name + " and the city "+board.cities[c].name +" are not connected");
            }
        }
        return *this;
    }   
}