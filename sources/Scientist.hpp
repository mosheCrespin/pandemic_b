//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_SCIENTIST_HPP
#define UNTITLED5_SCIENTIST_HPP

#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {
    class Scientist : public Player {
    private:
        int n;
    public:
        Scientist(Board &board, City city, int i);
        Player &discover_cure(pandemic::Color color) override;

    };
}

#endif //UNTITLED5_SCIENTIST_HPP
