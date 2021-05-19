//
// Created by moshe on 5/5/2021.
//

#ifndef UNTITLED5_BOARD_HPP
#define UNTITLED5_BOARD_HPP

#include <ostream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_set>
#include <unordered_map>
namespace pandemic {
    class Board {
    private:
        std::unordered_map<City, bool> research_stations;
        std::unordered_map<City, int> disease_cubes;
        std::unordered_set<Color> disease_cures;
        bool clean= true;//flag if board is clean
        int id;
    public:
        Board();
        void build(City city);
        bool is_clean();
        void remove_cures();
        bool is_there_cure(Color color);
        void set_cure(Color color);
        int &operator[](City city);
        void remove_stations();
        friend std::ostream &operator<<(std::ostream &out, Board &board);
        bool is_research_station(City city);
        void add_research_station(City city);
        static Color city_color(City city);
        static bool is_connected(City city_a,City city_b);

    };

}
#endif //UNTITLED5_BOARD_HPP
