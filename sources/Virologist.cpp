#include "Virologist.hpp"
using namespace std;

namespace pandemic
{
    Player &Virologist::treat(City city)
    {
        if (cards.find(city) == cards.end() && my_city != city)
        {
            throw invalid_argument("Illegal action. you do not have the card of " + city_to_string.at(city));
        }
        if (my_board[city] == 0)
        {
            throw invalid_argument("Illegal action. The disease level in the city " + city_to_string.at(city) + " is 0");
        }
        if (!my_board.is_cure_discovered(city))
        {
            my_board[city]--;
        }
        else
        {
            my_board[city] = 0;
        }
        return *this;
    }
}