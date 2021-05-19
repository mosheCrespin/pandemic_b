//
// Created by moshe on 5/5/2021.
//

#include "Researcher.hpp"

using namespace std;
namespace pandemic{
    Researcher::Researcher(Board &board, City city): Player(board, city) {
        this->_role="Researcher";
    }

    Player &Researcher::discover_cure(pandemic::Color color) {
        if(this->board.is_there_cure(color))
        {
            return *this;
        }
        if(this->number_of_cards_by_color[color]<num_five) {//there is not enough cards
                throw invalid_argument("there is not enough cards");
        }
        unordered_set<City> temp;
        for(const auto &v: this->player_cards){
            if(pandemic::Board::city_color(v)==color){
                this->number_of_cards_by_color[color]--;
                temp.insert(v);
            }
        }
        for(const auto &v : temp){
            this->player_cards.erase(v);
        }
        this->board.set_cure(color);
        return *this;
    }


}
