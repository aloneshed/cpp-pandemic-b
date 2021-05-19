#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int init_cards;

    public:
        using Player::Player;

        ~Scientist() {}

        Scientist(Board &board, City city, int num_of_cards) : Player(board, city), init_cards(num_of_cards) {}

        std::string role()
        {
            return "Scientist";
        }

        Player &discover_cure(Color color);
    };
}