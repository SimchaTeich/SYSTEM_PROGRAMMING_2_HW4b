#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int _bullets;

    public:
        Cowboy(const string& name, Point location);

        /*
        * If we are alive, and if we have bullets left,
        * we subtract 10 hit points from the enemy and lose one bullet.
        * Otherwise, nothing will happen to the enemy.
        */
        void shoot(Character *other);

        /*
        * Returns true if we have at least one more bullet
        */
        bool hasBullets() const;
        bool hasBoolets() const; // same as the abouv.
                                // but unfortantly this is
                                // a mistake of how created this
                                // taks. I have to implement it
                                // for the automatic testers...


        /*
        * Loads the gun with six new bullets.
        */
        void reload();
    };
};


#endif // !COWBOY_HPP
