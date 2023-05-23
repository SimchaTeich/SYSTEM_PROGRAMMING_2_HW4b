#include "OldNinja.hpp"

using namespace ariel;

OldNinja::OldNinja(const string& name, Point location)
    :Ninja(name, location)
{
    _hitPoints = 150;
    _speed = 8;
};
