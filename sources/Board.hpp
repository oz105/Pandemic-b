#pragma once
#include <unordered_map>
#include <iostream>
#include <set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic {
    
    // City Node contains information on the city 
    struct City_Node{
        std::string name;
        Color color;
        std::set<City> connections;
        bool station = false ;
    };

    class Board {
    public:


        int cure_counter = 0;
        int stations_counter = 0;

        std::unordered_map<City,City_Node> cities; // map with city as key and the information about it as a value

        std::unordered_map<City,int> disease_level; // hold the level of disease at the city , city as key level as value

        std::unordered_map<Color,bool> cures; // hold if for disease color already found cure

        std::unordered_map<City, std::string> city_to_string; 

        std::unordered_map<Color,std::string> color_to_string ;

        Board();
        ~Board() { }

        int& operator[](City city) ;// set the level of disease in the city by the operator [] return int& if we need to change it
            
        friend std::ostream& operator<<(std::ostream& os, Board& b);

        //Resetting the cures finding
        void remove_cures();

        //check if the the all board is clean from disease
        bool is_clean();
        
    };
}