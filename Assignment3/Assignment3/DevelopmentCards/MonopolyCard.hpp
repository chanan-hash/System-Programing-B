#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Cards.hpp"
#include "../Player.hpp"

using namespace std;

class Player; // Forward declaration

// This card you ask from each player a resource of your choice, and if they have it, they must give it to you

class MonopolyCard : public Cards{ // Inheritance
    MonopolyCard(const string &type);
    void useMonopolyCard(Player &owner, string resource, vector<Player> &players); // The player will ask for a resource of their choice from each player, and if they have it, they must give it to you
};