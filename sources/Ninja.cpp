#include <iostream>
#include <cmath>

#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(string ninja_name, Point positionNin) : Character(ninja_name, positionNin)
    {
        speed = 0;
    }

    Ninja::Ninja(string ninja_name, Point positionNin, int hit_Points, int speed) : Character(ninja_name, positionNin, hit_Points), speed(speed)
    {
    }

    void Ninja::move(Character *enemy)
    {
        if (isAlive())
        {
            double distanceToEnemy = distance(enemy);
            if (distanceToEnemy < speed)
            {

                setLocation(enemy->getLocation());
            }
            else
            {
                Point destination = getLocation().moveTowards(getLocation(), enemy->getLocation(), speed);
                setLocation(destination);
            }
        }
    }

    void Ninja::slash(Character *enemy)
    {
        if (!enemy->isAlive())
        {
            throw runtime_error("Cannot hit dead enemy");
        }
        if (!isAlive())
        {
            throw runtime_error("Cannot hit when dead");
        }

        if (enemy == this)
        {
            throw runtime_error("Cannot hit himself");
        }
        
        if (distance(enemy) < 1)
        {
            enemy->hit(40);
        }
    }

    int Ninja::getSpeed()
    {
        return speed;
    }

    bool Ninja::isNinja() const
    {
        return true;
    }

}