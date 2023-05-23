#include "Team.hpp"

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
    if(player->inTeam()) throw "Cannot add player to group!";

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
    if(!_captain->isAlive())
    {
        _captain = Team::closestToPlayer(_captain, this);
    }
    else
    {
        Character *victim = Team::closestToPlayer(_captain, enemies);

        // attack by cowboys
        for(int i = 0; i < _amountOfCowboys; i++)
        {
            if(_cowboys[i]->hasBullets()) _cowboys[i]->shoot(victim);
            else _cowboys[i]->reload();
        }

        // attack by ninjas
        for(int i = 0; i < _amountOfNinjas; i++)
        {
           if(_ninjas[i]->distance(victim) < 1) _ninjas[i]->slash(victim);
           else _ninjas[i]->move(victim);
        }
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
    Character *closest = team->captain();
    int amountOfCowboys = team->amountOfCowboys();
    int amountOfNinjas = team->amountOfNinjas();
    double distance = INT16_MAX;
    
    // Go over cowboys
    for(int i = 0; i < amountOfCowboys; i++)
    {
        if(player != team->CowboyAt(i) &&
           team->CowboyAt(i)->isAlive() &&
           player->distance(team->CowboyAt(i)) < distance)
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
           player->distance(team->NinjaAt(i)) < distance)
        {
            closest = team->NinjaAt(i);
            distance = player->distance(closest);
        }
    }

    return closest;
}