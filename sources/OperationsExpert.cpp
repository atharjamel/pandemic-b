#include "OperationsExpert.hpp"

namespace pandemic {

    OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city) {
    }

    Player& OperationsExpert::build() {
        if (brdd.stations[location]) {
            return *this;
        }
        brdd.stations[location] = true;
        return *this;
    }

    string OperationsExpert::role() {
        return "OperationsExpert";
    }
}