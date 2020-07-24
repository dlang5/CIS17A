#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Stats.h"

class Player{
public:
    std::string name;
    char XorO;
    struct Stats getTots;
};

#endif /* PLAYER_H */

