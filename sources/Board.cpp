#include "Board.hpp"
#include <iostream>

#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iomanip> 

using namespace std;

namespace pandemic {

        Board::Board() {
            
            cities = {
                {City::Algiers,(City_Node){"Algiers",Color::Black,{City::Madrid, City::Paris, City::Istanbul, City::Cairo}}},
                {City::Atlanta,(City_Node){"Atlanta",Color::Blue,{City::Chicago, City::Miami, City::Washington}}},
                {City::Baghdad,(City_Node){"Baghdad",Color::Black,{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}}},
                {City::Bangkok,(City_Node){"Bangkok",Color::Red,{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}}},
                {City::Beijing,(City_Node){"Beijing",Color::Red,{City::Shanghai, City::Seoul}}},
                {City::Bogota,(City_Node){"Bogota",Color::Yellow,{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}}},
                {City::BuenosAires,(City_Node){"BuenosAires",Color::Yellow,{City::Bogota, City::SaoPaulo}}},
                {City::Cairo,(City_Node){"Cairo",Color::Black,{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}}},
                {City::Chennai,(City_Node){"Chennai",Color::Black,{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}}},
                {City::Chicago,(City_Node){"Chicago",Color::Blue,{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}}},
                {City::Delhi,(City_Node){"Delhi",Color::Black,{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}}},
                {City::Essen,(City_Node){"Essen",Color::Blue,{City::London, City::Paris, City::Milan, City::StPetersburg}}},
                {City::HoChiMinhCity,(City_Node){"HoChiMinhCity",Color::Red,{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}}},
                {City::HongKong,(City_Node){"HongKong",Color::Red,{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}}},
                {City::Istanbul,(City_Node){"Istanbul",Color::Black,{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}}},
                {City::Jakarta,(City_Node){"Jakarta",Color::Red,{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}}},
                {City::Johannesburg,(City_Node){"Johannesburg",Color::Yellow,{City::Kinshasa, City::Khartoum}}},
                {City::Karachi,(City_Node){"Karachi",Color::Black,{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}}},
                {City::Khartoum,(City_Node){"Khartoum",Color::Yellow,{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}}},
                {City::Kinshasa,(City_Node){"Kinshasa",Color::Yellow,{City::Lagos, City::Khartoum, City::Johannesburg}}},
                {City::Kolkata,(City_Node){"Kolkata",Color::Black,{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}}},
                {City::Lagos,(City_Node){"Lagos",Color::Yellow,{City::SaoPaulo, City::Khartoum, City::Kinshasa}}},
                {City::Lima,(City_Node){"Lima",Color::Yellow,{City::MexicoCity, City::Bogota, City::Santiago}}},
                {City::London,(City_Node){"London",Color::Blue,{City::NewYork, City::Madrid, City::Essen, City::Paris}}},
                {City::LosAngeles,(City_Node){"LosAngeles",Color::Yellow,{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}}},
                {City::Madrid,(City_Node){"Madrid",Color::Blue,{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}}},
                {City::Manila,(City_Node){"Manila",Color::Red,{City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}}},
                {City::MexicoCity,(City_Node){"MexicoCity",Color::Yellow,{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}}},
                {City::Miami,(City_Node){"Miami",Color::Yellow,{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}}},
                {City::Milan,(City_Node){"Milan",Color::Blue,{City::Essen, City::Paris, City::Istanbul}}},
                {City::Montreal,(City_Node){"Montreal",Color::Blue,{City::Chicago, City::Washington, City::NewYork}}},
                {City::Moscow,(City_Node){"Moscow",Color::Black,{City::StPetersburg, City::Istanbul, City::Tehran}}},
                {City::Mumbai,(City_Node){"Mumbai",Color::Black,{City::Karachi, City::Delhi, City::Chennai}}},
                {City::NewYork,(City_Node){"NewYork",Color::Blue,{City::Montreal, City::Washington, City::London, City::Madrid}}},
                {City::Osaka,(City_Node){"Osaka",Color::Red,{City::Taipei, City::Tokyo}}},
                {City::Paris,(City_Node){"Paris",Color::Blue,{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}}},
                {City::Riyadh,(City_Node){"Riyadh",Color::Black,{City::Baghdad, City::Cairo, City::Karachi}}},
                {City::SanFrancisco,(City_Node){"SanFrancisco",Color::Blue,{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}}},
                {City::Santiago,(City_Node){"Santiago",Color::Yellow,{City::Lima}}},
                {City::SaoPaulo,(City_Node){"SaoPaulo",Color::Yellow,{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}}},
                {City::Seoul,(City_Node){"Seoul",Color::Red,{City::Beijing, City::Shanghai, City::Tokyo}}},
                {City::Shanghai,(City_Node){"Shanghai",Color::Red,{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}}},
                {City::StPetersburg,(City_Node){"StPetersburg",Color::Blue,{City::Essen, City::Istanbul, City::Moscow}}},
                {City::Sydney,(City_Node){"Sydney",Color::Red,{City::Jakarta, City::Manila, City::LosAngeles}}},
                {City::Taipei,(City_Node){"Taipei",Color::Red,{City::Shanghai, City::HongKong, City::Osaka, City::Manila}}},
                {City::Tehran,(City_Node){"Tehran",Color::Black,{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}}},
                {City::Tokyo,(City_Node){"Tokyo",Color::Red,{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}}},
                {City::Washington,(City_Node){"Washington",Color::Blue,{City::Atlanta, City::NewYork, City::Montreal, City::Miami}}}
            };
                // at the start all cures not found yet so set false
            cures = {
                {Color::Blue,false},
                {Color::Black,false},
                {Color::Red,false},
                {Color::Yellow,false}
                
            };
            disease_level = {};
        }

    bool Board::is_clean() {
        for (auto &p : cities) {
                if (disease_level.count(p.first)!=0&&disease_level[p.first]>0) {return false;}
        }
        return true;
    }

    int& Board::operator[](City city) { // set the level of disease in the city by the operator [] return int& if we need to change it
            return this->disease_level[city];
    }

     void Board::remove_cures() {
         for (auto &cure : cures) {
             cure.second = false;
         }    
    }

    /* output operator for Board object */
    ostream& operator<<(ostream& os, Board& b) {

    os << "-------------------- BOARD --------------------" << endl;

    os << "Research stations: " << endl;
    os << "Num of Research stations: " << b.stations_counter << endl;
    os << "cities with Research station :" << endl ;
    for (const auto &c : b.cities) {
        if(c.second.station){
            os << c.second.name << endl ;
        }
    }

    os << endl << "Level of diseases: " << endl ;
    for (const auto &c : b.cities) {
        os << "City: " << c.second.name << " = " << b[c.first] << endl ;
    }

    os << "Num Of Cures that discover: " << b.cure_counter << endl ;

    os << "------------------ END BOARD ------------------" << endl;
    return os;
        
    }
}