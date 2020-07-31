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
    char XorO;
    static int gmCount;
    //aggregation of class Stats
    Stats getTots;
    string titleF[12] = {"Queen ", "Lady ", "Princess ",
                         "Doctor ", "Dame ", "Sorceress ", 
                         "Knight ", "Jester ", "Chef ", 
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
                         " would have been better off facing the Dragon.",
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
    Player() {
        gmCount++;
    }
    //inline, overloaded constructor
    Player (string x, char e) {
        name = x;
        XorO = e;
    }
    int gtGmCnt() const {
        return gmCount;
    }
};

int Player::gmCount = 0;

void Player::getSide(Player *ptr){
//get each side and then confirm();
    srand (time(NULL));
    string s1, s2, roy1, roy2;
    char sel;
    cout << "Player X will go 1st, enter your name: ";
    getline (cin,s1);
    cout << "Do you wish to be male, female, or neither? Key in (m/f/other): ";
    cin >> sel;
    if(sel == 'f'){
        roy1 = titleF[rand()%12] + s1 + " the " + adjF[rand()%13];
    }
    if(sel == 'm'){
        roy1 = titleM[rand()%12] + s1 + " the " + adjM[rand()%13];
    }else if (sel != 'm' && sel != 'f'){
        roy1 = titleM[rand()%5] + s1 + " the " + adjM[rand()%10];
    }
    ptr[PLAYER1].name = roy1;
    cin.ignore();
    cout << "Player O will go 2nd, enter your name: ";
    getline (cin,s2);
    cout << "Do you wish to be male, female, or neither? Key in (m/f/other): ";
    cin >> sel;
    if(sel == 'f'){
        roy2 = titleF[rand()%12] + s2 + " the " + adjF[rand()%13];
    }
    if(sel == 'm'){
        roy2 = titleM[rand()%12] + s2 + " the " +adjM[rand()%13];
    }else if (sel != 'm' && sel != 'f'){
        roy2 = titlGn[rand()%5] + s2 + " the " + adjM[rand()%10];
    }
    ptr[PLAYER2].name = roy2;
    ptr[PLAYER1].XorO = 'X';
    ptr[PLAYER2].XorO = 'O';
    for(int i=0; i<2; i++){
    cout << ptr[i].name << " will be the " 
         << ptr[i].XorO << "'s." << endl;
    }
}

void Player::confirm(Player *ptr){
    char conf;
    cout << "Does this look good? (y/n)" << endl;
    cin >> conf;
    if(conf == 'n'){   //allows users to re-decide who goes first
        cout << "Please try again." << endl;
        cin.ignore();
        getSide(ptr);
        confirm(ptr);
    }else if(conf != 'y' && conf != 'n'){
        throw Xcption();
    }else{
        cout << endl;
    }
    cout << "Win the most number of matches to claim victory!" << endl;
    cout << "Connect four tokens in any direction to win the match."<< endl;
    cout << "Enter any non-number to surrender the match." << endl;
}

int Player::takeTrn( char sixBy7[6][7], Player current ){
//switch between players
//exception handling to not enter integer
//enter a non-numerical value to quit
    int slction = 0;
    if(cin.fail()){
        cout << "Exit game" << endl;
        exit(0);
    } 
    do{
        if(!cin.fail()){
            cout << current.name << "'s Turn ";
            cout << "Enter a number (1-7): ";
            try{
            cin >> slction;
            }
            catch(Player::Xcption){
                cout << "Try Again:" << endl;
                cin >> slction;
            }
            if(!cin.fail()){
                while (sixBy7[1][slction] != ' '){
                    cout << "Row Full, Choose 1-7: ";
                    cin >> slction;
                }
            }else{
                throw Xcption();
            }
    }else{
        break;
    }
    }while (slction < 1 || slction > 7);

    return slction;
}
void Player::isValid (char sixBy7[6][7], Player current, int slction){
//checks and prints value per each 2D array value
    int SIZE, getTurn = 0;
    SIZE = getTurn + 6;
    while (getTurn != 1){
        if (sixBy7[SIZE][slction] != 'X' 
            && sixBy7[SIZE][slction] != 'O'){
            sixBy7[SIZE][slction] = current.XorO;
            getTurn = 1;
        }else{
            --SIZE;
        }
    }
}
int Player::isFour (char sixBy7[6][7], Player current){
//check each position in the array of chars
//if X's or O's are 4 in a row in any direction
//print out win = 1 to the playGame function to proceed
    int win = 0;
    char c = current.XorO;
    for (int i = 1; i < 4; i++){
        for (int j = 1; j <= 7; j++){
            if (sixBy7[i][j] == sixBy7[i + 1][j] &&
                sixBy7[i][j] == sixBy7[i + 2][j] &&
                sixBy7[i][j] == sixBy7[i + 3][j] &&
                sixBy7[i][j] == c){
                win = 1;
            }
        }
    }
    for (int i = 1; i < 7; i++){
        for (int j = 1; j <= 4; j++){
            if (sixBy7[i][j] == sixBy7[i][j + 1] &&
                sixBy7[i][j] == sixBy7[i][j + 2] &&
                sixBy7[i][j] == sixBy7[i][j + 3] &&
                sixBy7[i][j] == c){
                win = 1;
            }
        }
    }
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 4; j++){
            if (sixBy7[i][j] == sixBy7[i + 1][j + 1] &&
                sixBy7[i][j] == sixBy7[i + 2][j + 2] &&
                sixBy7[i][j] == sixBy7[i + 3][j + 3] &&
                sixBy7[i][j] == c){
                win = 1;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j < 6; j++){
            if (sixBy7[i][j] == sixBy7[i + 1][j - 1] &&
                sixBy7[i][j] == sixBy7[i + 2][j - 2] &&
                sixBy7[i][j] == sixBy7[i + 3][j - 3] &&
                sixBy7[i][j] == c){
                win = 1;
            }
        }
    }
   return win;
}

void Player::gmeBord (char sixBy7[6][7]){
//print game board after each turn, verify is isFour, create array of 1-7 to label
    int array[6];
    for(int i=1; i<=6; i++){
        for(int j=1; j<=7; j++){
            if(sixBy7[i][j] != 'O' && sixBy7[i][j] != 'X'){
                sixBy7[i][j] = ' ';   
            }
            cout << sixBy7[i][j] << "|";
        }
        cout << endl;
    }

    for(int i=1; i<=7; i++){
        array[i] = i;
        cout << array[i] <<  " ";
    }
    cout << endl;
}

int Player::isFilld(char sixBy7[6][7]){
    //checks the array column by column to see if full board
    int filled = 0;
    for(int j = 1; j <= 7; j++){
        if(sixBy7[1][j] != ' '){
            ++filled;
        }
    }
    return filled;
}

char Player::reset (char sixBy7[6][7], fstream &file, Player *ptr){
//verify 'y' or 'n' for replay  
    srand (time(NULL));
    float winPerc;
    int maxWin, gmTot;
    Player play;
    int num = 6;
    int egg = 5 - (play.gtGmCnt() - 3);
    char yOrN;
    if(yOrN != 'n'){
        EastEgg line(egg);
        display(line);
        if(egg == 0){
            cout << "You've unlocked the Easter Egg!"<<endl;
            dynamic(num);
        }
        cout << "Play again? (y/n) " << endl;
        cin  >> yOrN;
        if (yOrN == 'y'){
            for(int i=1; i<=6; i++){
                for(int j = 1; j <= 7; j++){
                    sixBy7[i][j] = ' ';  //clear sixBy7
                }
            }
            gmeBord(sixBy7);
        }else if (yOrN == 'n'){
            if((egg) == 1){
                cout << "Good Game!" << endl;
            }else if((egg) != 1){
                cout << "Good Games!" << endl;
            }
            maxWin=GetMax<int>(ptr[PLAYER1].getTots.winTot,
                    ptr[PLAYER2].getTots.winTot);
            winPerc = (float)maxWin/(float)(5-egg);
            winPerc *= 100;
            if(ptr[PLAYER1].getTots.winTot > ptr[PLAYER2].getTots.winTot){
                cout << ptr[PLAYER1].name;
                cout << " has been crowned ruler of all the land with " << endl;
                if(maxWin == 1){
                    cout << maxWin << " game won";
                }else if (maxWin > 1){
                    cout << maxWin << " games won";
                }
                cout << " and a win/loss percentage of "
                     << winPerc << "%.";
            }else if((ptr[PLAYER2].getTots.winTot > ptr[PLAYER1].getTots.winTot)){
                cout << ptr[PLAYER2].name;
                cout << " has been crowned ruler of all the land with " << endl; 
                if(maxWin == 1){
                    cout << maxWin << " game won";
                }else if (maxWin > 1){
                    cout << maxWin << " games won";
                }
                cout << " and a win/loss percentage of "
                     << winPerc << "%.";
            }else if (ptr[PLAYER2].getTots.winTot = ptr[PLAYER1].getTots.winTot){
                cout << "Both Players Tied." << endl;
                cout << tieMsg[rand()%6];
            }
            cout << endl << "Stats for Nerds: " << endl;
            gmTot = ptr[PLAYER1].getTots.winTot + ptr[PLAYER2].getTots.winTot;
            cout << "Number of games played this session: " << gmTot;
            play = gtPlaDat(file);
            cout << "Goodbye.";
            exit(0);
        }else{
            throw Xcption();
            yOrN = reset(sixBy7, file, ptr);
        }
    }
    return yOrN;
}

int *Player::dynamic(int num){
//dynamic memory test
    int *array = nullptr;
    if(num <= 0)
        return nullptr;
    array = new int[num]; //allocate dynamic
    srand(time(0));
    cout << "You get some winning lottery numbers!: ";
    for(int i =0; i < num; i++){
        array[i] = rand()%47;
        cout << array[i] << " ";
    }
    cout << endl << "These will surely help you escape serfdom." << endl;
    return array;
}

void Player::playGme (char sixBy7[6][7], Player *ptr){
    int slction, isWin, filled = 0;
    char playAgn;
    ofstream wf("score.bin", ios::in | ios::out | ios::binary); 
    //score.bin must exist
    fstream file;
    string str;
    //write to file the win and loss totals, increment and write each time
    //loop depending on the play again variable returned by reset() after completion
    cout << "Rule: enter any non-integer to concede." << endl;
    while (playAgn != 'n'){
        for(int i=0; i<=1; i++){
            try{
                slction = takeTrn(sixBy7, ptr[i]);
            }
            catch(Player::Xcption){
                cout << "Bad Input" << endl;
            }
            isValid(sixBy7, ptr[i], slction);
            gmeBord(sixBy7);
            isWin = isFour(sixBy7, ptr[i]);
            if(isWin == 1){
                ptr[i].getTots.winTot++;
                cout << ptr[i].name << " has declared victory!" << endl;
                if(i == PLAYER1){
                    ptr[PLAYER2].getTots.lossTot++;
                    str = sntStrt[rand()%4] + ptr[PLAYER2].name + lossMsg[rand()%5];
                    cout << str << endl;
                }else{
                    ptr[PLAYER1].getTots.lossTot++;
                    str = sntStrt[rand()%4] + ptr[PLAYER1].name + lossMsg[rand()%5];
                    cout << str << endl;
                }
                for(int i=0; i<2; i++){
                    wf.write((char *) &ptr[i], sizeof(&ptr[i]));
                }
                for(int i=0; i<2; i++) {
                    cout << ptr[i].name << " has won "
                         << setw(2)   
                         << ptr[i].getTots.winTot 
                         << " time(s) and lost " 
                         << setw(2)
                         << ptr[i].getTots.lossTot 
                         << " time(s)."<< endl;
                }
                wf.close();
                playAgn = reset(sixBy7, file, ptr);                   
            }
            filled = isFilld(sixBy7);
            if (filled == 7){
                cout << "Tie game." << endl;
                playAgn = reset(sixBy7, file, ptr);
            }
        }
    }
}

Player Player::gtPlaDat(fstream &file){
    char ch[20];
    ofstream outFile("out.txt");
    file.open("test.txt", ios::in);
    file.seekg(11L, ios::beg); //ignore programmer's score
    cout << endl << "Previous win streaks: " << endl;
    while (file >> ch[20]){
        outFile.put(ch[20]);
        cout << ch[20];
    }
    file.close();
    cout << endl << "Here's what the empty structure looks like:" << endl;
    Player temp("Empty", 'E');
    for(int i = 0; i < 2; i++){
        cout << "P" << i+1 << " = " << temp.name << endl;
        cout << "Game piece = " << temp.XorO << endl;
    }
    return temp;
}

#endif /* PLAYER_H */

