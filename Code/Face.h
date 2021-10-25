/*
* Simple C++ class for representing one face of the Rubiks Cube
*
* @author
* Jake Reschke
*/

#pragma once
#include <vector>

class Face{
    public:
    Face();
    Face(int val);
    void rotateCW();
    void RotateCCW();
    std::vector<int> getRow(unsigned row);
    std::vector<int> getCol(unsigned col);
    void replaceRow(unsigned row, std::vector<int> new_row);
    void replaceCol(unsigned row, std::vector<int> new_col);
    bool isSame();

    private:
    int values_ [2][2];
    
};

