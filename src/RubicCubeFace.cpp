#include "RubicCubeFace.h"
#include <iostream>
#include <iomanip>
using namespace std;

RubicCubeFace::RubicCubeFace(int size, COLOR color){
    //cout << "\tRubic Cube Face : Created ( size = " << size << ")!" << endl;
    for(int row = 0; row < size; row++)
        cells.push_back(vector<COLOR>(size, color));
}

void RubicCubeFace::show(){
    const int space = 0;
    //cout << "\tRubic Cube Face : Show!" << endl;
    for (auto row : cells) {
        cout << "       ";
        for (auto cell : row) {
            switch (cell) {
                case COLOR::BLUE:
                    cout << setw(space) << "B";
                    break;
                case COLOR::GREEN:
                    cout << setw(space) << "G";
                    break;
                case COLOR::ORANGE:
                    cout << setw(space) << "O";
                    break;
                case COLOR::RED:
                    cout << setw(space) << "R";
                    break;
                case COLOR::WHITE:
                    cout << setw(space) << "W";
                    break;
                case COLOR::YELLOW:
                    cout << setw(space) << "Y";
                    break;
            }
            cout << ",";
        }
        cout << endl;
    }
}

