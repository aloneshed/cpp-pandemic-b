#include "Player.hpp"


namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        using Player::Player;

        ~FieldDoctor() {}

         std::string role() override
        {
            return "FieldDoctor";
        }

        Player &treat(City city) override;
    };
}