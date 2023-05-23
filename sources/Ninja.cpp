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
    double distaneToMove = distance(other) > _speed ? _speed : distance(other);
    _location = Point::moveTowards(_location, other->getLocation(), distaneToMove);
};


void Ninja::slash(Character *other)
{
    if(this == other) throw std::runtime_error("No self harm");

    if(!isAlive()) throw std::runtime_error("Im dead...");
    if(!other->isAlive()) throw std::runtime_error("Cant slash a dead enemy!");

    if(distance(other) < 1)
    {
        other->hit(40);
    }
};
