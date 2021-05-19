#include "FieldDoctor.hpp"
using namespace std;

namespace pandemic
{
    Player &FieldDoctor::treat(City city)
    {
        if (my_city != city && !Board::is_connected(my_city, city))
        {
            throw invalid_argument("Illegal action. Cities are not connected");
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