#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Scientist: public Player {

        private:
            int check_four ;
        public:
            Scientist(Board& board, City city , int check):Player(board, city, "Scientist"){
                check_four = check ;
            }
            ~Scientist(){}
            Player& discover_cure(Color);
    };

}