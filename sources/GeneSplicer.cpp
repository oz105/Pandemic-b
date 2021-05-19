#include "GeneSplicer.hpp"
#include <iostream>
#include <sstream>

using namespace std;

const int check_five_color = 5;

namespace pandemic {

        Player& GeneSplicer::discover_cure(Color color){ // can make it with 5 cards no in the same color
        if(!board.cities[this->current_city].station){ // check if there is station
            throw invalid_argument("cannot discover cure to becasue there is no research station at" +board.cities[this->current_city].name);
            return *this;
        }
        if(board.cures[color]){
            return *this;
        }
        if(this->cards.size() < check_five_color){
            throw invalid_argument("dont have enough cards");
        }
        if(this->cards.size() >= check_five_color){ // check the size of his cards
            int count = 0;
            for (auto city = this->cards.begin(); city != this->cards.end(); ) {
                city = this->cards.erase(city);
                count++;
                ++city;
                if (count>=check_five_color) {
                    break;
                }
            }
            board.cures[color] = true;
        }
        return *this;
    }

}