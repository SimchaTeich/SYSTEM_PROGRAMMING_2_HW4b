#include "Point.hpp"
#include <cmath> // sqrt, pow

using namespace ariel;


Point::Point(double x, double y) : _x(x), _y(y) {};


Point::Point(const Point& other)
{
    _x = other._x;
    _y = other._y;
};


int Point::x() const
{
    return _x;
};


int Point::y() const
{
    return _y;
};


double Point::distance(const Point& other) const
{
    return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
};


string Point::print() const
{
    string pointString = "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
    return pointString;
};


// Helps after some changes:
//https://stackoverflow.com/questions/13302396/given-two-points-find-a-third-point-on-the-line
Point Point::moveToWards(const Point& src, const Point& dst, double distance)
{
    // clac the vector
    double vx = dst._x - src._x;
    double vy = dst._y - src._y;

    double mag = sqrt(vx * vx + vy * vy);

    // normalize the vector
    vx /= mag;
    vy /= mag;

    vx *= distance;
    vy *= distance;

    double new_x = src._x + vx;
    double new_y = src._y + vy;

    return Point(new_x, new_y);
}
