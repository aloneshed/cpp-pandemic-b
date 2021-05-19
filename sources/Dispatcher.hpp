#include "Player.hpp"

namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        using Player::Player;

        ~Dispatcher() {}

        std::string role() override
        {
            return "Dispatcher";
        }
        
        Player &fly_direct(City city) override;
    };
}