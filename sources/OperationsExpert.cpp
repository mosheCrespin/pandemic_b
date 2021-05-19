//
// Created by moshe on 5/5/2021.
//

#include "OperationsExpert.hpp"
using namespace std;
namespace pandemic{


    OperationsExpert::OperationsExpert(Board &board, City city) : Player(board, city) {
        this->_role="OperationsExpert";
    }

    Player &OperationsExpert::build() {
        this->board.add_research_station(this->curr_city);
        return *this;
    }
}