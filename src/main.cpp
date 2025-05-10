#include <iostream>
#include "RubicCube.h"
using namespace std;

int main(int argc, char** argv){
    //if(argv[1] == "d")
        
    RubicCube r;
    r.show();
    r.rotate_left(0);
    r.show();
    return 0;
}
