#include <vector>
#include <string>
using namespace std;

namespace ariel
{

    enum class LandType
    {
        FOREST,       // yields wood
        HILLS,        // yields bricks
        PASTURE,      // yields wool
        AGRICULTURAL, // yields oats
        MOUNTAINS,    // yields iron
        DESERT        // yields nothing
    };

    struct LandPlot
    {
        LandType type;
        int number;
    };

    class Board
    {
        vector<vector<LandPlot>> board;

    public:
        Board();
        LandPlot getPlot(int x, int y);
    };
}

/**
 * #include <string>
#include <vector>
#include <map>

using namespace std;

class Board {
private:
    map<string, map<int, string>> boardState; // Map to hold the state of the board

public:
    Board();
    void placeSettlement(string place, int placeNum, string playerName);
    void placeRoad(string place, int placeNum, string playerName);
    string getOwner(string place, int placeNum);
};




cpp

#include "Board.hpp"

Board::Board() {
    // Initialize the board with empty strings
    for (string place : {"Forest", "Hills", "Agricultural Land", "Desert", "Mountains", "Pasture Land"}) {
        for (int i = 1; i <= 12; i++) {
            boardState[place][i] = "";
        }
    }
}

void Board::placeSettlement(string place, int placeNum, string playerName) {
    // Place a settlement on the board
    boardState[place][placeNum] = playerName;
}

void Board::placeRoad(string place, int placeNum, string playerName) {
    // Place a road on the board
    boardState[place][placeNum] = playerName;
}

string Board::getOwner(string place, int placeNum) {
    // Get the owner of a place on the board
    return boardState[place][placeNum];
}



#include "Board.hpp"

// ...

void Board::printBoard() {
    for (auto& place : boardState) {
        cout << place.first << ": ";
        for (auto& num : place.second) {
            cout << num.first << "(" << num.second << ") ";
        }
        cout << endl;
    }
}


vector<int> placeNum= {2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12};
shuffle (placeNum);
 for in places assigning number to it place

*/