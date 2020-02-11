#ifndef POINT_H
#define POINT_H
#include <vector>
#include <iostream>

class Point
{
public:
    Point(int);
    Point(std::vector<int>);
    int NumberDim(Point);
    ~Point();
    int GetDims(int);
    void SetDims();
    int Distance(Point, Point);
    void Translate(Point&, int);
    std::vector<int> dimensions;
};

#endif // POINT_H
