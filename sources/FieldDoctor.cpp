#include "FieldDoctor.hpp"
#include <iostream>
#include <sstream>

using namespace std;

namespace pandemic {

    Player& FieldDoctor::treat(City c){ // can make treat with connections city
        if(board[c] == 0 ){
            throw invalid_argument("you can not use treat"); // check if the level is 0 and throw err
        }

        bool flag = false; // use to check if threr is connection between this cities

        if(this->current_city == c){
            if(board.cures[board.cities[c].color]){ // check if there is cure 
                board[c] = 0 ;
            }
            else{
                board[c] -- ; // if threre is not remove 1
            }
        }
        else{
            for (auto n : board.cities[this->current_city].connections){ // check if there is connection
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
            else{ // there is no connection so throw err 
                throw invalid_argument("the city " +board.cities[this->current_city].name + " and the city "+board.cities[c].name +" are not connected");
            }
        }
        return *this;
    }   
}