#include "VictoryPointCard.hpp"
#include "../Player.hpp"

using namespace std;

VictoryPoint::VictoryPoint(const string &type) : Cards("Victory Point") {}

void VictoryPoint::useVictoryPoint(Player &player)
{
    player.addVictoryPoint();
    cout << "You have used a Victory Point card!" << endl;
}