#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

#define MAX_PLAYERS 10

namespace ariel
{
    class Team
    {
    private:
        Cowboy *_cowboys[MAX_PLAYERS];
        Ninja *_ninjas[MAX_PLAYERS];
        int _amountOfCowboys;
        int _amountOfNinjas;
        Character *_captain;

        /*
        returns pointer to the closest character in team, to
        player.
        */
        static Character *closestToPlayer(Character *player, Team* team);

    public:
        Team(Character *captain);
        ~Team(); // need to define all destructors of all as virtual.

        /*
        * append new player into the team
        * by type, if we still have less then
        * MAX_PLAYERS players.. else, raise exception.
        */
        void add(Character *player);

        /*
        * full explanation in README.md
        */
        void attack(Team *enemies);

        /*
        * Returns the number of players in
        * the team that still alive..
        */
        int stillAlive() const;

        /*
        * print details about the players.
        * full explanation in README.md
        */
        string print() const;

        /*
        returns amount of cowboys (alive or not..)
        */
        int amountOfCowboys() const;

        /*
        returns amount of Ninjas (alive or not..)
        */
        int amountOfNinjas() const;

        /*
        Returns the captain of the team
        */
        Character *captain() const;

        /*
        Returns pointer to cowboys at some index
        */
        Cowboy *CowboyAt(int index) const;

        /*
        Returns pointer to Ninjs at some index
        */
        Ninja *NinjaAt(int index) const;


    };
};

#endif // !TEAM_HPP 