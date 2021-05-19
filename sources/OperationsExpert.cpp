#include "OperationsExpert.hpp"

namespace pandemic
{
    Player &OperationsExpert::build()
    {
        my_board.build_research_station(my_city);
        return *this;
    }
}