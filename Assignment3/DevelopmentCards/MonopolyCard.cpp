#include "MonopolyCard.hpp"
#include "../Player.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player; // Forward declaration

MonopolyCard::MonopolyCard(const string &type) : Cards("Monopoly") {}

void MonopolyCard::useMonopolyCard(Player &owner, string resource, vector<Player> &players)
{
    cout << "You have used a Monopoly card!" << endl;
    // The player will ask for a resource of their choice from each player, and if they have it, they must give it to you
    int amout = 0;
    for (Player& player : players)
    {
        if (player.getResource(resource) == 0)
        {
            cout << "Player " << player.getName() << " does not have any " << resource << " to give." << endl;
            continue;
        }
        player.getResource(resource)--;
        amout++;
    }
    owner.getResource(resource) += amout;
};