#include "Medic.hpp"

namespace pandemic {
    Medic::Medic(Board& board, City city) : Player(board, city) {
    }

    Player& Medic::treat(City city) {
        if (city != location) {
            throw exception();
        }
        if (brdd.maps[city].second == 0) {
            throw exception();
        }
        if (brdd.cures[brdd.maps[city].first]) {
            brdd[city] = 0;
            return *this;
        }
        brdd[city] = 0;
        return *this;

    }

    Player& Medic::drive(City city) 
    {
        Player::drive(city);
        if (brdd.cures[brdd.maps[location].first]) 
        {
            brdd[location] = 0;
        }
        return *this;
    }

    Player& Medic::fly_direct(City city) 
    {
        Player::fly_direct(city);
        if (brdd.cures[brdd.maps[location].first]) 
        {
            brdd[location] = 0;
        }
        return *this;
    }

    Player& Medic::fly_charter(City city) 
    {
        Player::fly_charter(city);
        if (brdd.cures[brdd.maps[location].first]) 
        {
            brdd[location] = 0;
        }
        return *this; 
    }

    Player& Medic::fly_shuttle(City city) 
    {
        Player::fly_shuttle(city);
        if (brdd.cures[brdd.maps[location].first]) 
        {
            brdd[location] = 0;
        }
        return *this; 
    }

    string Medic::role() 
    {
        return "Medic";
    }
}