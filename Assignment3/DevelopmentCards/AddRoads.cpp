#include "AddRoads.hpp"
#include "../Player.hpp"

using namespace std;
class Player;                                                  // Forward declaration

AddRoads::AddRoads(const string &type) : Cards("Add Roads") {} // Constructor

void AddRoads::useAddRoads(Player &player)
{
    cout << "Adding the first road..." << endl;
    player.addRoad();
    cout << "Adding the second road..." << endl;
    player.addRoad();
    cout << "You have used an Add Roads card!" << endl;
}