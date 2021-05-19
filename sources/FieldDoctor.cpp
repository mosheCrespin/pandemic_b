//
// Created by moshe on 5/5/2021.
//

#include "FieldDoctor.hpp"
using namespace std;
namespace pandemic {


    FieldDoctor::FieldDoctor(Board &board, City city) : Player(board, city) {
        this->_role = "FieldDoctor";
    }

    Player &FieldDoctor::treat(City city) {
        if (city == curr_city) {
            Player::treat(city);
            return *this;
        }
        if (!Board::is_connected(city, curr_city)) {
            throw invalid_argument("cities are not neighbors");
        }
        if (board[city] == 0) {
            throw invalid_argument("Disease is already 0");
        }
        if (this->board.is_there_cure(Board::city_color(city))) {
            board[city] = 0;
        } else {
            board[city]--;
        }
        return *this;
    }

}