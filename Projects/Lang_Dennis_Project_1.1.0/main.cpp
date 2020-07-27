/* 
 * File: Connect Four Project
 * Author: Dennis Lang
 * Created on July 9, 2020, 11:13 PM
 */

#include "Stats.h"
#include "Player.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    Player play;
    Player arr[2]; //create 2 players, p1 and p2
    char sixBy7[7][7]; //allow buffer for arr[1], '\n'?
    cout << "Welcome to Connect Four!" << endl;
    play.getSide(arr);
    play.confirm(arr); 
    play.gmeBord(sixBy7);
    play.playGme(sixBy7, arr);
    return 0;
}