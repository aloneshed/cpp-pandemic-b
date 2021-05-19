#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Player.hpp"
const int cards_to_discard = 5;
namespace pandemic
{

    Player &Player::drive(City city)
    {
        if (my_city == city)
        {
            throw invalid_argument("Illegal action. You are already in " + city_to_string.at(city));
        }
        if (!Board::is_connected(my_city, city))
        {
            throw invalid_argument("Illegal action. " + city_to_string.at(my_city) + " and " + city_to_string.at(city) + " are not connected.");
        }
        my_city = city;
        arrived();
        return *this;
    }

    Player &Player::fly_direct(City city)
    {
        if (my_city == city)
        {
            throw invalid_argument("Illegal action. You are already in " + city_to_string.at(city));
        }
        if (cards.find(city) == cards.end())
        {
            throw invalid_argument("Illegal action. You do not have the card of " + city_to_string.at(city));
        }
        cards.erase(city);
        my_city = city;
        arrived();
        return *this;
    }

    Player &Player::fly_charter(City city)
    {
        if (my_city == city)
        {
            throw invalid_argument("Illegal action. You are already in " + city_to_string.at(city));
        }
        if (cards.find(my_city) == cards.end())
        {
            throw invalid_argument("Illegal action. You do not have the card of " + city_to_string.at(my_city));
        }
        cards.erase(my_city);
        my_city = city;
        arrived();
        return *this;
    }

    Player &Player::fly_shuttle(City city)
    {
        if (my_city == city)
        {
            throw invalid_argument("Illegal action. You are already in " + city_to_string.at(city));
        }
        if (!my_board.is_built(my_city))
        {
            throw invalid_argument("Illegal action. There is no research station in the city " + city_to_string.at(my_city));
        }
        if (!my_board.is_built(city))
        {
            throw invalid_argument("Illegal action. There is no research station in the city " + city_to_string.at(city));
        }
        my_city = city;
        arrived();
        return *this;
    }

    Player &Player::build()
    {
        if (cards.find(my_city) == cards.end())
        {
            throw invalid_argument("Illegal action. You cannot build a research station because you do not have the card of " + city_to_string.at(my_city));
        }
        if (!my_board.is_built(my_city))
        {
            my_board.build_research_station(my_city);
            cards.erase(my_city);
        }
        return *this;
    }

    Player &Player::discover_cure(Color color)
    {
        if (!my_board.is_built(my_city))
        {
            throw invalid_argument("Illegal action. There is no research station in the city " + city_to_string.at(my_city));
        }
        if (!my_board.is_cure_discovered(my_city))
        {
            int count = 0;
            for (const auto &card : cards)
            {
                if (Board::get_color_of_city(card) == color)
                {
                    count++;
                }
            }
            if (count < cards_to_discard)
            {
                throw invalid_argument("Illegal action. You have only " + to_string(count) + " cards in color " + color_to_string.at(color));
            }
            count = 1;
            for (auto it = cards.begin(); it != cards.end(); count++)
            {
                if (count == cards_to_discard)
                {
                    break;
                }
                if (Board::get_color_of_city(*it) == color)
                {
                    it = cards.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            my_board.mark_discover(color);
        }
        return *this;
    }

    Player &Player::treat(City city)
    {
        if (my_city != city)
        {
            throw invalid_argument("Illegal action. you cannot treat a city you are not in");
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

    string Player::role()
    {
        return "";
    }

    Player &Player::take_card(City city)
    {
        cards.insert(city);
        return *this;
    }

    Player &Player::remove_cards()
    {
        cards.clear();
        return *this;
    }
}