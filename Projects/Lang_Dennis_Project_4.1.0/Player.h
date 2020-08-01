/* 
 * File:   Player.h
 * Author: Dennis Lang
 * Created on July 25, 2020, 8:07 AM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "EastEgg.h"
#include "Stats.h"

//enumerated p1 = 0; p2 = 1
enum {PLAYER1, PLAYER2};

//derived from Stats
//includes player name string, friend class/function
//titles for appending before and after name
//messages upon loss and tied matches
//contains eXception class to throw
//keeps a count of games played w/ gameCount
//inline and prototypes of functions
//overloaded operators x4 for comparing names, winTots
//  as well as appending strings
//abstract due to virtual function for "secret hidden" Easter Egg
//contains function for vector also as well as overloaded
// constructor that is primarily used to increment gameCount
class Player: public Stats{
private:
    friend class Stats;
    string name, ogName;
    char XorO, ss[30];
    static int gmCount;
    //aggregation of class Stats
    Stats Q;
    string titleF[15] = {"Queen ", "Lady ", "Princess ",
                         "Doctor ", "Dame ", "Sorceress ", 
                         "Knight ", "Maiden ", "Chef ", 
                         "Her Majesty ", "Madame ", "Peasant ",
                         "Baroness ", "Duchess ", "Countess "};
    string titleM[15] = {"Doctor ", "Peasant ", "Knight ",
                         "Chef ", "Jester ", "Master "
                         "Sir ", "Ser ", "Prince ", "King ",
                         "His Majesty ", "Sorcerer ",
                         "Baron ", "Duke ", "Count "};
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
    string lossMsg[8] = {" should have invested in their uncle's fiefdom.",
                         " would have been better off fighting the Dragon.",
                         " has lost their last shred of dignity.",
                         " needs to reconsider their life choices.",
                         " should have worn the brown pants instead.",
                         " doesn't abide by your Earthly definition of losing!",
                         " says that this was merely a scratch!",
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
    Player gtPlaDat(fstream &file);
    Player() {gmCount++;}
    int gtGmCnt() const 
    {
        return gmCount;
    }
    //inline, overloaded constructor
    Player (string x, char e)
    {
        name = x;
        XorO = e;
    }
    friend bool operator== (Player &p1, Player &p2)
    {
        return (p1.name == p2.name);
    }
    friend void operator+ (Player &p1)
    {
        p1.name = "Golden " + p1.name;
    }
    friend bool operator> (Player &p1, Player &p2)
    {
        return (p1.winTot > p2.winTot);
    }
    friend bool operator&& (Player &p1, Player &p2)
    {
        return (p1.winTot = p2.winTot);
    }
    virtual int *dynamic(int num);
    void vecStuf();
};

//secret 20% rand chance to output even more useless easter egg
//copy of *dynamic from before as a usage of virtual abstract Player
class loserP: public Player{
public:
    int *dynamic(int num)
    {
        int *array = nullptr;
        if(num <= 0)
            return nullptr;
        array = new int[num]; //allocate dynamic
        srand(time(0));
        cout << "Here's some losing lottery numbers: ";
        for(int i =0; i < num; i++)
        {
            array[i] = rand()%1+69;
            cout << array[i] << " ";
        }
        cout << endl << "...sorry about that." << endl;
        return array;
    }
};

//set gmCount to 0
int Player::gmCount = 0;

//rules of the game with a few vectors
//shows vertical, horizontal and vertical win conditions
//for new players, and uses vector STL libraries to show
//push_back as pop isn't in <vector>, but in <list>
void Player::vecStuf(){
    vector<int> vec1,vec2,vec3;
    cout << "How to Play:" <<endl;
    vec1.push_back(0);
    for (int i = 2; i <= 7; i++) 
    {
        vec1.push_back(i); 
    }
    for (int i = 1; i <= 7; i++) 
    {
        vec3.push_back(i); 
    }
    cout << setw(7) << " "; 
    replace (vec1.begin(), vec1.end(), 7, 0);
    for (auto i = vec1.begin(); i != vec1.end(); ++i)
    {
        cout << *i << " "; 
    }
    cout << "<- win";
    cout << endl << setw(7) << " ";
    replace (vec1.begin()+1, vec1.end(), 0, 7);
    replace (vec1.begin(), vec1.end(), 6, 0);
    for (auto i = vec1.begin(); i != vec1.end(); ++i)
    {
        cout << *i << " "; 
    }
    cout << endl << setw(7) << " ";
    replace (vec1.begin()+1, vec1.end(), 0, 6);
    replace (vec1.begin(), vec1.end(), 5, 0);
    for (auto i = vec1.begin(); i != vec1.end(); ++i)
    {
        cout << *i << " "; 
    }
    cout << endl << setw(7) << "win -> ";
    replace (vec1.begin()+1, vec1.end(), 0, 5);
    replace (vec1.begin(), vec1.end(), 4, 0);
    for (auto i = vec1.cbegin(); i != vec1.cend(); ++i)
    {
        cout << *i << " "; 
    }
    cout << endl << setw(7) << " ";  
    for (auto i = vec3.cbegin(); i != vec3.cend(); ++i)
    {
        cout << *i << " "; 
    }
    cout << endl << setw(7) << "win -> "; 
    for (int i = 1; i <= 4; i++) 
    {
        vec2.push_back(0); 
    }
    for (int i = 5; i <= 7; i++) 
    {
        vec2.push_back(i); 
    }
    for (auto i = vec2.begin(); i != vec2.end(); ++i)
    {
        cout << *i << " "; 
    }
    cout<<endl;
}

#endif /* PLAYER_H */

