//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_OPERATIONSEXPERT_HPP
#define UNTITLED5_OPERATIONSEXPERT_HPP

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {
    class OperationsExpert : public Player {
    public:
        OperationsExpert(Board &board, City city) ;
        Player& build() override;

    };
}


#endif //UNTITLED5_OPERATIONSEXPERT_HPP
