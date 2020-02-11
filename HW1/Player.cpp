#include <iostream>
#include "Player.h"
#include <string>
using namespace std;

/**
 * Constructor to create a new player
 * @param name the name of the new player
 * @param is_human whether or not the player is the human
 */
Player::Player(const string name, const bool is_human){
    name_ = name;
    is_human_ = is_human;
}

/**
 * Method to update player point value
 * @param x the value to itterate the points by
 */
void Player::ChangePoints(const int x){
    points_ = points_ + x;
}

/**
 * Constructor that plots a point in a 2D plane.
 * @param x_input the x value of the coordinate
 * @param y_inout the y value of the coordinate
 */
void Player::SetPosition(Position pos){
    pos_.row = pos.row;
    pos_.col = pos.col;
}

/**
 * method to assign the direction associated with the passed other position relative to the current position
 * @param other a new position to compare to current player position
 * @return string direction of other position relative to current position
 */
string Player::ToRelativePosition(Position other){
    int row_difference = other.row - pos_.row;
    int col_difference = other.col - pos_.col;
    //new position one space right relative to position
    if(row_difference == 1 && col_difference == 0){
        return "RIGHT";
    }
    //new position one space left relative to position
    else if(row_difference == -1 && col_difference == 0){
        return "LEFT";
    }
    //new position one space up relative to position
    else if(row_difference == 0 && col_difference == 1){
        return "DOWN";
    }
    //new position one space down relative to position
    else if(row_difference == 0 && col_difference == 1){
        return "UP";
    }
    //otherise new position is not within single space distance
    else{
        return "INVALID";
    }
}

/**
 * turns point value into a string and pair it with player name
 * @param points_ the points_ attribute of the player instnace
 * @return string of "[player name] - [player points]"
 */
string Player::Stringify(){
    string str_points = to_string(points_); //convert int points to string
    string return_str = name_ + "-" + str_points;
    return return_str;
}

