#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;
namespace ariel
{
    class player
    {
    private:
        string name;
        int winPoints;
        // cards ?

    public:
    };

}

/**
 * #include <string>
#include <vector>
#include <map>

using namespace std;

class Player {
    string name;
    int points;
    map<string, int> resources;

public:
    Player(string name) : name(name), points(0) {}
    void placeSettelemnt(vector<string> places, vector<int> placesNum, Board& board) {}
    void placeRoad(vector<string> places, vector<int> placesNum, Board& board) {}
    void rollDice() {}
    void endTurn() {}
    void trade(Player& other, string give, string take, int giveAmount, int takeAmount) {}
    void buyDevelopmentCard() {}
    void printPoints() {}
};

class Board {
    map<string, map<int, vector<Player*>>> board;

public:
    Board() {}
};

class Catan {
    Player p1, p2, p3;
    Board board;

public:
    Catan(Player p1, Player p2, Player p3) : p1(p1), p2(p2), p3(p3) {}
    void ChooseStartingPlayer() {}
    Board getBoard() { return board; }
    void printWinner() {}
};
*/