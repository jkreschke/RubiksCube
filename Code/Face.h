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
    void RotateCW();
    void RotateCCW();
    std::vector<int> GetRow(unsigned row);
    std::vector<int> GetCol(unsigned col);
    void ReplaceRow(unsigned row, std::vector<int> new_row);
    void ReplaceCol(unsigned row, std::vector<int> new_col);
    bool IsSame();

    private:
    int values_ [2][2];
    
};

