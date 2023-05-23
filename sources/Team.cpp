#include "Team.hpp"
#include <float.h>

using namespace ariel;


Team::Team(Character *captain)
{
    _captain = captain;
    _amountOfCowboys = 0;
    _amountOfNinjas = 0;
    add(captain);
};


void Team::add(Character *player)
{
    if(player->inTeam()) throw std::runtime_error("Cannot add player to more then one group!");

    if(_amountOfCowboys + _amountOfNinjas < MAX_PLAYERS)
    {
        if(player->getType() == 'C')
        {
            _cowboys[_amountOfCowboys++] = (Cowboy *)player;
        }
        else
        {
            _ninjas[_amountOfNinjas++] = (Ninja *)player;
        }
    }
    else
    {
        throw std::runtime_error("Sorry! group is fully");
    }

    player->insertedToTeam();
};


Team::~Team()
{
    // free memory of Cowboys.
    for(int i = 0; i < _amountOfCowboys; i++)
    {
        delete _cowboys[i];
    }

    // free memory of Ninjas.
    for(int i = 0; i < _amountOfNinjas; i++)
    {
        delete _ninjas[i];
    }
};


void Team::attack(Team *enemies)
{
    if(enemies == nullptr) throw std::invalid_argument("Team to attack is nullptr..");
    if(!this->stillAlive() || !enemies->stillAlive()) throw std::runtime_error("Team to attack is dead..");

    if(!_captain->isAlive())
    {
        _captain = Team::closestToPlayer(_captain, this);
        if(_captain == nullptr) return;
    }
    
    Character *victim = Team::closestToPlayer(_captain, enemies);
    if (victim == nullptr) return;

    // attack by cowboys
    for(int i = 0; i < _amountOfCowboys; i++)
    {
        if(!victim->isAlive()) victim = Team::closestToPlayer(_captain, enemies);
        if (victim == nullptr) return;

        if(_cowboys[i]->isAlive() && _cowboys[i]->hasBullets() && victim->isAlive()) _cowboys[i]->shoot(victim);
        else if (_cowboys[i]->isAlive() && !_cowboys[i]->hasBullets() && victim->isAlive()) _cowboys[i]->reload();
    }

    // attack by ninjas
    for(int i = 0; i < _amountOfNinjas; i++)
    {
        if(!victim->isAlive()) victim = Team::closestToPlayer(_captain, enemies);
        if (victim == nullptr) return;

        if(_ninjas[i]->isAlive() && _ninjas[i]->distance(victim) < 1 && victim->isAlive()) _ninjas[i]->slash(victim);
        else if (_ninjas[i]->isAlive() && _ninjas[i]->distance(victim) >= 1 && victim->isAlive())_ninjas[i]->move(victim);
    }
};


int Team::stillAlive() const
{
    int stillAlives = 0;
    
    for(int i = 0; i < _amountOfCowboys; i++)
    {
        if(_cowboys[i]->isAlive()) stillAlives++;
    }

    for(int i = 0; i < _amountOfNinjas; i++)
    {
       if(_ninjas[i]->isAlive()) stillAlives++;
    }

    return stillAlives;
};


string Team::print() const
{
    string teamString;
    teamString += "Captain name: " + _captain->getName();
    teamString += "\n";

    for(int i = 0; i < _amountOfCowboys; i++)
    {
        teamString +=_cowboys[i]->print();
        teamString += "\n";
    }

    for(int i = 0; i < _amountOfNinjas; i++)
    {
        teamString += _ninjas[i]->print();
        teamString += "\n";
    }

    cout << teamString << endl;
    return teamString;
};


int Team::amountOfCowboys() const
{
    return _amountOfCowboys;
}


int Team::amountOfNinjas() const
{
    return _amountOfNinjas;
}


Character *Team::captain() const
{
    return _captain;
}


Cowboy *Team::CowboyAt(int index) const
{
    return _cowboys[index];
}


Ninja *Team::NinjaAt(int index) const
{
    return _ninjas[index];
}


Character *Team::closestToPlayer(Character *player, Team* team)
{
    Character *closest = nullptr;
    int amountOfCowboys = team->amountOfCowboys();
    int amountOfNinjas = team->amountOfNinjas();
    double distance = DBL_MAX;
    
    // Go over cowboys
    for(int i = 0; i < amountOfCowboys; i++)
    {
        if(player != team->CowboyAt(i) &&
           team->CowboyAt(i)->isAlive() &&
           player->distance(team->CowboyAt(i)) <= distance)
        {
            closest = team->CowboyAt(i);
            distance = player->distance(closest);
        }
    }

    // Go over ninjas
    for(int i = 0; i < amountOfNinjas; i++)
    {
        if(player != team->NinjaAt(i) &&
           team->NinjaAt(i)->isAlive() &&
           player->distance(team->NinjaAt(i)) <= distance)
        {
            closest = team->NinjaAt(i);
            distance = player->distance(closest);
        }
    }
    
    return closest;
}