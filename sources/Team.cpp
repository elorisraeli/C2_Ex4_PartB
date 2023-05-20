#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

#include "Team.hpp"

using namespace std;

namespace ariel
{
    Team::Team(Character *pLeader)
    {
        if (pLeader->getIsInTeam())
        {
            throw runtime_error("Leader is already in a team");
        }
        pLeader->setIsInTeam(true);
        leader = pLeader;
        fighters.push_back(leader);
    }

    Team::~Team()
    {
        for (Character *fighter : fighters)
        {
            delete fighter;
        }
        fighters.clear();
    }

    bool Team::isMember(Character *character)
    {
        for (Character *fighter : fighters)
        {
            if (fighter == character)
            {
                return true;
            }
        }
        return false;
    }

    void Team::add(Character *fighter_to_add)
    {
        if (leader == fighter_to_add)
        {
            throw runtime_error("Cannot add the leader");
        }

        if (fighters.size() >= 10)
        {
            throw runtime_error("Team is full (10 figthers), Cannot add.");
        }

        if (fighter_to_add->getIsInTeam())
        {
            throw runtime_error("Player is already in a team");
        }

        fighter_to_add->setIsInTeam(true);
        fighters.push_back(fighter_to_add);
    }

    void Team::attack(Team *enemy_team)
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
        for (Character *enemy : enemy_team->fighters)
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

            Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
            if (cowboy != nullptr)
            {
                cowboy->shoot(victim);
            }
            else
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

            if (!victim->isAlive())
            {
                // Find a new victim
                victim = nullptr;
                minDistance = numeric_limits<double>::max();

                for (Character *enemy : enemy_team->fighters)
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

    int Team::stillAlive()
    {
        int count = 0;
        for (auto *fighter : fighters)
        {
            if (fighter->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void Team::print()
    {
        cout << "Team Leader: " << leader->getName() << endl;
        cout << "Team Members: " << endl;
        for (Character *fighter : fighters)
        {
            cout << fighter->print() << endl;
        }
    }

    void Team::remove(Character *fighter_to_remove)
    {
        for (auto it = fighters.begin(); it != fighters.end(); ++it)
        {
            if (*it == fighter_to_remove)
            {
                fighters.erase(it);
                break;
            }
        }
    }

    Character *Team::getLeader()
    {
        return leader;
    }

    size_t Team::size()
    {
        return fighters.size();
    }

    vector<Character *> Team::getFigthers()
    {
        return fighters;
    }
}