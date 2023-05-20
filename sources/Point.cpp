#include <iostream>
#include <math.h>
#include <stdexcept>

#include "Point.hpp"

using namespace std;

namespace ariel
{
    Point::Point(double x_value, double y_value) : x_axis(x_value), y_axis(y_value)
    {
    }
    Point::Point(const Point &other) : x_axis(other.x_axis), y_axis(other.y_axis)
    {
    }

    double Point::distance(const Point &point) const
    {
        double distance_X = (point.x_axis - x_axis);
        double distance_Y = (point.y_axis - y_axis);
        if (distance_X == 0 && distance_Y == 0)
        {
            return 0; // they are the same point
        }
        // return sqrt((distance_X * distance_X) + (distance_Y * distance_Y));
        return hypot(distance_X, distance_Y);
    }

    string Point::print()
{
    return "(" + to_string(x_axis) + ", " + to_string(y_axis) + ")";
}

    Point Point::moveTowards(const Point &source, const Point &destination, double distance)
    {
        if (distance < 0)
        {
            throw std::invalid_argument("Distance can't be negative.");
        }

        double distance_X = destination.x_axis - source.x_axis;
        double distance_Y = destination.y_axis - source.y_axis;

        double calculated_dis = sqrt((distance_X * distance_X) + (distance_Y * distance_Y));
        if (calculated_dis <= distance)
        {
            return destination;
        }

        double ratio = distance / calculated_dis;
        double newX = source.x_axis + (destination.x_axis - source.x_axis) * ratio;
        double newY = source.y_axis + (destination.y_axis - source.y_axis) * ratio;

        return Point(newX, newY);
    }

}