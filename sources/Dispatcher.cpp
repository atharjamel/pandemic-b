#include "Dispatcher.hpp"

namespace pandemic {
    Dispatcher::Dispatcher(Board& board, City city) : Player(board, city) {}

    Player& Dispatcher::fly_direct(City city) 
    {
        if (location == city) 
        {
            throw exception();
        }
        if (brdd.stations[location]) {
            location = city;
            return *this;
        }
        if (cards[city]) {
            cards[city] = false;
            location = city;
            return *this;
        }
        throw exception();
    }

    string Dispatcher::role() {
        return "Dispatcher";
    }
}