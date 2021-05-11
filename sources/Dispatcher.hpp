#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Dispatcher: public Player {
    public:
        Dispatcher(Board& b, City c): Player(b,c,"Dispatcher") {}
        ~Dispatcher() {}
        Player& fly_direct(City c);
    };
}