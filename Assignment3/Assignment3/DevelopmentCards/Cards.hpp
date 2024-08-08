#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * @brief Class that represents the development cards
 * The other card will inherit from this class
 * This will be an abstract class
 */

class Cards
{
    string type; // Type of the card (Knight, VictoryPoint, RoadBuilding, YearOfPlenty, Monopoly)
    bool turn = false; // so the card can be used only in the next turn
public:
    // Ctor
    Cards();
    Cards(const string &type);
    virtual ~Cards(); // distructor

    string getType() const;
    bool getTurn() const;
    void setTurn(bool turn); // the list of the cards, every end of the turn, the card will be set to true
    virtual void print() const = 0; // Pure virtual function

};