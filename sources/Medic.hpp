#include "Player.hpp"
#include "City.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    public:
        using Player::Player;

        ~Medic() {}

        std::string role() override
        {
            return "Medic";
        }

        Player &treat(City city) override;

        void arrived() override;
    };
}