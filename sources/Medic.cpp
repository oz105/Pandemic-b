#include "Medic.hpp"
#include <iostream>
#include <sstream>

using namespace std;

namespace pandemic {
    Player& Medic::treat(City c) {
        if(board[this->current_city] == 0){
            throw invalid_argument("the disease level at "+board.cities[c].name+"is already 0");
        }
        if (this->current_city !=c ) {
            throw invalid_argument("you can use treat only in your current city");
        }
        board[this->current_city] = 0;
        return *this;
    }
    
}