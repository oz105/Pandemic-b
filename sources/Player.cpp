#include "Player.hpp"
#include <iostream>
#include <sstream>


using namespace std;

const int check_five_color = 5 ;

namespace pandemic {

    void Player::show_cards(){
        for (auto city : this->cards) {
            cout << Board::get_city(city) << endl;
        }        
    }

    Player& Player::take_card(City c) {
        this->cards.insert(c);
        return *this;
    }

    Player& Player::fly_direct(City c) { // fly dircet to city by throw the card of the city
        if (this->current_city==c) {
            throw invalid_argument("you can not fly direct to your current city");
        }
        if (this->cards.count(c)==0) {
            throw invalid_argument("you cant fly direct if you dont have the card "+board.cities[c].name);
        }
        this->current_city = c;
        this->cards.erase(c);
        if(this->role() == "Medic"){ // check if medic to delete the diesease level in the city if there is cure 
            if (board.cures[board.cities[this->current_city].color]) {board[c] = 0;}
                return *this;
        }
        return *this;
    }

    Player& Player::treat(City c) { // use treat on the current city (-1 if there is no cure)
        if(board[this->current_city] == 0){
            throw invalid_argument("the disease level at "+board.cities[c].name+"is already 0");
        }
        if (this->current_city !=c ) {
            throw invalid_argument("you can use treat only in your current city");
        }
        if (board.cures[board.cities[this->current_city].color]) { // check if there is cure for this color
            board[this->current_city] = 0;
            return *this;
        }
        board[this->current_city]--;
        return *this;
    }

    Player& Player::fly_charter(City c) { //use current city card to fly 
        if (this->current_city==c) {
            throw invalid_argument("you can not fly charter to your current city");
        }
        if (this->cards.count(this->current_city)==0) {
            throw invalid_argument("you cant fly charter if you dont have the card "+board.cities[this->current_city].name);
        }
        this->cards.erase(this->current_city);
        this->current_city= c;
        if(this->role() == "Medic"){ // check if medic to delete the diesease level in the city if there is cure 
            if (board.cures[board.cities[this->current_city].color]) {board[c] = 0;}
                return *this;
        }
        return *this;
    }

    Player& Player::drive(City c) { // dirve between connected city 
        if (this->current_city==c) {
            throw invalid_argument("you cant drive to your current city");
        }
        if(board.cities[this->current_city].connections.count(c)==0){ // check if there is connection
            throw invalid_argument("the city " +board.cities[this->current_city].name + " and the city "+board.cities[c].name +" are not connected by drive" );
        }
        this->current_city = c;
        if(this->role() == "Medic"){ // check if medic to delete the diesease level in the city if there is cure 
            if (board.cures[board.cities[this->current_city].color]) {board[c] = 0;}
                return *this;
        }
        return *this;

    }

    Player& Player::fly_shuttle(City c) { // need to be 2 station to use that 
        if (this->current_city==c) {
            throw invalid_argument("you can not fly shuttle to your current city");
        }
        if (!board.cities[this->current_city].station || !board.cities[c].station) {
            throw invalid_argument("you cant fly shuttle if there is no research station in "+board.cities[this->current_city].name+" and in " +board.cities[c].name);
        }
        this->current_city= c;
        if(this->role() == "Medic"){ // check if medic to delete the diesease level in the city if there is cure 
            if (board.cures[board.cities[this->current_city].color]) {board[c] = 0;}
                return *this;
        }
        return *this;
    }

    Player& Player::build() { //build station at the city y use card
        if (board.cities[this->current_city].station) {
            return *this;
        }
        if (this->cards.count(this->current_city)==0) {
            throw invalid_argument("you need to have the card of your current city to build there research station");
        }
        if (!board.cities[this->current_city].station) {
            this->cards.erase(this->current_city);
            this->board.stations_counter++;
            board.cities[this->current_city].station = true;
        }
        return *this;
    }

    Player& Player::discover_cure(Color color) {
        if(!board.cities[this->current_city].station){
            throw invalid_argument("there is no research station at " +board.cities[this->current_city].name+ " so you cant discover cure here");
            return *this;
        }
        int check = 0;
        for (auto city : this->cards) { 
            if (board.cities[city].color==color) { //count the num of cards in this color
                check++;
            }
        }
        if (check<check_five_color) { // check if there is five and more to discover
            throw invalid_argument("(player) dont have enough cards");
            return *this;
        }
        if (board.cures[color]) {return *this;}
        int count = 0;
        for (auto city = this->cards.begin(); city != this->cards.end(); ) { // run over all cards until get to cards.end() = end of cards
            if (board.cities[*city].color==color) { // check the color
                city = this->cards.erase(city);
                count++;
            } else {++city;}
            if (count>=check_five_color) { // when he got to 5 break
                break;
            }
        }
        board.cures[color] = true; // find the cure color
        board.cure_counter ++ ; // add to the cures counter
        return *this;
    }

}