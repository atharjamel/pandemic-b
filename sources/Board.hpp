#pragma once
#include <map>
#include <set>
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic 
{
    class Board 
    {
        public:
            Board();
            typedef pair <Color, int> cc; //מגדיר זוג סדור של צבא ומספר קוביות מחלה שיוטבע בכל עיר
            map <City, cc> maps; //סטאטוס ערים בהתאם לזוג הנל

            map <City, bool> stations; //תחנות מחקר יש או אין בערך בוליאני
            map <Color, bool> cures; //תרופות כנ"ל

            map <City, set<City>> graph;//מפת הקשרים

            int& operator[] (City city);
            bool is_clean();
            friend ostream& operator<< (ostream& stream, const Board& board);
            
            //פונקציות לבדיקה
            void remove_cures();
            void remove_stations();
    };
}