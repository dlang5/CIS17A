/* 
 * File:   Stats.h
 * Author: Dennis Lang
 * Created on July 30, 2020, 11:30 PM
 */

#ifndef STATS_H
#define STATS_H
#include "Player.h"

class Player;

class Stats {
//friends allow access to privates
private:
    friend class Player;
    unsigned int winTot = 0,
                 lossTot = 0;
};  

#endif /* STATS_H */

