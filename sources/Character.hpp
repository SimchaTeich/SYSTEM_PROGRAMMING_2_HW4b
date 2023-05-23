#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string.h>
#include "Point.hpp"

using std::string;
using std::cout;
using std::endl;


namespace ariel
{
    class Character
    {
    private:
        const string& _name;
        bool _inTeam;

    protected:
        Point _location;
        int _hitPoints;
        char _type; // 'C' or 'N'

    public:
        Character(const string& name, Point location);

        /*
        * check if Character is alive, by checking if
        * there is for at least one hit point was left.
        */
        bool isAlive() const;
        
        /*
        * returns the distance between this
        * Character to other Character.
        */
        double distance(Character *other) const;
        
        /*
        * douwn number of points from hit points left.
        */
        void hit(const int& points);

        /* getters */
        string getName() const;
        Point getLocation() const;
        char getType() const;
        bool inTeam() const;

        /* 
        * prints some details about the Character.
        */
        string print() const;

        /* updates that player is now belongs to team.
        *  actualy, just turn on the _inTeam flag.
        */
        void insertedToTeam();
    };
};


#endif // !CHARACTER_HPP