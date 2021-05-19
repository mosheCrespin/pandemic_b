//
// Created by moshe on 5/5/2021.
//

#include "Scientist.hpp"
using namespace std;

namespace pandemic{

    Scientist::Scientist(Board &board, City city, int i): Player(board, city) {
        this->_role="Scientist";
        this->n=i;
    }

    Player &Scientist::discover_cure(pandemic::Color color) {
        if(this->board.is_there_cure(color))
        {
            return *this;
        }
        if(!this->board.is_research_station(this->curr_city)){//if there is no research station
            throw invalid_argument("there is no Research station in this city");
        }
        if(this->number_of_cards_by_color[color]<this->n) {//there is not enough cards
                throw invalid_argument("there is not enough cards");
        }
        unordered_set<City> temp;
        for(const auto &v: this->player_cards){
            if(pandemic::Board::city_color(v)==color){
                temp.insert(v);
                this->number_of_cards_by_color[color]--;
            }
        }
        for(const auto &v : temp){
            this->player_cards.erase(v);
        }
        this->board.set_cure(color);
        return *this;
    }
}