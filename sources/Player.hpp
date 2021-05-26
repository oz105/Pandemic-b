#pragma once
#include <iostream>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic {

    class Player {

    protected:
        pandemic::Board& board;
        std::string m_role;
        City current_city;
        std::set<City> cards = {};
    public:
        Player(Board& b, City c, std::string r): board(b), current_city(c), m_role(r) { } // string should be const and & 
        ~Player() {}

        void remove_cards(){this->cards.clear();}

        void show_cards();

        Player& drive(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        Player& take_card(City c);
        std::string role() {return m_role;}
        
        
        virtual Player& build();
        virtual Player& treat(City c);
        virtual Player& fly_direct(City c);
        virtual Player& discover_cure(Color c);
        
    };
}