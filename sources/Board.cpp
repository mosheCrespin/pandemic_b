//
// Created by moshe on 5/5/2021.
//

#include "Board.hpp"
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "Color.hpp"
using namespace std;
namespace pandemic {
    static std::unordered_map<City, unordered_set<City>> connections{
            {Algiers, {Madrid,Paris,Istanbul,Cairo
                      }},{Atlanta, {Chicago,Miami,Washington
                      }},{Baghdad, {Tehran,Istanbul,Cairo,Riyadh,Karachi
                      }},{Bangkok, {Kolkata,Chennai,Jakarta,HoChiMinhCity,HongKong
                      }},{Beijing, {Shanghai,Seoul
                      }},{Bogota, {MexicoCity,Lima,Miami,SaoPaulo,BuenosAires
                      }},{BuenosAires, {Bogota,SaoPaulo
                      }},{Cairo, {Algiers,Istanbul,Baghdad,Khartoum,Riyadh
                      }},{Chennai, {Mumbai,Delhi,Kolkata,Bangkok,Jakarta
                      }},{Chicago, {SanFrancisco,LosAngeles,MexicoCity,Atlanta,Montreal
                      }},{Delhi, {Tehran,Karachi,Mumbai,Chennai,Kolkata
                      }},{Essen, {London,Paris,Milan,StPetersburg
                      }},{HoChiMinhCity, {Jakarta,Bangkok,HongKong,Manila
                      }},{HongKong, {Bangkok,Kolkata,HoChiMinhCity,Shanghai,Manila,Taipei
                      }},{Istanbul, {Milan,Algiers,StPetersburg,Cairo,Baghdad,Moscow
                      }},{Jakarta, {Chennai,Bangkok,HoChiMinhCity,Sydney
                      }},{Johannesburg, {Kinshasa,Khartoum
                      }},{Karachi, {Tehran,Baghdad,Riyadh,Mumbai,Delhi
                      }},{Khartoum, {Cairo,Lagos,Kinshasa,Johannesburg
                      }},{Kinshasa, {Lagos,Khartoum,Johannesburg
                      }},{Kolkata, {Delhi,Chennai,Bangkok,HongKong
                      }},{Lagos, {SaoPaulo,Khartoum,Kinshasa
                      }},{Lima, {MexicoCity,Bogota,Santiago
                      }},{London, {NewYork,Madrid,Essen,Paris
                      }},{LosAngeles, {SanFrancisco,Chicago,MexicoCity,Sydney
                      }},{Madrid, {London,NewYork,Paris,SaoPaulo,Algiers
                      }},{Manila, {Taipei,SanFrancisco,HoChiMinhCity,Sydney,HongKong
                      }},{MexicoCity, {LosAngeles,Chicago,Miami,Lima,Bogota
                      }},{Miami, {Atlanta,MexicoCity,Washington,Bogota
                      }},{Milan, {Essen,Paris,Istanbul
                      }},{Montreal, {Chicago,Washington,NewYork
                      }},{Moscow, {StPetersburg,Istanbul,Tehran
                      }},{Mumbai, {Karachi,Delhi,Chennai
                      }},{NewYork, {Montreal,Washington,London,Madrid
                      }},{Osaka, {Taipei,Tokyo
                      }},{Paris, {Algiers,Essen,Madrid,Milan,London
                      }},{Riyadh, {Baghdad,Cairo,Karachi
                      }},{SanFrancisco, {LosAngeles,Chicago,Tokyo,Manila
                      }},{Santiago, {Lima
                      }},{SaoPaulo, {Bogota,BuenosAires,Lagos,Madrid
                      }},{Seoul, {Beijing,Shanghai,Tokyo
                      }},{Shanghai, {Beijing,HongKong,Taipei,Seoul,Tokyo
                      }},{StPetersburg, {Essen,Istanbul,Moscow
                      }},{Sydney, {Jakarta,Manila,LosAngeles
                      }},{Taipei, {Shanghai,HongKong,Osaka,Manila
                      }},{Tehran, {Baghdad,Moscow,Karachi,Delhi
                      }},{Tokyo, {Seoul,Shanghai,Osaka,SanFrancisco
                      }},{Washington, {Atlanta,NewYork,Montreal,Miami}}
    };
    static std::unordered_map<City, Color> city_colors{
            {Algiers,Black},
            {Atlanta,Blue},
            {Baghdad,Black},
            {Bangkok,Red},
            {Beijing,Red},
            {Bogota,Yellow},
            {BuenosAires,Yellow},
            {Cairo,Black},
            {Chennai,Black},
            {Chicago,Blue},
            {Delhi,Black},
            {Essen,Blue},
            {HoChiMinhCity,Red},
            {HongKong,Red},
            {Istanbul,Black},
            {Jakarta,Red},
            {Johannesburg,Yellow},
            {Karachi,Black},
            {Khartoum,Yellow},
            {Kinshasa,Yellow},
            {Kolkata,Black},
            {Lagos,Yellow},
            {Lima,Yellow},
            {London,Blue},
            {LosAngeles,Yellow},
            {Madrid,Blue},
            {Manila,Red},
            {MexicoCity,Yellow},
            {Miami,Yellow},
            {Milan,Blue},
            {Montreal,Blue},
            {Moscow,Black},
            {Mumbai,Black},
            {NewYork,Blue},
            {Osaka,Red},
            {Paris,Blue},
            {Riyadh,Black},
            {SanFrancisco,Blue},
            {Santiago,Yellow},
            {SaoPaulo,Yellow},
            {Seoul,Red},
            {Shanghai,Red},
            {StPetersburg,Blue},
            {Sydney,Red},
            {Taipei,Red},
            {Tehran,Black},
            {Tokyo,Red},
            {Washington,Blue}
    };
    static int _id=0;
    Board::Board() {
        this->id=_id;
        _id++;
    }

    void pandemic::Board::build(pandemic::City city) {
        this->research_stations[city]= true;
    }
    std::ostream &operator<<(std::ostream &out, pandemic::Board &board) {
        out << "-----------------Board--------------------"<<endl;
        out<<"--research stations-- "<<endl;
        for(const auto &v :board.research_stations){
            out<<v.first<<endl;
        }
        out<<"**********"<<endl;
        out<<"--cubes-- "<<endl;
        for(const auto &v :board.disease_cubes){
            out<<v.first<<"="<<v.second<<endl;
        }
        out<<"**********"<<endl;
        out<<"--cures:-- "<<endl;
        for(const auto &v :board.disease_cures){
            out<<v<<endl;
        }
        out<<"****************************"<<endl;

        return out;
    }


    int &pandemic::Board::operator[](pandemic::City city) {
        return disease_cubes[city];
    }

    bool Board::is_clean() {
        for (const auto &v : this->disease_cubes)
        {
            if(v.second!=0){
                return false;
            }
        }
        return true;
    }
    void Board::remove_cures() {
        this->disease_cures.clear();
    }

    void Board::remove_stations() {
        this->research_stations.clear();
        for(const auto &v : this->research_stations){
            this->research_stations[v.first]= false;
        }
    }

    bool Board::is_connected(City city_a, City city_b) {
        if(connections.find(city_a)==connections.end()||connections.find(city_a)==connections.end()){
            throw invalid_argument("not valid city");
        }
        return connections[city_a].find(city_b)!=connections[city_a].end();
    }

    Color Board::city_color(City city) {
        return city_colors[city];
    }

    bool Board::is_research_station(City city) {
        return this->research_stations[city];
    }

    bool Board::is_there_cure(Color color) {
        return this->disease_cures.find(color)!=this->disease_cures.end();

    }

    void Board::set_cure(Color color) {
            this->disease_cures.insert(color);
    }

    void Board::add_research_station(City city) {
        this->research_stations[city]= true;
    }

}