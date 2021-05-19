//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_PLAYER_HPP
#define UNTITLED5_PLAYER_HPP
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <unordered_set>
#include <unordered_map>


namespace pandemic {
    class Player {
    protected:
        City curr_city;
        std::unordered_set<City> player_cards;
        std::unordered_map<Color, int> number_of_cards_by_color;
        Board &board;
        std::string _role;

    public:
        Player(pandemic::Board &board, City city);

        virtual Player &fly_direct(City city);

        virtual Player &fly_charter(City city);

        virtual Player &fly_shuttle(City city);

        virtual Player& build();

        virtual Player &discover_cure(pandemic::Color color);

        virtual Player &treat(City city);
        Player& take_card(pandemic::City city);

        virtual Player& drive(City city);
        std::string &role();
        void remove_cards();


    };
    const int num_five=5;

}
#endif //UNTITLED5_PLAYER_HPP
