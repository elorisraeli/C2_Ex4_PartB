#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

#include "SmartTeam.hpp"

using namespace std;

namespace ariel
{
    SmartTeam::SmartTeam(Character *pLeaderT2) : Team(pLeaderT2)
    {
    }

    SmartTeam::~SmartTeam()
    {
    }

    // void SmartTeam::attack(Team *enemy_team)
    // {
    //     // Assess the situation
    //     Character *myLeader = getLeader();
    //     int myAliveCount = stillAlive();
    //     int enemyAliveCount = enemy_team->stillAlive();

    //     // Prioritize targets
    //     // In this example, we prioritize the enemy team's leader and characters with low hit points
    //     Character *enemyLeader = enemy_team->getLeader();
    //     Character *priorityTarget = enemyLeader;
    //     for (Character *enemy : enemy_team->fighters)
    //     {
    //         if (enemy->isAlive() && enemy->getHitPoints() < priorityTarget->getHitPoints())
    //         {
    //             priorityTarget = enemy;
    //         }
    //     }

    //     // Coordinate attacks
    //     for (Character *fighter : fighters)
    //     {
    //         if (!fighter->isAlive())
    //         {
    //             continue;
    //         }

    //         Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
    //         if (cowboy != nullptr && cowboy->hasboolets())
    //         {
    //             cowboy->shoot(priorityTarget);
    //         }
    //         else
    //         {
    //             Ninja *ninja = dynamic_cast<Ninja *>(fighter);
    //             if (ninja != nullptr && ninja->distance(priorityTarget) < 1)
    //             {
    //                 ninja->slash(priorityTarget);
    //             }
    //             else
    //             {
    //                 fighter->moveTowards(priorityTarget->getLocation(), fighter->getSpeed());
    //             }
    //         }
    //     }

    //     // Adapt to changing circumstances
    //     // In this example, we do not implement dynamic adaptation, but you can add logic here based on the changing situation during the attack.
    // }
}