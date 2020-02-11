#include <iostream>
#include "Point.h"
#include <sstream>
#include <cmath> //to use exponentiation pow()
#include <vector>
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
Point::Point(int n){
    vector<int> dimensions_origin(n, 0);
}

/**
 * Constructor that plots a point in a 2D plane.
 * @param x_input the x value of the coordinate
 * @param y_inout the y value of the coordinate
 */
Point::Point(std::vector<int> dim){
    dimensions = dim;
}

/**
 * Decunstructor
 */
Point::~Point(){

}

int Point::NumberDim(Point p){
    int size = p.dimensions.size();
    return size;
}

/**
 * Getter for x attribute of class instance
 * @return x the x attribute value of the instance
 */
int Point::GetDims(int n){
    return this->dimensions.at(n);
}

/**
 * Setter function to apply x attribute to class instance
 */
void Point::SetDims(){
    this->dimensions = dimensions;
}


/**
 * Function that calculates the Euclidian distance between the 
 * point's current x and y attributes. 
 * @param p1 the first point instance to be compared
 * @param p2 the second point instance to be compared
 * @return distance integer distance rounded down between the points
 */
int Point::Distance(Point p1, Point p2){
    try {
        if(p1.dimensions.size() != p2.dimensions.size()){
            throw p1;
        }
        int sqr_distance = 0;
        for(unsigned int i = 0; i < p1.dimensions.size(); i++){
            sqr_distance = sqr_distance + pow(p1.dimensions[i] - p2.dimensions[i], 2);
        }
        int distance = sqrt(sqr_distance);
        return distance;
    }
    catch(Point p1){
        cout<< "Error: # of Dimensions Do Not Match" << endl;
        return -1;
    }
}

/**
 * Function takes translates a point by a given integer. 
 * @param &p1 a reference to the point to change its attributes
 * @param trans the integer to translate the point by
 */
void Point::Translate(Point &p1, int trans){
    for(unsigned int i = 0; i<p1.dimensions.size(); i++){
        p1.dimensions.at(i) = p1.dimensions.at(i) + trans;
    }
}


