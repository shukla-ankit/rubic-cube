#include <iostream>
#include "RubicCube.h"
using namespace std;

int main(int argc, char** argv){
    //if(argv[1] == "d")
        
    RubicCube r(4);
    r.print();
    r.view();
    r.rotate_left(0);
    r.view();
    r.rotate_right(0);
    r.view();
    r.rotate_up(2);
    r.view();
    r.rotate_down(2);
    r.view();
    r.rotate_cw(1);
    r.view();
    r.rotate_ccw(1);
    r.view();
    return 0;
}
