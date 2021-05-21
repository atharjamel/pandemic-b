#include "GeneSplicer.hpp"

namespace pandemic {

    GeneSplicer::GeneSplicer(Board& board, City city) : Player(board, city) {}

    Player& GeneSplicer::discover_cure(Color color) 
    {
        if (!brdd.stations[location]) 
        {
            throw exception();
        }
        const int const_five = 5;
        if (brdd.cures[color]) 
        {
            return *this;
        }
        int count = 0;
        for (auto &cards : cards) 
        {
            if (cards.second) 
            {
                count++;
            }
        }
        if (count < const_five) 
        {
            throw exception();
        }
        count = 0;
        for (auto &cards : cards) 
        {
            if (cards.second) 
            {
                count++;
                cards.second = false;
            }
            if (count == const_five) 
            {
                break;
            }
        }
        brdd.cures[color] = true;
        return *this;
    }

    string GeneSplicer::role() 
    {
        return "GeneSplicer";
    }
}