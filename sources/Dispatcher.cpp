//
// Created by moshe on 5/5/2021.
//

#include "Dispatcher.hpp"
using namespace std;
namespace pandemic{

    Dispatcher::Dispatcher(Board &board, City city): Player(board, city) {
        this->_role="Dispatcher";
    }

    Player &Dispatcher::fly_direct(City city) {
        if(city==this->curr_city){
            throw invalid_argument("can't fly same city");
        }

        if(this->board.is_research_station(this->curr_city)){
            this->curr_city=city;
            return *this;
        }

        if(this->player_cards.find(city)!=this->player_cards.end()){
            this->curr_city = city;
            this->player_cards.erase(city);
            this->number_of_cards_by_color[Board::city_color(city)]--;
            return *this;
        }
        throw invalid_argument("not research station");

    }

}
