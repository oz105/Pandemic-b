#include "Researcher.hpp"
#include <iostream>
#include <sstream>

using namespace std;

const int check_five_color = 5;

namespace pandemic {

     Player& Researcher::discover_cure(Color color){
        if(board.cures[color]){
            return *this;
        }
        int check = 0;
        for (auto city : this->cards) {
            if (board.cities[city].color==color) {
                check++;
            }
        }
        if(check < check_five_color){
            throw invalid_argument("dont have enough cards");
            return *this;
        }
        int five = 0;
        for (auto c = this->cards.begin(); c != this->cards.end(); ) {
            if (board.cities[*c].color==color) { 
                c = this->cards.erase(c);
                five++;
            } else {++c;}
            if (five>=check_five_color) {
                break;
            }
        }
        board.cures[color] = true;
        return *this;
    }
}