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
    if(this == other) throw std::runtime_error("No self harm");

    if(!isAlive()) throw std::runtime_error("Im dead...");
    if(!other->isAlive()) throw std::runtime_error("Cant slash a dead enemy!");

    if(hasBullets())
    {
        other->hit(10);
        _bullets--;
    }
};


bool Cowboy::hasBullets() const
{
    return _bullets >= 1;
};


bool Cowboy::hasboolets() const
{
    return hasBullets();
};


void Cowboy::reload()
{
    if(!isAlive()) throw std::runtime_error("Dead cowboy can not reload");
    _bullets = 6;
};
