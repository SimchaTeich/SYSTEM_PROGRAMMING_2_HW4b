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
    // TODO
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

    //return stillAlives;
    return 0; // Just for now
};


string Team::print() const
{
    string teamString;
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

    return teamString;
};
