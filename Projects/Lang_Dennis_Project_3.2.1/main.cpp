/* 
 * File: Connect Four Project
 * Author: Dennis Lang
 * Created on July 9, 2020, 11:13 PM
 */

#include "Player.h"

void roylDec();
void wavyLn();

int main(int argc, char** argv) {
    Player play;
    Player arr[2]; //create 2 players, p1 and p2
    char sixBy7[7][7]; //allow buffer for arr[1], '\n'?
    roylDec();
    play.getSide(arr);
    try{
        play.confirm(arr); 
    }
    catch(Player::Xcption){
        cout << "Bad Input" << endl;
        cout << "Win the most number of matches to claim victory!" << endl;
        cout << "Connect four tokens in any direction to win the match."<< endl;
        cout << "Enter any non-number to surrender the match." << endl;
    }
    play.gmeBord(sixBy7);
    try{
        play.playGme(sixBy7, arr); 
    }
    catch(Player::Xcption){
        cout << "Bad Input" << endl;
        if((play.gtGmCnt() - 3) == 1){
            cout << "Good Game!" << endl;
        }else if((play.gtGmCnt() - 3) != 1){
            cout << "Good Games!" << endl;
        }
        cout << "Number of games played this session: "
             << play.gtGmCnt() - 3 << endl;
        cout << "Goodbye.";
        exit(0);
    }
    return 0;
}

void roylDec(){
    wavyLn();
    cout << endl << "~~~~~Welcome to Royal Connect Four!~~~~~" << endl;
    wavyLn();
    cout << R"(         *                    *
        ***                 * | *
      * * * *              * \|/ *
 * * * \|O|/ * * *    * * * \|X|/ * * *
  \o\o\o|O|o/o/o/      \x\x\x|X|x/x/x/
  (<><><>O<><><>)      (<><><>0<><><>)     
  '============='      '=============')" << endl;
    wavyLn();
    cout<<endl;
    wavyLn();
    cout<<endl;
    cout << "Play a rousing match or two of Connect 4 \n"
            "  for the right to sit on the throne!" << endl;
}

void wavyLn(){
    for(int i = 0; i < 40; i++){
        cout << "~";
    }
}