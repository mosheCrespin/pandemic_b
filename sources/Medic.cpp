//
// Created by moshe on 5/5/2021.
//

#include "Medic.hpp"

using namespace std;
namespace pandemic{


    Medic::Medic(Board &board, City city) : Player(board, city) {
        this->_role="Medic";
    }

    Player &Medic::fly_direct(City city) {
        Player::fly_direct(city);
        if(this->board.is_there_cure(Board::city_color(this->curr_city))){
            this->board[city]=0;
        }
        return *this;
    }

    Player &Medic::fly_charter(City city) {
        Player::fly_charter(city);
        if(this->board.is_there_cure(Board::city_color(this->curr_city))){
            this->board[city]=0;
        }
        return *this;
    }

    Player &Medic::fly_shuttle(City city) {
        Player::fly_shuttle(city);
        if(this->board.is_there_cure(Board::city_color(this->curr_city))){
            this->board[city]=0;
        }
        return *this;
    }

    Player &Medic::treat(City city) {
        Player::treat(city);
        this->board[city]=0;
        return *this;
    }

    Player &Medic::drive(City city) {
        Player::drive(city);
        if(this->board.is_there_cure(Board::city_color(this->curr_city))){
            this->board[city]=0;
        }
        return *this;
    }
}