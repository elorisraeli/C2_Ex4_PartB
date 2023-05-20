#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string ninja_name, Point positionNin);
        Ninja(string ninja_name, Point positionNin, int hit_Points, int speed);
        void move(Character *enemy);
        void slash(Character *enemy);

        int getSpeed();

        // Override function
        virtual bool isNinja() const override;
    };
}

#endif // NINJA_HPP