#pragma once

#include "Cards.hpp"
#include "../Player.hpp"

using namespace std;

class Player; // Forward declaration

class VictoryPoint : public Cards
{
public:
    VictoryPoint(const string &type);
    void useVictoryPoint(Player &player);
};