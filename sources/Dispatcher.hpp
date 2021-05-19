//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_DISPATCHER_HPP
#define UNTITLED5_DISPATCHER_HPP

#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {
    class Dispatcher : public Player {
    public:
        Dispatcher(Board &board, City city);
        Player &fly_direct(City city) override;

    };
}


#endif //UNTITLED5_DISPATCHER_HPP
