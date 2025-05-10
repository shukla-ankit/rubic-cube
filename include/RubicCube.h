#ifndef RUBIC_CUBE
#define RUBIC_CUBE

#include <vector>
#include "RubicCubeFace.h"
using namespace std;

class RubicCube{
        int nSize = 3; // DEFAULT_SIZE
        const short nFaces = 6;

        void init();

    public:
        
        vector<RubicCubeFace> faces;

        RubicCube();
        RubicCube(int size);
        void rotate_left(int row);
        void rotate_right(int row);
        void rotate_up(int col);
        void rotate_down(int col);

        void show();
};

#endif
