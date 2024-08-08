#pragma once

#include "Cards.hpp"
#include "../Player.hpp"

using namespace std;

class Player; // Forward declaration
class YearOfPlenty : public Cards
{
public:
    YearOfPlenty(const string &type);
    void useYearOfPlenty(Player &player, string resource1, string resource2);
};