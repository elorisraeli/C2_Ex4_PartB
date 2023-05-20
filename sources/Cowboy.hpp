#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int num_of_bullets;

    public:
        Cowboy(string cow_name, Point positionCo);
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();

        int getBullets();

        // Override function
        virtual bool isNinja() const override;
    };
}

#endif // COWBOY_HPP