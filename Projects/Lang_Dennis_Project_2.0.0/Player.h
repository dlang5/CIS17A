/* 
 * File:   Player.h
 * Author: Dennis Lang
 * Created on July 25, 2020, 8:07 AM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

enum {PLAYER1, PLAYER2};

class Player;

class Stats {
//friends allow access to privates
    friend class Player;
    unsigned int winTot = 0,
                 lossTot = 0;
};  

class Player {
private:
    string name;
    char XorO;
    static int gameCnt;
    //aggregation of class Stats
    Stats getTots;
public:
    char reset (char sixBy7[6][7], fstream &file);
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
    Player() {gameCnt++;}
    //inline, overloaded constructor
    Player (string x, char e) {
        name = x;
        XorO = e;
    }
    int gtGmCnt() const {
        return gameCnt;
    }
};

int Player::gameCnt = 0;

void Player::getSide(Player *ptr){
//get each side and then confirm();
    cout << "Player X will go 1st, enter your name: ";
    getline (cin,ptr[PLAYER1].name);
    cout << "Player O will go 2nd, enter your name: ";
    getline (cin,ptr[PLAYER2].name);
    ptr[PLAYER1].XorO = 'X';
    ptr[PLAYER2].XorO = 'O'; //assign X's and O's
    for(int i=0; i<2; i++){
    cout << ptr[i].name << " will be the " 
         << ptr[i].XorO << "'s." << endl;
    }
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
            cin >> slction;
            if(!cin.fail()){
                while (sixBy7[1][slction] != ' '){
                    cout << "Row Full, Choose 1-7: ";
                    cin >> slction;
                }
            }else{
                break;
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

void Player::confirm(Player *ptr){
    char conf;
    cout << "Is this correct (y/n)?" << endl;
    cin >> conf;
    if(conf == 'n'){   //allows users to re-decide who goes first
        cout << "Please try again." << endl;
        cin.ignore();
        getSide(ptr);
        confirm(ptr);
    }else if(conf != 'y' && conf != 'n'){
        confirm(ptr);
    }else{
        cout << endl;
    }
    cout << "Get ready to play." << endl;
    cout << "Enter any non-number to quit mid-game." << endl;
    cout << "Connect four to win!" << endl;
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

char Player::reset (char sixBy7[6][7], fstream &file){
//verify 'y' or 'n' for replay  
    Player play;
    int num = 6;
    char yOrN;
    if(yOrN != 'n'){
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
            cout << "Good game(s)!" << endl;
            cout << "Number of games played this session: "
                 << play.gtGmCnt() - 3;
            play = gtPlaDat(file);
            dynamic(num);
            cout << endl << "Goodbye.";
            exit(0);
        }else{
            yOrN = reset(sixBy7, file);
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
    cout << "Here's some lotto numbers: ";
    for(int i =0; i < num; i++){
        array[i] = rand()%47;
        cout << array[i] << " ";
    }
    return array;
}

void Player::playGme (char sixBy7[6][7], Player *ptr){
    int slction, isWin, filled = 0;
    char playAgn;
    ofstream wf("score.bin", ios::in | ios::out | ios::binary); 
    //score.bin must exist
    fstream file;
    //write to file the win and loss totals, increment and write each time
    //loop depending on the play again variable returned by reset() after completion
    cout << "Rule: enter any non-integer to concede." << endl;
    while (playAgn != 'n'){
        for(int i=0; i<=1; i++){
            slction = takeTrn(sixBy7, ptr[i]);
            isValid(sixBy7,ptr[i], slction);
            gmeBord(sixBy7);
            isWin = isFour(sixBy7, ptr[i]);
            if(isWin == 1){
                ptr[i].getTots.winTot++;
                cout << ptr[i].name << " has won, congrats!" << endl;
                if(i == PLAYER1){
                    ptr[PLAYER2].getTots.lossTot++;
                }else{
                    ptr[PLAYER1].getTots.lossTot++;
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
                playAgn = reset(sixBy7, file);                   
            }
            filled = isFilld(sixBy7);
            if (filled == 7){
                cout << "Tie game." << endl;
                playAgn = reset(sixBy7, file);
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
    cout << endl << "This is the what the empty structure looks like:" << endl;
    Player temp("Empty", 'E');
    for(int i = 0; i < 2; i++){
        cout << "P" << i+1 << " = " << temp.name << endl;
        cout << "Game piece = " << temp.XorO << endl;
    }
    return temp;
}

#endif /* PLAYER_H */

