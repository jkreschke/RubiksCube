/*
* C++ class implementation of the 2x2x2 Rubik's cube
*
* @author
* Jake Reschke
* @collaborator
* Karry Wong
*/

#include <vector>
#include "RubiksCube2.h"

// Default constructor
RubiksCube2::RubiksCube2(){
    frontFace_ = Face(1);
    topFace_ = Face(6);
    backFace_ = Face(3);
    bottomFace_ = Face(5);
    leftFace_ = Face(4);
    rightFace_ = Face(2);
    testing = false;
}

// CONSTRUCTOR FOR TESTING
RubiksCube2::RubiksCube2(int val){
    testing = true;
    Face* faces[6] = {& frontFace_,& topFace_,& backFace_,& bottomFace_,& leftFace_,& rightFace_};
    for(unsigned k = 0; k < 6; k ++){
        for(unsigned i = 0; i < 2; i++){
            for(unsigned j = 0; j < 2; j++){
                faces[k] -> values_[i][j] = ( (k+1) * 10) + (2 * i) + j;
            }
        }
    }
}

/*
* ==============================================
* CUBE MOVES. Changes internal state of the cube
* ==============================================
*/

void RubiksCube2::FrontCW(){
    frontFace_.RotateCW();
    std::vector<int> temp = rightFace_.GetCol(0);
    rightFace_.ReplaceCol(0,topFace_.GetRow(1));
    topFace_.ReplaceRow(1,leftFace_.GetCol(1),true);
    leftFace_.ReplaceCol(1,bottomFace_.GetRow(0));
    bottomFace_.ReplaceRow(0,temp,true);
}

void RubiksCube2::FrontCCW(){
    frontFace_.RotateCCW();
    std::vector<int> temp = rightFace_.GetCol(0);
    rightFace_.ReplaceCol(0,bottomFace_.GetRow(0),true);
    bottomFace_.ReplaceRow(0,leftFace_.GetCol(1));
    leftFace_.ReplaceCol(1,topFace_.GetRow(1),true);
    topFace_.ReplaceRow(1,temp);
}

void RubiksCube2::TopCW(){
    topFace_.RotateCW();
    std::vector<int> temp = frontFace_.GetRow(0);
    frontFace_.ReplaceRow(0,rightFace_.GetRow(0));
    rightFace_.ReplaceRow(0,backFace_.GetRow(0));
    backFace_.ReplaceRow(0,leftFace_.GetRow(0));
    leftFace_.ReplaceRow(0,temp);
}

void RubiksCube2::TopCCW(){
    topFace_.RotateCCW();
    std::vector<int> temp = frontFace_.GetRow(0);
    frontFace_.ReplaceRow(0,leftFace_.GetRow(0));
    leftFace_.ReplaceRow(0,backFace_.GetRow(0));
    backFace_.ReplaceRow(0,rightFace_.GetRow(0));
    rightFace_.ReplaceRow(0,temp);
}

void RubiksCube2::BackCW(){
    backFace_.RotateCW();
    std::vector<int> temp = leftFace_.GetCol(0);
    leftFace_.ReplaceCol(0, topFace_.GetRow(0), true);
    topFace_.ReplaceRow(0, rightFace_.GetCol(1));
    rightFace_.ReplaceCol(1, bottomFace_.GetRow(1), true);
    bottomFace_.ReplaceRow(1, temp);
}

void RubiksCube2::BackCCW(){
    backFace_.RotateCCW();
    std::vector<int> temp = leftFace_.GetCol(0);
    leftFace_.ReplaceCol(0, bottomFace_.GetRow(1));
    bottomFace_.ReplaceRow(1, rightFace_.GetCol(1), true);
    rightFace_.ReplaceCol(1, topFace_.GetRow(0));
    topFace_.ReplaceRow(0, temp, true);
}

void RubiksCube2::BottomCW(){
    bottomFace_.RotateCW();
    std::vector<int> temp = frontFace_.GetRow(1);
    frontFace_.ReplaceRow(1, leftFace_.GetRow(1));
    leftFace_.ReplaceRow(1, backFace_.GetRow(1));
    backFace_.ReplaceRow(1, rightFace_.GetRow(1));
    rightFace_.ReplaceRow(1, temp);
}

void RubiksCube2::BottomCCW(){
    bottomFace_.RotateCCW();
    std::vector<int> temp = frontFace_.GetRow(1);
    frontFace_.ReplaceRow(1,rightFace_.GetRow(1));
    rightFace_.ReplaceRow(1, backFace_.GetRow(1));
    backFace_.ReplaceRow(1, leftFace_.GetRow(1));
    leftFace_.ReplaceRow(1, temp);
}

void RubiksCube2::LeftCW(){
    leftFace_.RotateCW();
    std::vector<int> temp = frontFace_.GetCol(0);
    frontFace_.ReplaceCol(0, topFace_.GetCol(0));
    topFace_.ReplaceCol(0, backFace_.GetCol(1), true);
    backFace_.ReplaceCol(1, bottomFace_.GetCol(0), true);
    bottomFace_.ReplaceCol(0, temp);
}

void RubiksCube2::LeftCCW(){
    leftFace_.RotateCCW();
    std::vector<int> temp = frontFace_.GetCol(0);
    frontFace_.ReplaceCol(0, bottomFace_.GetCol(0));
    bottomFace_.ReplaceCol(0, backFace_.GetCol(1), true);
    backFace_.ReplaceCol(1, topFace_.GetCol(0), true);
    topFace_.ReplaceCol(0, temp);
}

void RubiksCube2::RightCW(){
    rightFace_.RotateCW();
    std::vector<int> temp = frontFace_.GetCol(1);
    frontFace_.ReplaceCol(1, bottomFace_.GetCol(1));
    bottomFace_.ReplaceCol(1, backFace_.GetCol(0), true);
    backFace_.ReplaceCol(0, topFace_.GetCol(1), true);
    topFace_.ReplaceCol(1, temp);
}

void RubiksCube2::RightCCW(){
    rightFace_.RotateCCW();
    std::vector<int> temp = frontFace_.GetCol(1);
    frontFace_.ReplaceCol(1,topFace_.GetCol(1));
    topFace_.ReplaceCol(1, backFace_.GetCol(0), true);
    backFace_.ReplaceCol(0, bottomFace_.GetCol(1), true);
    bottomFace_.ReplaceCol(1, temp);
}

/*
* =========================================================
* MOVE PREVIEWS Returns deep copy of cube with move applied
* =========================================================
*/

RubiksCube2 RubiksCube2::PrevFrontCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.FrontCW();
    return cube_copy;
}

RubiksCube2 RubiksCube2::PrevFrontCCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.FrontCCW();
    return cube_copy;
}

RubiksCube2 RubiksCube2::PrevTopCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.TopCW();
    return cube_copy; 
}

RubiksCube2 RubiksCube2::PrevTopCCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.TopCCW();
    return cube_copy; 
}

RubiksCube2 RubiksCube2::PrevBackCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.BackCW();
    return cube_copy; 
}

RubiksCube2 RubiksCube2::PrevBackCCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.BackCCW();
    return cube_copy;    
}

RubiksCube2 RubiksCube2::PrevBottomCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.BottomCW();
    return cube_copy;      
}

RubiksCube2 RubiksCube2::PrevBottomCCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.BottomCCW();
    return cube_copy;     
}

RubiksCube2 RubiksCube2::PrevLeftCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.LeftCW();
    return cube_copy;     
}

RubiksCube2 RubiksCube2::PrevLeftCCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.LeftCCW();
    return cube_copy;     
}

RubiksCube2 RubiksCube2::PrevRightCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.RightCW();
    return cube_copy;  
}

RubiksCube2 RubiksCube2::PrevRightCCW(){
    RubiksCube2 cube_copy = *this;
    cube_copy.RightCCW();
    return cube_copy;     
}

/*
* ==============================================
* Some miscellaneous operations
* ==============================================
*/

bool RubiksCube2::IsSolved(){
    if (!frontFace_.IsSame()){
        return false;
    } else if (!topFace_.IsSame()){
        return false;
    } else if (!backFace_.IsSame()){
        return false;
    } else if (!bottomFace_.IsSame()){
        return false;
    } else if (!leftFace_.IsSame()){
        return false;
    } else if (!rightFace_.IsSame()){
        return false;
    } else{
        return true;
    }
}


/*
* ==============================================
* Cube symmetries
* ==============================================
*/

void RubiksCube2::FlipUp(){
    this -> RightCW();
    this -> LeftCCW();
}

void RubiksCube2::FlipDown(){
    this -> RightCCW();
    this -> LeftCW();
}

void RubiksCube2::FlipLeft(){
    this -> TopCCW();
    this -> BottomCW();
}

void RubiksCube2::FlipRight(){
    this -> TopCW();
    this -> BottomCCW();
}

/*
* ==============================================
* Print things to the terminal
* ==============================================
*/

void RubiksCube2::PrintInstructions(){
    std::cout << "         " << " --- --- " << std::endl;
    std::cout << "         " << "|   |   |" << std::endl;
    std::cout << "         " << " --Top-- " << std::endl;
    std::cout << "         " << "|   |   |" << std::endl;
    std::cout << "         " << " --- --- " << std::endl;

    std::cout << " --- --- " << " --- --- " << " --- --- " << " --- --- " << std::endl;
    std::cout << "|   |   |" << "|   |   |" << "|   |   |" << "|   |   |" << std::endl;
    std::cout << " - Left- " << " -Front- " << " -right- " << " -back - " << std::endl;
    std::cout << "|   |   |" << "|   |   |" << "|   |   |" << "|   |   |" << std::endl;
    std::cout << " --- --- " << " --- --- " << " --- --- " << " --- --- " << std:: endl;

    std::cout << "         " << " --- --- " << std::endl;
    std::cout << "         " << "|   |   |" << std::endl;
    std::cout << "         " << " -bottom " << std::endl;
    std::cout << "         " << "|   |   |" << std::endl;
    std::cout << "         " << " --- --- " << std::endl;
}

std::ostream & operator<<(std::ostream & os, const RubiksCube2 & cube){
    const Face* faces[4] = {&cube.leftFace_,&cube.frontFace_,&cube.rightFace_,&cube.backFace_};
    if (cube.testing){
        os << "         " << " --- --- " << std::endl;
        os << "         " << "| " << cube.topFace_.values_[0][0] << "|" << cube.topFace_.values_[0][1] << " |" << std::endl;
        os << "         " << " --- --- " << std::endl;
        os << "         " << "| " << cube.topFace_.values_[1][0] << "|" << cube.topFace_.values_[1][1] << " |" << std::endl;
        os << "         " << " --- --- " << std::endl;

        os << " --- --- " << " --- --- " << " --- --- " << " --- --- " << std::endl;
        for (int i = 0; i < 4; i++){
            os << "| " << faces[i] -> values_[0][0] << "|" << faces[i] -> values_[0][1] << " |";
        }
        os << std::endl;
        os << " --- --- " << " --- --- " << " --- --- " << " --- --- " << std::endl;
        for (int i = 0; i < 4; i++){
            os << "| " << faces[i] -> values_[1][0] << "|" << faces[i] -> values_[1][1] << " |";
        }
        os << std::endl;
        os << " --- --- " << " --- --- " << " --- --- " << " --- --- " << std::endl;

        os << "         " << " --- --- " << std::endl;
        os << "         " << "| " << cube.bottomFace_.values_[0][0] << "|" << cube.bottomFace_.values_[0][1] << " |" << std::endl;
        os << "         " << " --- --- " << std::endl;
        os << "         " << "| " << cube.bottomFace_.values_[1][0] << "|" << cube.bottomFace_.values_[1][1] << " |" << std::endl;
        os << "         " << " --- --- " << std::endl;

    } else{
        os << "         " << " --- --- " << std::endl;
        os << "         " << "| " << cube.topFace_.values_[0][0] << " | " << cube.topFace_.values_[0][1] << " |" << std::endl;
        os << "         " << " --- --- " << std::endl;
        os << "         " << "| " << cube.topFace_.values_[1][0] << " | " << cube.topFace_.values_[1][1] << " |" << std::endl;
        os << "         " << " --- --- " << std::endl;

        os << " --- --- " << " --- --- " << " --- --- " << " --- --- " << std::endl;
        for (int i = 0; i < 4; i++){
            os << "| " << faces[i] -> values_[0][0] << " | " << faces[i] -> values_[0][1] << " |";
        }
        os << std::endl;
        os << " --- --- " << " --- --- " << " --- --- " << " --- --- " << std::endl;
        for (int i = 0; i < 4; i++){
            os << "| " << faces[i] -> values_[1][0] << " | " << faces[i] -> values_[1][1] << " |";
        }
        os << std::endl;
        os << " --- --- " << " --- --- " << " --- --- " << " --- --- " << std::endl;

        os << "         " << " --- --- " << std::endl;
        os << "         " << "| " << cube.bottomFace_.values_[0][0] << " | " << cube.bottomFace_.values_[0][1] << " |" << std::endl;
        os << "         " << " --- --- " << std::endl;
        os << "         " << "| " << cube.bottomFace_.values_[1][0] << " | " << cube.bottomFace_.values_[1][1] << " |" << std::endl;
        os << "         " << " --- --- " << std::endl;
    }

    return os;
}
