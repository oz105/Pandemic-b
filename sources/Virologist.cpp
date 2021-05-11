#include "Virologist.hpp"
#include <iostream>
#include <sstream>

using namespace std;

namespace pandemic {


    Player& Virologist::treat(City c){
        if (board[c] == 0) {
            throw invalid_argument("the disease level at "+board.cities[c].name+"is already 0");
        }
        if(this->current_city != c) {
            if(this->cards.count(c)==0){
                throw invalid_argument("you dont have the card of the city "+board.cities[c].name);
            }  
        } 
        if(this->current_city == c){
            if (board.cures[board.cities[this->current_city].color]) {
                board[this->current_city] = 0;
            }
            else{
                board[this->current_city]--;
            }
        }
        else{
            this->cards.erase(c);
            if (board.cures[board.cities[c].color]) {
                board[c] = 0;
            }
            else{
                board[c]--;
            }
        }
            return *this;
    }
    
}