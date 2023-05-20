#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace ariel
{
    class Point
    {
    private:
        double x_axis;
        double y_axis;

    public:
        Point(double x_value, double y_value);
        Point(const Point &other);

        double distance(const Point &point) const;

        std::string print();

        static Point moveTowards(const Point &source, const Point &destination, double distance);
    };
}

#endif // POINT_HPP