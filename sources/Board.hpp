#include <iostream>
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#pragma once

namespace pandemic
{
    class Board
    {
    private:
        static std::map<City, std::set<City>> connected_cities;
        std::map<City, int> disease_cubes;
        std::set<Color> discovered_cure;
        std::set<City> research_stations;

    public:
        Board() {}

        ~Board() {}

        void build_research_station(City city);

        bool is_built(City city);

        void mark_discover(Color color);

        bool is_cure_discovered(City city);

        bool is_clean();

        void read_cities();

        void remove_cures();

        void remove_stations();

        static Color get_color_of_city(City city)
        {
            return cities_colors.at(city);
        }

        static bool is_connected(City &city1, City &city2);

        int &operator[](City city);

        friend std::ostream &operator<<(std::ostream &os, Board &board);
    };
}