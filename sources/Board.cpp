
#include "Board.hpp"

/**
 * @brief הלוח הראשי, כמה שחקנים יכולים להיות על אותו לוח ולכן 
 * נעביר מצביע לאותם השחקנים ששינוי ששחקן אחד עושה יהיה רלוונטי גם לשחקנים האחרים
 * 
 */
namespace pandemic {
    Board::Board() 
    {
        //מאפס עמדות ותרופות
        for (auto &st : stations) 
        {
            st.second=false;
        }
        for (auto &cure : cures) 
        {
            cure.second=false;
        }
        //מגדיר קוביות וערים
        maps[Algiers]=make_pair(Black, 0);
        maps[Atlanta]=make_pair(Blue, 0);
        maps[Baghdad]=make_pair(Black, 0);
        maps[Beijing]=make_pair(Red, 0);
        maps[Bangkok]=make_pair(Red, 0);
        maps[Bogota]=make_pair(Yellow, 0);
        maps[BuenosAires]=make_pair(Yellow, 0);
        maps[Cairo]=make_pair(Black, 0);
        maps[Karachi]=make_pair(Black, 0);
        maps[Johannesburg]=make_pair(Yellow, 0);
        maps[Jakarta]=make_pair(Red, 0);
        maps[Istanbul]=make_pair(Black, 0);
        maps[HongKong]=make_pair(Red, 0);
        maps[HoChiMinhCity]=make_pair(Red, 0);
        maps[Essen]=make_pair(Blue, 0);
        maps[Delhi]=make_pair(Black, 0);
        maps[Chicago]=make_pair(Blue, 0);
        maps[Chennai]=make_pair(Black, 0);
        maps[MexicoCity]=make_pair(Yellow, 0);
        maps[Manila]=make_pair(Red, 0);
        maps[Madrid]=make_pair(Blue, 0);
        maps[LosAngeles]=make_pair(Yellow, 0);
        maps[London]=make_pair(Blue, 0);
        maps[Lima]=make_pair(Yellow, 0);
        maps[Lagos]=make_pair(Yellow, 0);
        maps[Kolkata]=make_pair(Black, 0);
        maps[Kinshasa]=make_pair(Yellow, 0);
        maps[Khartoum]=make_pair(Yellow, 0);
        maps[Miami]=make_pair(Yellow, 0);
        maps[Milan]=make_pair(Blue, 0);
        maps[Montreal]=make_pair(Blue, 0);
        maps[Moscow]=make_pair(Black, 0);
        maps[Mumbai]=make_pair(Black, 0);
        maps[NewYork]=make_pair(Blue, 0);
        maps[Osaka]=make_pair(Red, 0);
        maps[Paris]=make_pair(Blue, 0);
        maps[Riyadh]=make_pair(Black, 0);
        maps[SanFrancisco]=make_pair(Blue, 0);
        maps[Santiago]=make_pair(Yellow, 0);
        maps[SaoPaulo]=make_pair(Yellow, 0);
        maps[Seoul]=make_pair(Red, 0);
        maps[Shanghai]=make_pair(Red, 0);
        maps[StPetersburg]=make_pair(Blue, 0);
        maps[Sydney]=make_pair(Red, 0);
        maps[Taipei]=make_pair(Red, 0);
        maps[Tehran]=make_pair(Black, 0);
        maps[Tokyo]=make_pair(Red, 0);
        maps[Washington]=make_pair(Blue, 0);

        //מאתחל את גרף הקשרים שלנו
        graph[Baghdad]={Tehran, Istanbul, Cairo, Riyadh, Karachi};
        graph[Algiers]={Madrid, Paris, Istanbul, Cairo};
        graph[Bangkok]={Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong};
        graph[Atlanta]={Chicago, Miami, Washington};
        graph[Bogota]={MexicoCity, Lima, Miami, SaoPaulo, BuenosAires};
        graph[Beijing]={Shanghai, Seoul};
        graph[BuenosAires]={Bogota, SaoPaulo};
        graph[Cairo]={Algiers, Istanbul, Baghdad, Khartoum, Riyadh};
        graph[Karachi]={Tehran, Baghdad, Riyadh, Mumbai, Delhi};
        graph[Johannesburg]={Kinshasa, Khartoum};
        graph[Jakarta]={Chennai, Bangkok, HoChiMinhCity, Sydney};
        graph[Istanbul]={Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow};
        graph[HongKong]={Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei};
        graph[HoChiMinhCity]={Jakarta, Bangkok, HongKong, Manila};
        graph[Essen]={London, Paris, Milan, StPetersburg};
        graph[Delhi]={Tehran, Karachi, Mumbai, Chennai, Kolkata};
        graph[Chicago]={SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal};
        graph[Chennai]={Mumbai, Delhi, Kolkata, Bangkok, Jakarta};
        graph[MexicoCity]={LosAngeles, Chicago, Miami, Lima, Bogota};
        graph[Manila]={Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong};
        graph[Madrid]={London, NewYork, Paris, SaoPaulo, Algiers};
        graph[LosAngeles]={SanFrancisco, Chicago, MexicoCity, Sydney};
        graph[London]={NewYork, Madrid, Essen, Paris};
        graph[Lima]={MexicoCity, Bogota, Santiago};
        graph[Kolkata]={Delhi, Chennai, Bangkok, HongKong};
        graph[Washington]={Atlanta, NewYork, Montreal, Miami};
        graph[Lagos]={SaoPaulo, Khartoum, Kinshasa};
        graph[Kinshasa]={Lagos, Khartoum, Johannesburg};
        graph[Khartoum]={Cairo, Lagos, Kinshasa, Johannesburg};
        graph[Miami]={Atlanta, MexicoCity, Washington, Bogota};
        graph[Milan]={Essen, Paris, Istanbul};
        graph[Montreal]={Chicago, Washington, NewYork};
        graph[Moscow]={StPetersburg, Istanbul, Tehran};
        graph[Mumbai]={Karachi, Delhi, Chennai};
        graph[NewYork]={Montreal, Washington, London, Madrid};
        graph[Paris]={Algiers, Essen, Madrid, Milan, London};
        graph[Osaka]={Taipei, Tokyo};
        graph[Riyadh]={Baghdad, Cairo, Karachi};
        graph[SanFrancisco]={LosAngeles, Chicago, Tokyo, Manila};
        graph[SaoPaulo]={Bogota, BuenosAires, Lagos, Madrid};
        graph[Santiago]={Lima};
        graph[Seoul]={Beijing, Shanghai, Tokyo};
        graph[Shanghai]={Beijing, HongKong, Taipei, Seoul, Tokyo};
        graph[StPetersburg]={Essen, Istanbul, Moscow};
        graph[Sydney]={Jakarta, Manila, LosAngeles};
        graph[Taipei]={Shanghai, HongKong, Osaka, Manila};
        graph[Tehran]={Baghdad, Moscow, Karachi, Delhi};
        graph[Tokyo]={Seoul, Shanghai, Osaka, SanFrancisco};
    }

//ניגש לערך קוביות
    int& Board::operator[] (City city) 
    {
        return maps[city].second;
    }

//מדפיס
    ostream& operator<< (ostream& stream, const Board& Board) 
    {
        stream << "Board" << endl;
        return stream;
    }

//בודק שנקי
    bool Board::is_clean() 
    {
        for (auto const &city : maps) 
        {
            if (city.second.second > 0) 
            {
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures() 
    {
        for (auto &cure : cures) 
        {
            cure.second=false;
        }
    }

    void Board::remove_stations() 
    {
        for (auto &station : stations) 
        {
            station.second=false;
        } 
    }
}