#include "player.hpp"

using namespace ariel;
using namespace std;

Player::Player(string name) : name(name), winPoints(0), roads(15), settlements(5), cities(4)
{
    this->resources["wood"] = 0;
    this->resources["bricks"] = 0;
    this->resources["wool"] = 0;
    this->resources["oats"] = 0;
    this->resources["iron"] = 0;
}
// void Player::placeSettelemnt(vector<string> places, vector<int> placesNum, Board &board)
// {
//     for (int i = 0; i < places.size(); i++)
//     {
//         LandPlot plot = board.getPlot(placesNum[i], placesNum[i]);
//         if (plot.type == LandType::DESERT)
//         {
//             throw invalid_argument("Cannot place a settlement on a desert.");
//         }
//         if (plot.type == LandType::FOREST || plot.type == LandType::HILLS || plot.type == LandType::PASTURE || plot.type == LandType::AGRICULTURAL || plot.type == LandType::MOUNTAINS)
//         {
//             throw invalid_argument("Cannot place a settlement on a land that is already occupied.");
//         }
//         if (plot.type == LandType::DESERT)
//         {
//             throw invalid_argument("Cannot place a settlement on a desert.");
//         }
//         LandPlot newPlot;
//         newPlot.type = plot.type;
//         newPlot.number = plot.number;
//         board.setPlot(placesNum[i], placesNum[i], newPlot);
//     }
// }

// void Player::placeRoad(vector<string> places, vector<int> placesNum, Board &board)

void Player::addResource(string resource, int amount)
{
    this->resources[resource] += amount;
}

// random dice roll between 2-12
// need to add the resources to the player
void Player::rollDice()
{
    int dice = rand() % 11 + 2;
    cout << "Dice roll: " << dice << endl;
}

void Player::printPoints()
{
    cout << "Player " << name << " has " << winPoints << " points." << endl;
}

void Player::endTurn()
{
    cout << "Player " << name << " ends his turn." << endl;
}

void Player::trade(Player &other, string give, string take, int giveAmount, int takeAmount)
{
    string answer;
    cout << "Player " << this->name << " wants to trade with " << other.getName() << ". Do you want to trade? (yes/no)" << endl;
    cin >> answer;
    if (answer == "yes")
    {
        //     if (this->resources[give] < giveAmount) {
        //         throw invalid_argument("You don't have enough resources to trade.");
        //     }
        //     if (other.resources[take] < takeAmount) {
        //         throw invalid_argument("The other player doesn't have enough resources to trade.");
        //     }
        //     this->resources[give] -= giveAmount;
        //     this->resources[take] += takeAmount;
        //     other.resources[give] += giveAmount;
        //     other.resources[take] -= takeAmount;
    }


}