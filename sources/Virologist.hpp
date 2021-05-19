#include "Player.hpp"

namespace pandemic
{
    class Virologist : public Player
    {
    public:
        using Player::Player;

        ~Virologist() {}

        std::string role() override
        {
            return "Virologist";
        }

        Player &treat(City city) override;
    };
}