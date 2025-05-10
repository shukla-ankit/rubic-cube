#include "RubicCube.h"
#include <iostream>
#include <iomanip>
using namespace std;

RubicCube::RubicCube() {
    init();
}

RubicCube::RubicCube(int size){
    nSize = size;
    init();
}

void RubicCube::init() {
    cout << "Rubic Cube : Created! (size = " << nSize << " )" << endl;

    faces.push_back(RubicCubeFace(nSize, COLOR::WHITE));
    faces.push_back(RubicCubeFace(nSize, COLOR::BLUE));
    faces.push_back(RubicCubeFace(nSize, COLOR::YELLOW));
    faces.push_back(RubicCubeFace(nSize, COLOR::GREEN));
    faces.push_back(RubicCubeFace(nSize, COLOR::ORANGE));
    faces.push_back(RubicCubeFace(nSize, COLOR::RED));
}

void RubicCube::show(){
    cout << "\nRubic Cube : Show Rubic Cube!" << endl;
    cout << "       -----" << endl;

    cout << "       Top" << endl;
    cout << "       -----" << endl;
    faces[4].show();
    cout << "---------------------------" << endl;

    cout << "Left  |Front |Right |Back " << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i < nSize; i++)
    {
        for (int k = 3; k < 7; k++)
        {
            for (int j = 0; j < nSize; j++)
            {
                switch (faces[k % 4].cells[i][j]) {
                case COLOR::BLUE:
                    cout << "B";
                    break;
                case COLOR::GREEN:
                    cout << "G";
                    break;
                case COLOR::ORANGE:
                    cout << "O";
                    break;
                case COLOR::RED:
                    cout << "R";
                    break;
                case COLOR::WHITE:
                    cout << "W";
                    break;
                case COLOR::YELLOW:
                    cout << "Y";
                    break;
                }
                cout <<  ",";
            }
            cout << "|";
        }
        cout << "\n";
    }

    cout << "       -----" << endl;
    cout << "       Bottom" << endl;
    cout << "       -----" << endl;
    faces[5].show();
    cout << "       -----" << endl;

    cout << "\n\n" << endl;
}


void rotate_left(int row);
void rotate_right(int row);
void rotate_up(int col);
void rotate_down(int col);


void RubicCube::rotate_left(int row){
    cout << "Rubic Cube : Rotate Left" << row << "!" << endl;

    if (row == 0 || row == nSize - 1) {

    }
    vector<COLOR> temp(faces[0].cells[row]);
    int i = 0;
    while(++i < 4)
        faces[i - 1].cells[row] = faces[i].cells[row];
    faces[i - 1].cells[row] = temp;
}

void RubicCube::rotate_right(int row) {
    cout << "Rubic Cube : Rotate Right" << row << "!" << endl;

    if (row == 0 || row == nSize - 1) {

    }
    vector<COLOR> temp(faces[3].cells[row]);
    int i = 0;
    while (i++ < 4)
        faces[i].cells[row] = faces[i+1].cells[row];
    faces[i].cells[row] = temp;
}


void RubicCube::rotate_up(int col){
    cout << "Rubic Cube : Rotate Up" << col << "!" << endl;
}

void RubicCube::rotate_down(int col) {
    cout << "Rubic Cube : Rotate Down" << col << "!" << endl;
}
