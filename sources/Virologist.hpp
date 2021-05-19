//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_VIROLOGIST_HPP
#define UNTITLED5_VIROLOGIST_HPP

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic {
    class Virologist : public Player {
    public:
        Virologist(Board &board, City city) ;
        Player &treat(City city) override;

    };

}
#endif //UNTITLED5_VIROLOGIST_HPP
