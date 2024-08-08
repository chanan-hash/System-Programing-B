#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>

using namespace std;
namespace ariel
{
    class Catan
    {
        Board board;
        Player p1;
        Player p2;
        Player p3;

    public:
        Catan(Player p1, Player p2, Player p3) : p1(p1.getName()), p2(p2.getName()), p3(p3.getName()) {}
        void ChooseStartingPlayer();
        Board getBoard();
        void printWinner();
    };
}
