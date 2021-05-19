#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#pragma once

namespace pandemic
{
    class Player
    {
    protected:
        Board &my_board;
        City my_city;
        std::set<City> cards;

    public:
        Player(Board &board, City city) : my_board(board), my_city(city) {}

        Player();

        ~Player() {}

        Player &drive(City city);

        virtual Player &fly_direct(City city);

        Player &fly_charter(City city);

        Player &fly_shuttle(City city);

        virtual Player &build();

        virtual Player &discover_cure(Color color);

        virtual Player &treat(City city);
        
        virtual void arrived() {}

        virtual std::string role();

        Player &take_card(City city);

        Player &remove_cards();

        int get_num_of_card()
        {
            return cards.size();
        }
    };

}