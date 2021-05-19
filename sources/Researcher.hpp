//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_RESEARCHER_HPP
#define UNTITLED5_RESEARCHER_HPP

#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {
    class Researcher : public Player {
    public:
        Researcher(Board &board, City city);
        Player &discover_cure(pandemic::Color color) override;

    };
}

#endif //UNTITLED5_RESEARCHER_HPP
