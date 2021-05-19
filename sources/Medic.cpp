#include "Medic.hpp"
using namespace std;

namespace pandemic
{
    Player &Medic::treat(City city)
    {
        if (my_city != city)
        {
            throw invalid_argument("Illegal action. you cannot treat a city you are not in");
        }
        if (my_board[city] == 0)
        {
            throw invalid_argument("Illegal action. The disease level in the city " + city_to_string.at(city) + " is 0");
        }

        my_board[city] = 0;

        return *this;
    }

    void Medic::arrived()
    {
        if (my_board.is_cure_discovered(my_city))
        {
            my_board[my_city] = 0;
        }
    }
}