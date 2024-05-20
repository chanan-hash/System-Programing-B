#include "player.hpp"

using namespace ariel;
using namespace std;

Player::Player(string name) : name(name), winPoints(0) {}

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


// random dice roll between 2-12
void Player::rollDice()
{
    int dice = rand() % 11 + 2;
    cout << "Dice roll: " << dice << endl;
}

void Player::printPoints()
{
    cout << "Player " << name << " has " << winPoints << " points." << endl;
}

void Player::endTurn() {
    cout << "Player " << name << " ends his turn." << endl; 
}