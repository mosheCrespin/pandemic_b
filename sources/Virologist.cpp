//
// Created by moshe on 5/5/2021.
//

#include "Virologist.hpp"


using namespace std;
namespace pandemic{


    Virologist::Virologist(Board &board, City city) : Player(board, city) {
        this->_role="Virologist";
    }

    Player &Virologist::treat(City city) {
        if(board[city]==0){
            throw invalid_argument("Disease is already 0");
        }
        if(this->board.is_there_cure(Board::city_color(city))){
            board[city]=0;
        }else if(city==curr_city){
            Player::treat(city);
        }else if(this->player_cards.find(city)==this->player_cards.end()){
            throw invalid_argument("U don't have a valid card");
        } else{
            board[city]--;
        }
        return *this;
    }
}