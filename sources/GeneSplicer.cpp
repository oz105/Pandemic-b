#include "GeneSplicer.hpp"
#include <iostream>
#include <sstream>

using namespace std;

const int check_five_color = 5;

namespace pandemic {

        Player& GeneSplicer::discover_cure(Color color){
        if(!board.cities[this->current_city].station){
            throw invalid_argument("cannot discover cure to becasue there is no research station at" +board.cities[this->current_city].name);
            return *this;
        }
        if(board.cures[color]){
            return *this;
        }
        if(this->cards.size() < check_five_color){
            throw invalid_argument("dont have enough cards");
        }
        if(this->cards.size() >= check_five_color){
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