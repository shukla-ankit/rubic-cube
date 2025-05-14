#ifndef RUBIC_CUBE
#define RUBIC_CUBE

#include <vector>
#include <string>
#include "RubicCubeFace.h"
using namespace std;

class RubicCube{
    int nSize = 3; // DEFAULT_SIZE
    const short nFaces = 6;
    vector<RubicCubeFace> faces;

    void init();
    void viewUp();
    void viewDown();
    void viewFaceRow(int faceIdx, int row, string indent = "");
public:    

    RubicCube();
    RubicCube(int size);

    void rotate_left(int row);
    void rotate_right(int row);
    void rotate_up(int col);
    void rotate_down(int col);
    void rotate_cw(int col);
    void rotate_ccw(int col);

    void print();
    void view();
};

#endif
