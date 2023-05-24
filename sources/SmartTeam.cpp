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
        // Similar basic checks as in Team class
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

        // Perform attacks
        for (Character *fighter : fighters)
        {
            if (!fighter->isAlive())
            {
                continue;
            }

            Ninja *ninja = dynamic_cast<Ninja *>(fighter);
            if (ninja != nullptr)
            {
                // find closest enemy to attack with each ninja
                Character *closestToAttackByNinja = nullptr;
                for (Character *enemy : enemy_team->getFigthers())
                {
                    if (enemy->isAlive())
                    {
                        if (ninja->distance(enemy) < 1)
                        {
                            closestToAttackByNinja = enemy;
                            break; // dont need to search anymore, found close one
                        }
                    }
                }// after loop or after break

                if (closestToAttackByNinja != nullptr)
                {
                    ninja->slash(closestToAttackByNinja);
                }
                else
                {
                    // find the closest enemy to move to
                    Character *closestToNinja = nullptr;
                    double distance = 0;
                    double min_distance = numeric_limits<int>::max();
                    for (Character *enemy : enemy_team->getFigthers())
                    {
                        if (enemy->isAlive())
                        {
                            distance = ninja->distance(enemy);
                            if (distance < min_distance)
                            {
                                closestToNinja = enemy;
                                min_distance = distance;
                            }
                        }
                    }
                    ninja->move(closestToNinja);
                }
            }
            else
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                if (cowboy != nullptr)
                {
                    // Attack the enemy with the lowest health
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

                    cowboy->shoot(lowestHealthEnemy);
                }
            }

            if (enemy_team->stillAlive() == 0)
            {
                return; // no Living enemies to attack
            }
        }
    }
}