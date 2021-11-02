/*
* Simple C++ class for representing one face of the Rubiks Cube
*
* @author
* Jake Reschke & Karry Wong
*/

#include "Face.h"

Face::Face(){
    Face(0);
}

Face::Face(int val){
    for(unsigned i = 0; i < 2; i++){
        for(unsigned j = 0; j < 2; j++){
            values_[i][j] = val;
        }
    }
}

void Face::RotateCW(){
    int temp = values_[0][0];
    values_[0][0] = values_[1][0];
    values_[1][0] = values_[1][1];
    values_[1][1] = values_[0][1];
    values_[0][1] = temp;
}

void Face::RotateCCW(){
    int temp = values_[0][0];
    values_[0][0] = values_[0][1];
    values_[0][1] = values_[1][1];
    values_[1][1] = values_[1][0];
    values_[1][0] = temp;
}

void Face::ReplaceRow(unsigned row, std::vector<int> new_row, bool reversed){
    if (reversed){
        for (unsigned j = 0; j < 2; j++){
            values_[row][j] = new_row[1 - j];
        }
    } else{
        for(unsigned j = 0; j < 2; j++){
            values_[row][j] = new_row[j];
        }
    }
}

void Face::ReplaceCol(unsigned col, std::vector<int> new_col, bool reversed){
    if (reversed){
        for(unsigned i = 0; i < 2; i++){
            values_[i][col] = new_col[1 - i];
        }
    } else{
        for(unsigned i = 0; i < 2; i++){
            values_[i][col] = new_col[i];
        }
    }
}

std::vector<int> Face::GetRow(unsigned row){
    std::vector<int> row_vec;
    for(unsigned j = 0; j < 2; j++){
        row_vec.push_back(values_[row][j]);
    }
    return row_vec;
}

std::vector<int> Face::GetCol(unsigned col){
    std::vector<int> col_vec;
    for(unsigned i = 0; i < 2; i++){
        col_vec.push_back(values_[i][col]);
    }
    return col_vec;
}

bool Face::IsSame(){
    for(unsigned i = 0; i < 2; i++){
        for(unsigned j = 0; j < 2; j++){
            if (values_[i][j] != values_[0][0]){
                return false;
            }
        }
    }
    return true;
}

std::ostream & operator<<(std::ostream & os, const Face & face){
    os << " --- --- " << std::endl;
    os << "| " << face.values_[0][0] << " | " << face.values_[0][1] << " |" << std::endl;
    os << " --- --- " << std::endl;
    os << "| " << face.values_[1][0] << " | " << face.values_[1][1] << " |" << std::endl;
    os << " --- --- " << std::endl;
    return os;
}
