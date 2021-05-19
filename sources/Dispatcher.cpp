#include "Dispatcher.hpp"
using namespace std;

namespace pandemic
{
    Player &Dispatcher::fly_direct(City city) 
    {
        if (my_city == city)
        {
            throw invalid_argument("Illegal action. You are already in " + city_to_string.at(city));
        }
        if (my_board.is_built(my_city))
        {
            my_city = city;
        }
        else
        {
            return Player::fly_direct(city);
        }
        
        return *this;
    }
}