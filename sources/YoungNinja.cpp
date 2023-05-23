#include "YoungNinja.hpp"

using namespace ariel;

YoungNinja::YoungNinja(const string& name, Point location)
    :Ninja(name, location)
{
    _hitPoints = 100;
    _speed = 14;
};
