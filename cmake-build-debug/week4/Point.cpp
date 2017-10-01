//
// Created by malthe on 9/29/17.
//

//#include "Point.h"

#include <cmath>
#include <iostream>

using namespace std;

class Point {

private:
    int xval, yval, xgoal, ygoal;

public:

    // Constructor uses default arguments to allow calling with zero, one,
    // or two values.
    Point(int x, int y) {
        xval = x;
        yval = y;

    }

    Point(int x, int y, int xgoal, int ygoal) {
        xval = x;
        yval = y;
        this->xgoal = xgoal;
        this->ygoal = ygoal;

    }

    // Extractors.
    int x() { return xval; }
    int y() { return yval; }
    int xGoal() { return xgoal; }
    int yGoal() { return ygoal; }

    // Distance to another point.  Pythagorean thm.
    double dist(Point other) {
        int xd = xval - other.xval;
        int yd = yval - other.yval;
        //return sqrt(xd*xd + yd*yd);
        return xd + yd;
    }

    // Add or subtract two points.
    Point add(Point b)
    {
        return Point(xval + b.xval, yval + b.yval);
    }
    Point sub(Point b)
    {
        return Point(xval - b.xval, yval - b.yval);
    }

    // Move the existing point.
    void move(double a, double b)
    {
        xval += a;
        yval += b;
    }

    // Print the point on the stream.  The class ostream is a base class
    // for output streams of various types.
    void print(ostream &strm)
    {
        strm << "(" << xval << "," << yval << ")";
    }

};