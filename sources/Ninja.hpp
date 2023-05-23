#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    protected:
        int _speed;

    public:
        Ninja(const string& name, Point location);

        /*
        * Receives a pointer to the enemy and walks towards the enemy.
        * The ninja walks a distance less than or equal to her speed
        */
        void move(Character *other);

        /*
        * Receives a pointer to the enemy.
        * If I am alive and the enemy is less than 1 meter away
        * I will deal 40 "hit points" damage to the enemy.
        * Otherwise, no damage will be done to the enemy.
        */
        void slash(Character *other);
    };
};


#endif // !NINJA_HPP