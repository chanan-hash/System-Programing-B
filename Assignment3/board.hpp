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
        std::vector<std::vector<LandPlot>> board;

    public:
        Board();
        LandPlot getPlot(int x, int y);
    };
}