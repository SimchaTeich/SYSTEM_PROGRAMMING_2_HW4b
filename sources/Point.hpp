#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;

    public:
        Point(double x, double y);
        Point(const Point& other);

        // getters
        int x() const;
        int y() const;

        /*
        Calc distance between this Point
        to other Point.
        input: other Point
        output: the distance type double.
        */
        double distance(const Point& other) const;

        /*
        print Point in this format:
        "(x,y)"
        */
        string print() const;

        /*
        calc some Point on the line, define by src and dst,
        with distance start from src.
        */
        static Point moveToWards(const Point& src, const Point& dst, double distance);
    };
};


#endif // !POINT_HPP