//
// Created by moshe on 5/5/2021.
//

#include "GeneSplicer.hpp"

using namespace std;
namespace pandemic{

    GeneSplicer::GeneSplicer(Board &board, City city): Player(board, city) {
        this->_role="GeneSplicer";
    }

    Player &GeneSplicer::discover_cure(pandemic::Color color) {
        if(this->board.is_there_cure(color))
        {
            return *this;
        }
        if(!this->board.is_research_station(this->curr_city)) {//if there is no research station
            throw invalid_argument("there is no Research station in this city");
        }
        if(this->player_cards.size()<num_five) {//there is not enough cards
                throw invalid_argument("there is not enough cards");
            }
        unordered_set<City> temp;
        for(const auto &v: this->player_cards){
                this->number_of_cards_by_color[Board::city_color(v)]--;
                temp.insert(v);
            }
        for(const auto &v: temp) {
            this->player_cards.erase(v);
        }
        this->board.set_cure(color);
        return *this;

    }
}