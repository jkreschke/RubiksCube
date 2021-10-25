/*
* C++ class implementation of the 2x2x2 Rubik's cube
* 
* @author 
* Jake Reschke
*/

#pragma once
#include <iostream>
#include "Face.h"

class RubiksCube2{
    public:
    RubiksCube2();

    // moves
    void FrontRotateCw();
    void FrontRotateCCW();
    void TopRotateCw();
    void TopRotateCCW();
    void BackRotateCw();
    void BackRotateCCW();
    void BotRotateCw();
    void BotRotateCCW();
    void LeftRotateCw();
    void LeftRotateCCW();
    void RightRotateCw();
    void RightRotateCCW();

    bool isSolved();

    // cube symmetries
    void FlipUp();
    void FlipDown();
    void FlipLeft();
    void FlipRight();

    // overloaded << operator for printing the cube state to the console
    friend std::ostream& operator<<(std::ostream & os, const RubiksCube2 & cube);

    private:

    Face frontFace_;
    Face topFace_;
    Face backFace_;
    Face botFace_;
    Face leftFace_;
    Face rightFace_;

};