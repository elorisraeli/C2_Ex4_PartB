#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point positionP;
        int hit_Points;
        string name;
        bool is_in_team = false;

    public:
        Character(string ch_name, Point position);
        Character(string ch_name, Point position, int HPoints);
        virtual ~Character(); // Make the destructor virtual
        bool isAlive();
        double distance(Character *other);
        void hit(int damage);
        string getName();
        Point getLocation();
        void setLocation(Point new_position);
        virtual string print();

        int getHitPoints();
        void moveTowards(Point destination, double distance);

        virtual bool isNinja() const = 0;

        bool getIsInTeam();
        void setIsInTeam(bool new_is_in_team);
    };
}

#endif // CHARACTER_HPP