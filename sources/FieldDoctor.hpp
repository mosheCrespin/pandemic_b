//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_FIELDDOCTOR_HPP
#define UNTITLED5_FIELDDOCTOR_HPP

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {
    class FieldDoctor : public Player {
    public:
        FieldDoctor(Board &board, City city);
        Player &treat(City city) override;


    };
}


#endif //UNTITLED5_FIELDDOCTOR_HPP
