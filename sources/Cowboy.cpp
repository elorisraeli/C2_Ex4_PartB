#include <iostream>
#include <cmath>

#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(string cow_name, Point positionCo) : Character(cow_name, positionCo, 110), num_of_bullets(6)
    {
    }

    void Cowboy::shoot(Character *enemy)
    {
        if (!isAlive())
        {
            throw runtime_error("Cannot hit when dead");
        }

        if (enemy == this)
        {
            throw runtime_error("Cannot hit himself");
        }

        if (!enemy->isAlive())
        {
            throw runtime_error("Cannot hit dead enemy");
        }

        if (hasboolets())
        {
            num_of_bullets--;
            enemy->hit(10);
        }
        else
        {
            reload();
        }
    }

    bool Cowboy::hasboolets()
    {
        return (num_of_bullets > 0);
    }

    void Cowboy::reload()
    {
        if (!isAlive())
        {
            throw runtime_error("Cant reload when dead");
        }
        num_of_bullets = 6;
    }

    int Cowboy::getBullets()
    {
        return num_of_bullets;
    }

    bool Cowboy::isNinja() const
    {
        return false;
    }

}