#include "FieldDoctor.hpp"

namespace pandemic {
    
    FieldDoctor::FieldDoctor(Board& board, City city) : Player(board, city) {}

    Player& FieldDoctor::treat(City city) 
    {
        if ((brdd.graph[location].count(city) < 1 && city != location) || brdd.maps[city].second == 0) 
        {
            throw exception();
        }
        if (brdd.cures[brdd.maps[city].first]) 
        {
            brdd[city] = 0;
            return *this;
        }
        brdd[city]--;
        return *this;
    }

    string FieldDoctor::role() 
    {
        return "FieldDoctor";
    }
}