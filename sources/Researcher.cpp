#include "Researcher.hpp"
using namespace std;
const int cards_to_discard = 5;
namespace pandemic
{
    Player &Researcher::discover_cure(Color color)
    {
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
}