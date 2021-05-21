#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <string>
#include <set>
using std::string;
using std::set;

namespace pandemic {
    class Player {
        public:
            City location; //העיר בה נמצא
            Board& brdd; //מצביע ללוח, חייב להיות REF אחרת לא יתאפשר לשנות
            map <City, bool> cards; //הקלפים של כל שחקן, לכל עיר או שיש קלף או שלא
            Player& take_card(City city); //לקיחת קלף, עובר לפי המבנה הנ"ל

            Player(Board& brd, City city); //בנאי
            
            //כלל הפונקציות הוירטואליות יעברו דריסה לאחר מכן
            //פונקציות הטיסה
            virtual Player& fly_direct(City city);
            virtual Player& fly_charter(City city);
            virtual Player& fly_shuttle(City city);

            virtual Player& build(); //בונה על הלוח
            virtual Player& drive(City city); //נסיעה מעיר לעיר בהתאם לגרף הקשרים שעל הלוח
            virtual Player& treat(City city);
            virtual Player& discover_cure(Color color);
            virtual string role();
            //נועד לבדיקות
            Player& remove_cards();
    };
}