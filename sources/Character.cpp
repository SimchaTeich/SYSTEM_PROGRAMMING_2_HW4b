#include "Character.hpp"

using namespace ariel;


Character::Character(const string& name, Point location)
    :_name(name), _location(location)
{
    _inTeam = false;
    _hitPoints = 0;
    _type = 0;
};


bool Character::isAlive() const
{
    return _hitPoints >= 1;
};


double Character::distance(Character *other) const
{
    return _location.distance(other->getLocation());
};


void Character::hit(const int& points)
{
    _hitPoints -= points;
};


string Character::getName() const
{
    return _name;
};


Point Character::getLocation() const
{
    return _location;
};


char Character::getType() const
{
    return _type;
};


bool Character::inTeam() const
{
    return _inTeam;
};


string Character::print() const
{
    string characterString;

    characterString += _type;
    if(isAlive())
    {
        characterString += ", " + _name;
        characterString += ", " + std::to_string(_hitPoints);
    }
    else characterString += ", (" + _name + ")";

    characterString += ", " + _location.print();

    return characterString;
};


void Character::insertedToTeam()
{
    _inTeam = true;
};
