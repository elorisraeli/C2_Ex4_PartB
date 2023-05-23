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

    void SmartTeam::attack(Team *enemy_team)
    {
        // Similar basic checks as in the parent class
        if (enemy_team == nullptr)
        {
            throw invalid_argument("Cannot attack nullptr team");
        }

        if (enemy_team->stillAlive() == 0)
        {
            throw runtime_error("Cannot hit a dead team");
        }

        if (!leader->isAlive())
        {
            // Similar leader replacement strategy as in Team class
            // Find the living character closest to the dead leader
            double minDistance = numeric_limits<double>::max();
            Character *newLeader = nullptr;

            for (Character *fighter : fighters)
            {
                if (fighter->isAlive())
                {
                    double distance = leader->distance(fighter);
                    if (distance < minDistance)
                    {
                        minDistance = distance;
                        newLeader = fighter;
                    }
                }
            }

            if (newLeader != nullptr)
            {
                leader = newLeader;
            }
            else
            {
                return; // No living character found, the attack ends
            }
        }

        // Now, the smart strategy begins:
        // Attack the enemy with the lowest health first
        while (stillAlive() > 0 && enemy_team->stillAlive() > 0)
        {
            Character *lowestHealthEnemy = nullptr;
            int minHealth = numeric_limits<int>::max();

            // Find the enemy with the lowest health
            for (Character *enemy : enemy_team->getFigthers())
            {
                if (enemy->isAlive() && enemy->getHitPoints() < minHealth)
                {
                    minHealth = enemy->getHitPoints();
                    lowestHealthEnemy = enemy;
                }
            }

            // If no enemy found, end the attack
            if (lowestHealthEnemy == nullptr)
            {
                return;
            }

            // Perform attacks
            for (Character *fighter : fighters)
            {
                if (!fighter->isAlive())
                {
                    continue;
                }

                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                if (cowboy != nullptr)
                {
                    cowboy->shoot(lowestHealthEnemy);
                }
                else
                {
                    Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                    if (ninja != nullptr)
                    {
                        if (ninja->distance(lowestHealthEnemy) < 1)
                        {
                            ninja->slash(lowestHealthEnemy);
                        }
                        else
                        {
                            ninja->move(lowestHealthEnemy);
                        }
                    }
                }

                // If the current enemy character has died, break the loop
                // The next round will find the new lowest health enemy
                if (!lowestHealthEnemy->isAlive())
                {
                    break;
                }
            }
        }
    }
}