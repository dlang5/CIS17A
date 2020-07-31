/* 
 * File:   Player.h
 * Author: Dennis Lang
 * Created on July 25, 2020, 8:07 AM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "EastEgg.h"
#include "Stats.h"

enum {PLAYER1, PLAYER2};

class Player {
private:
    string name;
    char XorO, ss[30];
    static int gmCount;
    //aggregation of class Stats
    Stats getTots;
    string titleF[12] = {"Queen ", "Lady ", "Princess ",
                         "Doctor ", "Dame ", "Sorceress ", 
                         "Knight ", "Maiden ", "Chef ", 
                         "Her Majesty ", "Madame ", "Peasant "};
    string titleM[12]  = {"Doctor ", "Peasant ", "Knight ",
                         "Chef ", "Jester ", "Master "
                         "Sir ", "Ser ", "Prince ", "King "
                         "His Majesty ", "Sorcerer "};
    string adjF[13]   = {"Bold", "Brave", "Wise", "Large",
                         "Strong", "Meek", "Lioness",
                         "Mischievous", "Small", "Clumsy",
                         "Dragoness", "Lonely", "Beautiful"};
    string adjM[13]   = {"Bold", "Brave", "Wise", "Large",
                         "Strong", "Meek", "Mischievous", 
                         "Small", "Clumsy", "Lonely",
                         "Dragon", "Lion", "Oafish"};
    string tieMsg[6]  = {"Fight to the Death to determine who will Rule.",
                         "Dost thou wish to Joust instead?",
                         "Flip a royal Sixpence to settle the Draw.",
                         "Methinks a trial by fire is in order.",
                         "Only Merlin could have predicted this.",
                         "*Sigh* Now Prince Joffrey gets to be king."};
    string lossMsg[5] = {" should have invested in their uncle's fiefdom.",
                         " would have been better off fighting the Dragon.",
                         " has lost their last shred of dignity.",
                         " needs to reconsider their life choices.",
                         " has had a virtual chamber pot dumped upon them.",};
    string sntStrt[4] = {"Mayhaps ", "Perhaps ", "Verily, ", "Prithee, "};
public:
    class Xcption{};
    char reset (char sixBy7[6][7], fstream &file, Player *ptr);
    int isFilld(char sixBy7[6][7]);
    int isFour (char sixBy7[6][7], Player current);
    int takeTrn(char sixBy7[6][7], Player current);
    void confirm(Player *ptr);
    void getSide(Player *ptr);
    void gmeBord (char sixBy7[6][7]);
    void isValid (char sixBy7[6][7], Player current, int slction);
    void playGme (char sixBy7[6][7], Player *ptr);
    int *dynamic(int num);
    Player gtPlaDat(fstream &file);
    Player() {gmCount++;}
    int gtGmCnt() const {return gmCount;}
    //inline, overloaded constructor
    Player (string x, char e) {
        name = x;
        XorO = e;
    }
    virtual void something(){};
    friend bool operator==(Player &p1, Player &p2){
        return (p1.name == p2.name);
    }
};

int Player::gmCount = 0;

#endif /* PLAYER_H */

