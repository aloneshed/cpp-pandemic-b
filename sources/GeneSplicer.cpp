#include "GeneSplicer.hpp"
using namespace std;
const int cards_to_discard = 5;

namespace pandemic
{
    Player &GeneSplicer::discover_cure(Color color)
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
                count++;
            }
            if (count < cards_to_discard)
            {
                throw invalid_argument("Illegal action. You have only " + to_string(count) + " cards");
            }
            count = 1;
            for (auto it = cards.begin(); it != cards.end(); count++)
            {
                if (count == cards_to_discard)
                {
                    break;
                }
                it = cards.erase(it);
            }
            my_board.mark_discover(color);
        }
        return *this;
    }
}