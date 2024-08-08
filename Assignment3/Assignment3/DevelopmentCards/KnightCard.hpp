#pragma once
#include "Cards.hpp"
#include "../Player.hpp"

using namespace std;

class Player; // Forward declaration

class KnightCard : public Cards{ // Inheritance
    KnightCard(const string &type);
    void useKinghtCard(Player &player); // The player will move the robber and steal a resource from another player, will activate a Knight move function
};