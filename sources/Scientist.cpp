#include "Scientist.hpp"
#include <iostream>
#include <sstream>

using namespace std;

namespace pandemic {

      Player& Scientist::discover_cure(Color color){
        if(board.cures[color]){
        return *this;
        }
        if(!board.cities[this->current_city].station){
            throw invalid_argument("cannot discovercure to beacasue there is no research station at " +board.cities[this->current_city].name);
            return *this;
        }
        int check = 0;
        for (auto city : this->cards) {
            if (board.cities[city].color==color) {
                check++;
            }
        }
        if(check < check_four){
        throw invalid_argument("cannot discover cure to " +board.cities[this->current_city].name);
        return *this;
        }
        
        int four = 0;
        for (auto c = this->cards.begin(); c != this->cards.end(); ) {
            if (board.cities[*c].color==color) { 
                c = this->cards.erase(c);
                four++;
            } else {++c;}
            if (four>=4) {
                break;
            }
        }
        board.cures[color] = true;  
        return *this;
    }
}