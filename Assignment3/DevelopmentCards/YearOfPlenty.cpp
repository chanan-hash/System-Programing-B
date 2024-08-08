#include "YearOfPlenty.hpp"
#include "../Player.hpp"

using namespace std;

YearOfPlenty::YearOfPlenty(const string &type) : Cards("Year of Plenty") {}

void YearOfPlenty::useYearOfPlenty(Player &player, string resource1, string resource2)
{
    player.getResource(resource1)++;
    player.getResource(resource2)++;
    cout << "You have used a Year of Plenty card!" << endl;
}