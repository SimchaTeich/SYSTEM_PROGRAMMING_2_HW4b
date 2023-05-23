#include "Ninja.hpp"

using namespace ariel;


Ninja::Ninja(const string& name, Point location)
    : Character(name, location)
{
    _type = 'N';
    _speed = 0;
};


void Ninja::move(Character *other)
{
    // move as match you can toward the other.
    int distaneToMove = distance(other) > _speed ? _speed : distance(other);
    _location = Point::moveToWards(_location, other->getLocation(), distaneToMove);
};


void Ninja::slash(Character *other)
{
    if(isAlive() && distance(other) < 1)
    {
        other->hit(40);
    }
};
