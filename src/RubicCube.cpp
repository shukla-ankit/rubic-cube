#include "RubicCube.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
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

void RubicCube::viewFaceRow(int faceIdx, int row, string indent) {
    cout << indent;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int j = 0; j < nSize; j++){
        switch (faces[faceIdx].cells[row][j]) {
        case COLOR::BLUE:
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
            break;
        case COLOR::GREEN:
            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
            break;
        case COLOR::ORANGE:
            SetConsoleTextAttribute(hConsole,  BACKGROUND_RED | BACKGROUND_GREEN);
            break;
        case COLOR::RED:
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
            break;
        case COLOR::WHITE:
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
            break;
        case COLOR::YELLOW:
            SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
            break;
        }
        cout << "  ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << " ";
    }
}

void RubicCube::viewUp() {
    string indent(3 * nSize, ' ');
    for (int i = 0; i < nSize; i++) {
        viewFaceRow(4, i, indent);
        cout << "\n" << endl;
    }
}

void RubicCube::viewDown() {
    string indent(3 * nSize, ' ');
    for (int i = 0; i < nSize; i++) {
        viewFaceRow(5, i, indent);
        cout << "\n" << endl;
    }
}

void RubicCube::view() {
    viewUp();
    for (int row = 0; row < nSize; row++) {
        for (int faceIdx : {3, 0, 1, 2}) {
            viewFaceRow(faceIdx, row);
        }
        cout << "\n" << endl;
    }
    viewDown();
}

void RubicCube::print(){
    string indent(2 * nSize, ' ');
    string underLine(2 * nSize, '-');
    cout << indent + underLine << endl;

    cout << indent + "Top" << endl;
    cout << indent + underLine << endl;
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

void RubicCube::rotate_left(int row){
    cout << "Row #" << row + 1 << " rotated left!\n" << endl;

    if (row == 0 || row == nSize - 1) {

    }
    vector<COLOR> temp(faces[0].cells[row]);
    int i = 0;
    while(++i < 4)
        faces[i - 1].cells[row] = faces[i].cells[row];
    faces[i - 1].cells[row] = temp;
}

void RubicCube::rotate_right(int row) {
    cout << "Row #" << row + 1 << " rotated right!\n" << endl;

    if (row == 0 || row == nSize - 1) {

    }
    vector<COLOR> temp(faces[3].cells[row]);
    int i = 0;
    while (i < 4)
        faces[i].cells[row] = faces[i++ +1].cells[row];
    faces[i].cells[row] = temp;
}


void RubicCube::rotate_up(int col){
    cout << "Column #" << col + 1 << " rotated up!\n" << endl;


}

void RubicCube::rotate_down(int col) {
    cout << "Column #" << col + 1 << " rotated down!\n" << endl;

}


void RubicCube::rotate_cw(int col) {
    cout << "Column #" << col + 1 << " rotated clockwise!\n" << endl;


}

void RubicCube::rotate_ccw(int col) {
    cout << "Column #" << col + 1 << " rotated counter-clockwise!\n" << endl;

}
