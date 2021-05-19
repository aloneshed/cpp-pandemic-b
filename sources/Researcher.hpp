#include "Player.hpp"


namespace pandemic
{
    class Researcher : public Player
    {
    public:
        using Player::Player;

        ~Researcher() {}

        std::string role() override
        {
            return "Researcher";
        }

        Player &discover_cure(Color color) override;
    };
}