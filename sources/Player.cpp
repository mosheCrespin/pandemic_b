//
// Created by moshe on 5/5/2021.
//

#include "Player.hpp"



using namespace std;


pandemic::Player::Player(pandemic::Board& b, City city) : board(b), curr_city(city), _role("None") {
    this->number_of_cards_by_color[Yellow]=0;
    this->number_of_cards_by_color[Black]=0;
    this->number_of_cards_by_color[Blue]=0;
    this->number_of_cards_by_color[Red]=0;
}

pandemic::Player &pandemic::Player::fly_direct(pandemic::City city) {
    if(city==this->curr_city){
        throw invalid_argument("can't fly same city");
    }
    if(this->player_cards.find(city)!=this->player_cards.end()) {//if the player has this card
        this->curr_city = city;
        this->player_cards.erase(city);
        this->number_of_cards_by_color[Board::city_color(city)]--;
    }else{
        throw invalid_argument("U don't have a valid card for this flight!");
    }
    return *this;
}

pandemic::Player &pandemic::Player::fly_charter(pandemic::City city) {
    if(city==this->curr_city){
        throw invalid_argument("can't fly same city");
    }
    if(this->player_cards.find(curr_city)!=this->player_cards.end()) {
        this->player_cards.erase(this->curr_city);
        this->number_of_cards_by_color[Board::city_color(curr_city)]--;

        this->curr_city = city;
    }else{
        throw invalid_argument("U don't have a valid card for this flight!");
    }
    return *this;
}

pandemic::Player &pandemic::Player::fly_shuttle(pandemic::City city) {
    if(city==this->curr_city){
        throw invalid_argument("can't fly same city");
    }
    if(!this->board.is_research_station(this->curr_city)||!this->board.is_research_station(city)) {
        throw invalid_argument("for this flight U need to have research stations in both cities");
    }
    this->curr_city=city;
    return *this;

}

pandemic::Player &pandemic::Player::discover_cure(pandemic::Color color) {
    if(this->board.is_there_cure(color))
    {
        return *this;
    }
    if(this->number_of_cards_by_color[color]<num_five) {//there is not enough cards
        throw invalid_argument("there is not enough cards");
    }
    if(!this->board.is_research_station(this->curr_city)) {//if there is no research station
        throw invalid_argument("there is no Research station in this city");
    }
    unordered_set<City> temp;
    for(const auto &v: this->player_cards){
        if(pandemic::Board::city_color(v)==color){
            this->number_of_cards_by_color[color]--;
            temp.insert(v);
        }
    }
    for(const auto &v: temp) {
        this->player_cards.erase(v);
    }

    this->board.set_cure(color);
    return *this;
}

pandemic::Player &pandemic::Player::treat(City city) {
    if(city!=curr_city){
        throw invalid_argument("U are not in this city");
    }
    if(board[city]==0){
        throw invalid_argument("Disease is already 0");
    }
    if(this->board.is_there_cure(Board::city_color(curr_city))){
        board[city]=0;
    } else{
        this->board[city]--;
    }
    return *this;
}

pandemic::Player &pandemic::Player::take_card(pandemic::City city) {
    if(this->player_cards.find(city)==this->player_cards.end()) {//if the the card does not exists
        this->number_of_cards_by_color[pandemic::Board::city_color(city)]++;
        this->player_cards.insert(city);
    }
    return *this;
}

pandemic::Player &pandemic::Player::drive(pandemic::City city) {
    if(!Board::is_connected(this->curr_city,city)) {
        throw invalid_argument("cities are not neighbors");
    }
    this->curr_city=city;
    return *this;
}

pandemic::Player &pandemic::Player::build() {
    if(this->board.is_research_station(this->curr_city)){
        return *this;
        }
    if(this->player_cards.find(curr_city)==this->player_cards.end()) {
        throw invalid_argument("U don't have a valid card for this Operation");
    }
    this->board.add_research_station(this->curr_city);
    this->player_cards.erase(curr_city);
    this->number_of_cards_by_color[Board::city_color(curr_city)]--;
    return *this;
}

std::string &pandemic::Player::role() {
    return this->_role;
}

void pandemic::Player::remove_cards() {
    this->player_cards.clear();
}










