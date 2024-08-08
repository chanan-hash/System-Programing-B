#include "Cards.hpp"

using namespace std;

// Ctor with initialization list, faster initialization
Cards::Cards() : type("") {}

Cards::Cards(const string &type) : type(type) {}

// Dtor
Cards::~Cards() {}

string Cards::getType() const
{
    return this->type;
}

bool Cards::getTurn() const
{
    return this->turn;
}

// The player will have a list of development cards, and every end of the turn, the card will be set to true
void Cards::setTurn(bool turn)
{
    this->turn = turn;
}
