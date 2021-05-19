#include "Scientist.hpp"
using namespace std;

namespace pandemic
{
    Player &Scientist::discover_cure(Color color)
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
            if (count < init_cards)
            {
                throw invalid_argument("Illegal action. You have only " + to_string(count) + " cards in color " + color_to_string.at(color));
            }
            count = 1;
            for (auto it = cards.begin(); it != cards.end(); count++)
            {
                if (count == init_cards)
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
}