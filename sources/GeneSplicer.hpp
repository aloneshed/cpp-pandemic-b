#include "Player.hpp"


namespace pandemic
{
    class GeneSplicer : public Player
    {
    public:
        using Player::Player;

        ~GeneSplicer() {}

        std::string role() override
        {
            return "GeneSplicer";
        }

        Player &discover_cure(Color color) override;
    };
}