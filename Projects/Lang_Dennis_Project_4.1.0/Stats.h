/* 
 * File:   Stats.h
 * Author: Dennis Lang
 * Created on July 30, 2020, 11:30 PM
 */

#ifndef STATS_H
#define STATS_H
#include "Player.h"

//declares instance of Player in scope
class Player;

//friends allow access to privates/protected
//class is derived by Player with ints for wins/losses
class Stats {
protected:
    friend class Player;
    unsigned int winTot = 0,
                 lossTot = 0;
};  

#endif /* STATS_H */

