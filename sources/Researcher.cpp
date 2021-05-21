#include "Researcher.hpp"

namespace pandemic {
    
    Researcher::Researcher(Board& board, City city) : Player(board, city) {
    }

    Player& Researcher::discover_cure(Color color) {
        const int _cards_needed = 5;
        if (brdd.cures[color]) {
            return *this;
        }
        int count = 0;
        for (auto &cards : cards) {
            if (cards.second && brdd.maps[cards.first].first == color) {
                count++;
            }
        }
        if (count < _cards_needed) {
            throw exception();
        }
        count = 0;
        for (auto &cards : cards) {
            if (brdd.maps[cards.first].first == color) {
                count++;
                cards.second = false;
            }
            if (count == _cards_needed) {
                brdd.cures[color] = true;
                return *this;
            }
        }
        brdd.cures[color] = true;
        return *this;
    }

    string Researcher::role() {
        return "Researcher";
    }
}