#include <iostream>
#include "Point.h"
#include <sstream>
#include <cmath> //to use exponentiation pow()
using namespace std;

/**
 * JC Abrahamson
 * PE 1
 * The function code for a program that creates three user 
 * generated points on a 2D plane, translates and 
 * calculates euclidean distance between points.
 */

/**
 * Constructor with no paramaters that creats a point
 * at the origin.
 */
Point::Point(){
	x = 0;
    y = 0;
}

/**
 * Constructor that plots a point in a 2D plane.
 * @param x_input the x value of the coordinate
 * @param y_input the y value of the coordinate
 */
Point::Point(int x_input, int y_input){
    x = x_input;
    y = y_input;
}

/**
 * Decunstructor
 */
Point::~Point(){

}

/**
 * Getter for x attribute of class instance
 * @return x the x attribute value of the instance
 */
int Point::GetX(){
    return this->x;
}

/**
 * Getter for y attribute of class instance
 * @return y the y attribute value of the instance
 */
int Point::GetY(){
    return this->y;
}

/**
 * Setter function to apply x attribute to class instance
 */
void Point::SetX(){
    this->x = x;
}

/**
 * Setter function to apply y attribute to class instance
 */
void Point::SetY(){
    this->y = y;
}

/**
 * Function that calculates the Euclidian distance between the 
 * point's current x and y attributes. 
 * @param p1 the first point instance to be compared
 * @param p2 the second point instance to be compared
 * @return distance integer distance rounded down between the points
 */
int Point::Distance(Point p1, Point p2){
    int a = p1.x - p2.x; //for simplcity
    int b = p1.y - p2.y; //for simplicity
    int distance = sqrt(pow(a, 2) + pow(b, 2)); //Euclidian distance formula
    return distance;
}

/**
 * Function takes translates a point by a given integer. 
 * @param &p1 a reference to the point to change its attributes
 * @param trans the integer to translate the point by
 */
void Point::Translate(Point &p1, int trans){
    p1.x = p1.x + trans;
    p1.y = p1.y + trans;
}


