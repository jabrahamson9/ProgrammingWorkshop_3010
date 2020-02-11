#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
public:
    Point();
    Point(int, int);
    ~Point();
    int GetX();
    int GetY();
    void SetX();
    void SetY();
    int Distance(Point, Point);
    void Translate(Point&, int);
    int x;
    int y;
};

#endif // POINT_H
