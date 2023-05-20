#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <iostream>
#include <vector>
#include "Team.hpp"

using namespace std;

namespace ariel
{
    class Team2 : public Team
    {
    private:


    public:
        Team2(Character* pLeaderT2);
        ~Team2();
        void attack(Team *enemy_team);      

    };
}

#endif // TEAM2_HPP