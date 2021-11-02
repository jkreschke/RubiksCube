/*
* C++ class implementation of the 2x2x2 Rubik's cube
*
* @author
* Jake Reschke
* @collaborator
* Karry Wong
*/

#pragma once
#include <iostream>
#include "Face.h"

class RubiksCube2{
    public:
    RubiksCube2();
    // constructor for testing:
    RubiksCube2(int val);

    // moves
    void FrontCW();
    void FrontCCW();
    void TopCW();
    void TopCCW();
    void BackCW();
    void BackCCW();
    void BottomCW();
    void BottomCCW();
    void LeftCW();
    void LeftCCW();
    void RightCW();
    void RightCCW();

    // move previews
    RubiksCube2 PrevFrontCW();
    RubiksCube2 PrevFrontCCW();
    RubiksCube2 PrevTopCW();
    RubiksCube2 PrevTopCCW();
    RubiksCube2 PrevBackCW();
    RubiksCube2 PrevBackCCW();
    RubiksCube2 PrevBottomCW();
    RubiksCube2 PrevBottomCCW();
    RubiksCube2 PrevLeftCW();
    RubiksCube2 PrevLeftCCW();
    RubiksCube2 PrevRightCW();
    RubiksCube2 PrevRightCCW();

    bool IsSolved();
    void Solve(bool print_path);
    void RandMoves(unsigned num_moves);
    void PrintInstructions();

    // cube symmetries
    void FlipUp();
    void FlipDown();
    void FlipLeft();
    void FlipRight();

    // overloaded << operator for printing the cube state to the console
    friend std::ostream & operator<<(std::ostream & os, const RubiksCube2 & cube);


    private:

    Face frontFace_;
    Face topFace_;
    Face backFace_;
    Face bottomFace_;
    Face leftFace_;
    Face rightFace_;

    bool testing;

};
