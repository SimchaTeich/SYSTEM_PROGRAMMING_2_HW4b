#include "Cowboy.hpp"

using namespace ariel;

Cowboy::Cowboy(const string& name, Point location)
    : Character(name, location)
{
    _type = 'C';
    _hitPoints = 110;
    _bullets = 0;
    reload();
};


void Cowboy::shoot(Character *other)
{
    if(isAlive() && hasBullets())
    {
        other->hit(10);
        _bullets--;
    }
};


bool Cowboy::hasBullets() const
{
    return _bullets >= 1;
};


bool Cowboy::hasBoolets() const
{
    return hasBullets();
};


void Cowboy::reload()
{
    _bullets += 6;
};
