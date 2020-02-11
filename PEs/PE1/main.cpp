#include <iostream>
#include <string>
#include "Point.h"
using namespace std;

/**
 * JC Abrahamson
 * PE 1
 * This program creates three user generated points on a 2D
 * plane. It then translates and calculates euclidean distance 
 * between the points and displays its results to the user.
 */

int main(){
	Point origin();
    Point p1(4, 10);
    Point p2(7, 2);
    Point p3(6, 7);
    cout << "Point 1:(" + to_string(p1.x) + ',' + to_string(p1.y) + ')' << endl;
    cout << "Point 2:(" + to_string(p2.x) + ',' + to_string(p2.y) + ')' << endl;
    cout << "Point 3:(" + to_string(p3.x) + ',' + to_string(p3.y) + ')' << endl << endl;

    int dis12 = p1.Distance(p1, p2);
    cout << "Distance between points 1 & 2: " + to_string(dis12) << endl;
    int dis13 = p1.Distance(p1, p3);
    cout << "Distance between points 1 & 3: " + to_string(dis13) << endl;
    int dis23 = p2.Distance(p2, p3);
    cout << "Distance between points 2 & 3: " + to_string(dis23) << endl << endl;

    p1.Translate(p1, 4);
    cout << "Point 1 Translated +4 units: (" + 
            to_string(p1.x) + ',' + to_string(p1.y) + ')' << endl;
    dis12 = p1.Distance(p1, p2);
    cout << "Distance between points 1 & 2: " + to_string(dis12) << endl;
    dis13 = p1.Distance(p1, p3);
    cout << "Distance between points 1 & 3: " + to_string(dis13) << endl;
    dis23 = p2.Distance(p2, p3);
    cout << "Distance between points 2 & 3: " + to_string(dis23) << endl << endl;

    p2.Translate(p1, -12);
    cout << "Point 1 Now Translated -12 units: (" + 
            to_string(p1.x) + ',' + to_string(p1.y) + ')' << endl;
    dis12 = p1.Distance(p1, p2);
    cout << "Distance between points 1 & 2: " + to_string(dis12) << endl;
    dis13 = p1.Distance(p1, p3);
    cout << "Distance between points 1 & 3: " + to_string(dis13) << endl;
    dis23 = p2.Distance(p2, p3);
    cout << "Distance between points 2 & 3: " + to_string(dis23) << endl << endl;

	int get_x = p3.x;
	int get_y = p3.y;
	cout << "Test of getter function:" << endl;
	cout << "Get the x and y value @ Point 3" << endl;
	cout << "x= " + to_string(get_x) << endl;
	cout << "y= " + to_string(get_y) << endl;

    return 0;
}   