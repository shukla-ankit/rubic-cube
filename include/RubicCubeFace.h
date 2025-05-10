#ifndef RUBIC_CUBE_FACE
#define RUBIC_CUBE_FACE

#include <vector>
using namespace std;

enum COLOR { WHITE, BLUE, YELLOW, GREEN, ORANGE, RED};

#define RubicCubeCell COLOR

class RubicCubeFace{
    public:
        vector<vector<RubicCubeCell>> cells;
        RubicCubeFace(int size, COLOR color);
        void show();
};

#endif
