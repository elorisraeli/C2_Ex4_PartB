#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

using namespace std;

namespace ariel
{
    class Team
    {
    protected:
        vector<Character *> fighters;
        Character *leader;
        bool isMember(Character *character);

    public:
        Team(Character *pLeader);
        ~Team();
        void add(Character *figther_to_add);
        virtual void attack(Team *enemy_team);
        int stillAlive();
        void print();

        void remove(Character *fighter_to_remove);
        Character *getLeader();
        size_t size();

        vector<Character *> getFigthers();
    };
}

#endif // TEAM_HPP