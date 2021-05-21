#include "Virologist.hpp"

namespace pandemic 
{
    Virologist::Virologist(Board& board, City city) : Player(board, city) {}

    Player& Virologist::treat(City city) 
    {
        if (location == city) 
        {
            if (brdd.maps[location].second == 0) 
            {
                throw exception();
            }
            if (brdd.cures[brdd.maps[city].first]) 
            {
                brdd[city] = 0;
                return *this;
            }
            brdd[city]-=1;
            cards[city] = false;
            return *this;
        }
        if (brdd.maps[city].second == 0) 
        {
            throw exception();
        }
        if (brdd.cures[brdd.maps[city].first]) 
        {
            brdd[city] = 0;
            cards[city] = false;
            return *this;
        }
        if (!cards[city]) 
        {
            throw exception();
        }
        brdd[city]-=1;
        cards[city] = false;
        return *this;
    }

    string Virologist::role() {
        return "Virologist";
    }
}
