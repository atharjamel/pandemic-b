#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic 
{
    class Scientist : public Player {
        public:
            int cardss;
            Scientist(Board& board, City city, int num);
            virtual Player& discover_cure(Color color) override;
            virtual string role() override;
    };
}