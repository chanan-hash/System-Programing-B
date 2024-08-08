#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include "Board.hpp"

using namespace std;
namespace ariel
{
    class Player
    {
    private:
        string name;
        int winPoints;
        int roads;
        int settlements;
        int cities;
        map<string, int> resources; // Map to hold resources and their amounts
        // resources as a int? cheeper to compare and add.
        // cards ?, resources ? development cards ? matrix of cards to count the amount of each card

    public:
        Player(string name);// : name(name), winPoints(0), roads(15), settlements(5), cities(4) {} // initilization list
        void placeSettelemnt(vector<string> places, vector<int> placesNum, Board &board) {}
        void placeRoad(vector<string> places, vector<int> placesNum, Board &board) {}
        void changeToCity(vector<string> places, vector<int> placesNum, Board &board) {}
        void rollDice() {}
        void endTurn() {}
        void trade(Player &other, string give, string take, int giveAmount, int takeAmount) {} // can open window if want to trade with other player "yes" trade, "no". if yes need to check if he has the resources if not throw exception
        void buyDevelopmentCard() {}                                                           // will check if he can by if not will print not, if yes will buy and add it to his development cards
        void printPoints() {}
        string getName() { return this->name; }
        int getWinPoints() { return this->winPoints; }
        void addResource(string resource, int amount) {}

    };

}
