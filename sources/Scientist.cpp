#include "Scientist.hpp"

namespace pandemic 
{
    Scientist::Scientist(Board& board, City city, int num) : Player(board, city), cardss(num) {}

    Player& Scientist::discover_cure(Color color) 
    {
        if (!brdd.stations[location]) 
        {
            throw exception();
        }
        if (brdd.cures[color]) 
        {
            return *this;
        }
        int card_count = 0;
        for (auto &cards : cards) 
        {
            if (cards.second && brdd.maps[cards.first].first == color) 
            {
                card_count++;
            }
        }
        if (card_count < cardss) 
        {
            throw exception();
        }
        card_count = 0;
        for (auto &cards : cards) 
        {
            if (brdd.maps[cards.first].first == color) 
            {
                card_count++;
                cards.second = false;
            }
            if (card_count == cardss) 
            {
                break;
            }
        }
        brdd.cures[color] = true;
        return *this;
    }

    string Scientist::role() 
    {
        return "Scientist";
    }
}