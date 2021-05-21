#include "Player.hpp"

/**
 * @brief האובייקט העיקרי שכולם יורשים ממנו, כל שאר השחקנים מקבלים תכונות מהשחקן הראשי,
 * השוני היחיד ביניהם הוא במימוש פונקציות ספציפיות בהתאם להגדרות המשחק ב README
 * 
 */
namespace pandemic 
{
    Player::Player(Board& brd, City city) : brdd(brd) 
    {
        location = city;
        for (auto &card : cards) {
            card.second = false;
        }
    }
    
    Player& Player::take_card(City city) 
    {
        if (!cards[city]) 
        {
            cards[city] = true;
        }
        return *this;
    }

    Player& Player::build() 
    {
        if (brdd.stations[location]) 
        {
            return *this;
        }
        if (cards[location]) 
        {
            cards[location] = false;
            brdd.stations[location] = true;
            return *this;
        }
        throw exception();
    }

    Player& Player::drive(City city) {
        if (location == city || brdd.graph[location].count(city) < 1) {
            throw exception();
        }
        location = city;
        return *this;
    }

    Player& Player::fly_direct(City city) {
        if (cards[city] && location != city) {
            cards[city] = false;
            location = city;
            return *this;
        }
        throw exception();
    }

    Player& Player::fly_charter(City city) {
        if (cards[location] && location != city) {
            cards[location] = false;
            location = city;
            return *this;
        }
        throw exception();
    }

    Player& Player::fly_shuttle(City city) {
        if (brdd.stations[location] && brdd.stations[city] && location != city) {
            location = city;
            return *this;
        }
        throw exception();
    }

    Player& Player::treat(City city) {
        if (city != location || brdd.maps[location].second == 0) 
        {
            throw exception();
        }
        if (brdd.cures[brdd.maps[location].first]) 
        {
            brdd[location] = 0;
            return *this;
        }
        brdd[location]--;
        return *this;
    }

    Player& Player::discover_cure(Color color) 
    {
        if (!brdd.stations[location]) 
        {
            throw exception();
        }
        const int constfive = 5;
        if (brdd.cures[color]) 
        {
            return *this;
        }
        int count = 0;
        for (auto &cards : cards) 
        {
            if (cards.second && brdd.maps[cards.first].first == color) 
            {
                count++;
            }
        }
        if (count < constfive) 
        {
            throw exception();
        }
        count = 0;
        for (auto &cards : cards) 
        {
            if (brdd.maps[cards.first].first == color) 
            {
                count++;
                cards.second = false;
            }
            if (count == constfive) 
            {
                brdd.cures[color] = true;
                return *this;
            }
        }
        brdd.cures[color] = true;
        return *this;
    }

    string Player::role() {
        return "Player";
    }

    Player& Player::remove_cards() 
    {
        for (auto &card : cards) 
        {
            card.second = false;
        }
        return *this;
    }
}