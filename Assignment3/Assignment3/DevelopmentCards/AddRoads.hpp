#pragma once
#include "Cards.hpp"
#include "../Player.hpp"

using namespace std;

class Player; // Forward declaration

class AddRoads : public Cards
{
public:
    AddRoads(const string &type);
    void useAddRoads(Player &player);
};
