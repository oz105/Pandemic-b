#include "OperationsExpert.hpp"
#include <iostream>

using namespace std;

namespace pandemic {

    Player& OperationsExpert::build(){
        if (board.cities[this->current_city].station) {
            return *this;
        }
        board.cities[this->current_city].station = true;
        this->board.stations_counter++;
        return *this;
    }
}