#include "Player.hpp"

namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        using Player::Player;

        ~OperationsExpert() {}

        std::string role() override
        {
            return "OperationsExpert";
        }
        
        Player &build() override;
    };
}