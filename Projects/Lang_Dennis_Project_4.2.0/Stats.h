/* 
 * File:   Stats.h
 * Author: Dennis Lang
 * Created on July 30, 2020, 11:30 PM
 * This header file creates the Stats class
 * that is inherited by the Player class.
 * An instance of Player is shown at the beginning
 * for scope purposes, so "Player.h" is included.
 */

#ifndef STATS_H
#define STATS_H
#include "Player.h"

//declares instance of Player in scope
//is necessary to allow the friend class player
class Player;

//friends allow access to privates/protected
//class is derived by Player with ints for wins/losses
//unsigned int as the player count always goes up from 0
//protected allows access in between that of public/private
class Stats {
protected:
    friend class Player;
    unsigned int winTot = 0,
                 lossTot = 0;
};  

#endif /* STATS_H */

