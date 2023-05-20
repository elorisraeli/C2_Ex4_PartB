#include <iostream>
#include <cmath>

#include "Character.hpp"
using namespace std;

namespace ariel
{
    Character::Character(string ch_name, Point position) : name(ch_name), positionP(position)
    {
    }
    Character::Character(string ch_name, Point position, int HPoints) : name(ch_name), positionP(position), hit_Points(HPoints)
    {
    }

    Character::~Character()
    {
    }

    bool Character::isAlive()
    {
        return (hit_Points > 0);
    }

    double Character::distance(Character *other)
    {
        return this->getLocation().distance(other->getLocation());
    }

    void Character::hit(int damage)
    {
        if (damage <= 0)
        {
            throw invalid_argument("Cannot hit nothing or negative number");
        }

        hit_Points -= damage;
        if (hit_Points < 0)
        {
            hit_Points = 0;
        }
    }

    string Character::getName()
    {
        return name;
    }
    Point Character::getLocation()
    {
        return positionP;
    }

    void Character::setLocation(Point new_position)
    {
        positionP = new_position;
    }

    string Character::print()
    {
        string characterType;
        if (isNinja())
        {
            characterType = "N";
        }
        else
        {
            characterType = "C";
        }

        string output = "";
        if (isAlive())
        {
            output += characterType + ": " + name + ", ";
            output += "HP: " + to_string(hit_Points) + ", ";
            output += "Position: " + positionP.print();
        }
        else
        {
            output += characterType + " (" + name + "), ";
            output += "Position: " + positionP.print();
        }

        return output;
    }

    int Character::getHitPoints()
    {
        return hit_Points;
    }

    void Character::moveTowards(Point destination, double distance)
    {
        positionP = positionP.moveTowards(positionP, destination, distance);
    }

    bool Character::getIsInTeam()
    {
        return is_in_team;
    }
    void Character::setIsInTeam(bool new_is_in_team)
    {
        is_in_team = new_is_in_team;
    }
}