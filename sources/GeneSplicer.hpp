//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_GENESPLICER_HPP
#define UNTITLED5_GENESPLICER_HPP


#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {
    class GeneSplicer : public Player {
    public:
        GeneSplicer(Board &board, City city);
        Player &discover_cure(pandemic::Color color) override;


    };
}



#endif //UNTITLED5_GENESPLICER_HPP
