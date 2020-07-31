/* 
 * File: Connect Four Project
 * Author: Dennis Lang
 * Created on July 9, 2020, 11:13 PM
 */

#include "Player.h"

int main(int argc, char** argv) {
    Player play;
    Player arr[2]; //create 2 players, p1 and p2
    char sixBy7[7][7]; //allow buffer for arr[1], '\n'?
    cout << "Welcome to Royal Connect Four!" << endl;
    play.getSide(arr);
    try{
        play.confirm(arr); 
    }
    catch(Player::Xcption){
        cout << "Bad Input" << endl;
        cout << "Get ready to play." << endl;
        cout << "Enter any non-number to quit mid-game." << endl;
        cout << "Connect four to win!" << endl;
    }
    play.gmeBord(sixBy7);
    try{
        play.playGme(sixBy7, arr); 
    }
    catch(Player::Xcption){
        cout << "Bad Input" << endl;
        if((play.gtGmCnt() - 3) == 1){
            cout << "Good game!" << endl;
        }else if((play.gtGmCnt() - 3) != 1){
            cout << "Good games!" << endl;
        }
        cout << "Number of games played this session: "
             << play.gtGmCnt() - 3 << endl;
        cout << "Goodbye.";
        exit(0);
    }
    return 0;
}