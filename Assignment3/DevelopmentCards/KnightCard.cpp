#include "KnightCard.hpp"
#include "../Player.hpp"

using namespace std;

KnightCard::KnightCard(const string &type) : Cards("Kinght") {}

void KnightCard::useKinghtCard(Player &player)
{
    player.activateKnightMove(); // need to be implemented
    // The player will move the robber and steal a resource from another player
    // Will activate a Knight move function
}