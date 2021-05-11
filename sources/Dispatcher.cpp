#include "Dispatcher.hpp"
#include <iostream>
#include <sstream>

using namespace std;

namespace pandemic {
    Player& Dispatcher::fly_direct(City c) {
        if (this->current_city==c) {
            throw invalid_argument("you cant fly direct to your current city");
        }
        if (this->cards.count(c)< 1 && !board.cities[this->current_city].station) {
            throw invalid_argument("you cant fly direct if you dont have the card "+board.cities[c].name);
        }
        if (!board.cities[this->current_city].station) {
            this->cards.erase(c);
        }
        this->current_city = c;
        return *this;
    }
}