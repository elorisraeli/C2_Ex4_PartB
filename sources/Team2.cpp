#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *pLeaderT2) : Team(pLeaderT2)
    {
    }

    Team2::~Team2()
    {
    }

    void Team2::attack(Team *enemy_team)
    {
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

        Character *victim = nullptr;
        double minDistance = numeric_limits<double>::max();

        // Find the living enemy character closest to the leader
        for (Character *enemy : enemy_team->getFigthers())
        {
            if (enemy->isAlive())
            {
                double distance = leader->distance(enemy);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    victim = enemy;
                }
            }
        }

        if (victim == nullptr)
        {
            throw runtime_error("Not alive victim, All dead");
            return; // No living enemy character found, the attack ends
        }

        // Perform attacks
        for (Character *fighter : fighters)
        {
            if (!fighter->isAlive())
            {
                continue;
            }
            if (fighter->isNinja())
            {
                Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                if (ninja != nullptr)
                {
                    if (ninja->distance(victim) < 1)
                    {
                        ninja->slash(victim);
                    }
                    else
                    {
                        ninja->move(victim);
                    }
                }
            }
            else
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                if (cowboy != nullptr)
                {
                    cowboy->shoot(victim);
                }
            }

            if (!victim->isAlive())
            {
                // Find a new victim
                victim = nullptr;
                minDistance = numeric_limits<double>::max();

                for (Character *enemy : enemy_team->getFigthers())
                {
                    if (enemy->isAlive())
                    {
                        double distance = leader->distance(enemy);
                        if (distance < minDistance)
                        {
                            minDistance = distance;
                            victim = enemy;
                        }
                    }
                }

                if (victim == nullptr)
                {
                    return; // No living enemy character found, the attack ends
                }
            }
        }
    }
}