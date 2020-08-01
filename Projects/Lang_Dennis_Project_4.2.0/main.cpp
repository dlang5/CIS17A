/* 
 * File: Connect Four Project
 * Author: Dennis Lang
 * Created on July 9, 2020, 11:13 PM
 * Connect Four is a game played on a vertical game board that 
 * is six by seven units large. The game is
 * designed for two players, and the objective is for one player 
 * to connect four of their game pieces either
 * vertically, horizontally, or diagonally before the opponent is 
 * able to, and before the game board fills up
 * entirely with pieces. After choosing which player goes first, 
 * each player drops a game piece (red or black
 * in the physical game, ‘X’ or “O” in my game) into the column of 
 * choice. The piece then drops into the
 * bottom-most row, stacking on top of prior pieces until the 
 * column is full. The physical game uses gravity
 * and a shelf on the bottom row, as well as a very thin game board 
 * to achieve this, while the code uses a
 * 2D array of empty tiles and counts upward from one, the bottom 
 * row. To restart the game, the board is
 * wiped, and the players continue from scratch. This game adds
 *  several “royal features” such as
 * appending titles to the players and determining who rules the 
 * kingdom after winning the most matches.
 */

#include <string> //string manipulation
#include <iomanip> //setw, setprecision
#include <iostream> //cout
#include <fstream> //file stream
#include <vector> //vector STL
#include <list> //convert vector to list
#include <algorithm> //std::replace
#include "Player.h"
#include "EastEgg.h"
#include "Stats.h"
using namespace std;

//function prototypes for simple cout statements
//unnecessary for inclusion in classes or header files
void badInpt();
void roylDec();
void samNam();
void wavyLn();

//calls declaration of game
//calls getside to assign names
//confirms names and titles
//catches players with same name (low odds of occurrence)
//catches exception to input for confirm()
//catches BadInput after each player takes turns
//builds updated gameBoard after each move
//exit if BadInput, return(0) if 'n' after game done
int main(int argc, char** argv) {
    Player play;
    //create 2 players, p1 and p2
    Player arr[2];
    //allow buffer for arr[1], '\n'?
    char sixBy7[7][7];
    roylDec();
    play.getSide(arr);
    if(arr[0] == arr[1])
    {
        samNam();
    }
    try
    {
        play.confirm(arr); 
    }
    catch(Player::Xcption)
    {
        void badInpt();
    }
    play.gmeBord(sixBy7);
    try
    {
        play.playGme(sixBy7, arr); 
    }
    catch(Player::Xcption)
    {
        cout << "Bad Input" << endl;
        if((play.gtGmCnt() - 3) == 1)
        {
            cout << "Good Game!" << endl;
        }else if((play.gtGmCnt() - 3) != 1)
        {
            cout << "Good Games!" << endl;
        }
        cout << "Number of games played this session: "
             << play.gtGmCnt() - 3 << endl;
        cout << "Goodbye.";
        exit(0);
    }
    return 0;
}

//get each side and then confirm();
//chooses side as well as appends with random title from array
//displays side so users can confirm
//resets gmCount to 0
//strange gmCount math seen later due to counting each
//created Player instance, including derived
void Player::getSide(Player *ptr)
{
    srand (time(NULL));
    string s1, s2, roy1, roy2;
    char sel;
    cout << "Player X will go 1st, enter your name: ";
    getline (cin,s1);
    cout << "Do you wish to be male, female, or neither? "
         << "Key in (m/f/other): ";
    cin >> sel;
    if(sel == 'f')
    {
        roy1 = titleF[rand()%15] + s1 + " the " + adjF[rand()%13];
    }
    if(sel == 'm')
    {
        roy1 = titleM[rand()%15] + s1 + " the " + adjM[rand()%13];
    }else if (sel != 'm' && sel != 'f')
    {
        roy1 = titleM[rand()%5] + s1 + " the " + adjM[rand()%10];
    }
    ptr[PLAYER1].name = roy1;
    cin.ignore();
    cout << "Player O will go 2nd, enter your name: ";
    getline (cin,s2);
    cout << "Do you wish to be male, female, or neither? "
         << "Key in (m/f/other): ";
    cin >> sel;
    if(sel == 'f')
    {
        roy2 = titleF[rand()%15] + s2 + " the " + adjF[rand()%13];
    }
    if(sel == 'm')
    {
        roy2 = titleM[rand()%15] + s2 + " the " +adjM[rand()%13];
    }else if (sel != 'm' && sel != 'f')
    {
        roy2 = titleM[rand()%5] + s2 + " the " + adjM[rand()%10]; //5 10
    }
    ptr[PLAYER2].name = roy2;
    ptr[PLAYER1].XorO = 'X';
    ptr[PLAYER2].XorO = 'O';
    for(int i=0; i<2; i++)
    {
    cout << ptr[i].name << " will be the " 
         << ptr[i].XorO << "'s." << endl;
    }
    gmCount = 0;
}

//allows users to re-decide who goes first
//outputs unchanged EasterEgg counter
//calls vector to show rules, along with helpful text
void Player::confirm(Player *ptr)
{
    char conf;
    Player play;
    int egg = (1 - (play.gtGmCnt()/2 - 3)) - 1;
    cout << "Doest this behold well to thee? ('n' to redo)" << endl;
    cin >> conf;
    if(conf == 'n')
    {
        cout << "Please try again." << endl;
        cin.ignore();
        getSide(ptr);
        confirm(ptr);
    }else if(conf != 'y' && conf != 'n')
    {
        throw Xcption();
    }else{
        cout << "";
    }
    vecStuf();
    cout << "Connect four tokens in any direction to win the match."<< endl;
    cout << "Win the most number of matches to claim victory!" << endl;
    cout << "Enter any non-number to surrender the match." << endl;
    EastEgg line(egg);
    display(line);
}

//switch between players
//exception handling to not enter integer
//enter a non-numerical value to quit
int Player::takeTrn( char sixBy7[6][7], Player current )
{
    int slction = 0;
    if(cin.fail())
    {
        cout << "Exit game" << endl;
        exit(0);
    } 
    do{
        if(!cin.fail())
        {
            cout << current.name << "'s Turn ";
            cout << "Enter a number (1-7): ";
            try
            {
            cin >> slction;
            }
            catch(Player::Xcption)
            {
                cout << "Try Again:" << endl;
                cin >> slction;
            }
            if(!cin.fail())
            {
                while (sixBy7[1][slction] != ' ')
                {
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

//checks and prints value per each 2D array value
//allows reselect on invalid integer entry
//1 and 7 are the valid entries due to the Milton Bradley rules
void Player::isValid (char sixBy7[6][7], Player current, int slction)
{
    int SIZE, getTurn = 0;
    SIZE = getTurn + 6;
    while (getTurn != 1){
        if (sixBy7[SIZE][slction] != 'X' 
            && sixBy7[SIZE][slction] != 'O')
        {
            sixBy7[SIZE][slction] = current.XorO;
            getTurn = 1;
        }else{
            --SIZE;
        }
    }
}

//check each position in the array of chars
//if X's or O's are 4 in a row in any direction
//print out win = 1 to the playGame function to proceed
//checks every direction, up, down and horizontal
int Player::isFour (char sixBy7[6][7], Player current)
{
    int win = 0;
    char c = current.XorO;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (sixBy7[i][j] == sixBy7[i + 1][j] &&
                sixBy7[i][j] == sixBy7[i + 2][j] &&
                sixBy7[i][j] == sixBy7[i + 3][j] &&
                sixBy7[i][j] == c)
            {
                win = 1;
            }
        }
    }
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (sixBy7[i][j] == sixBy7[i][j + 1] &&
                sixBy7[i][j] == sixBy7[i][j + 2] &&
                sixBy7[i][j] == sixBy7[i][j + 3] &&
                sixBy7[i][j] == c)
            {
                win = 1;
            }
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (sixBy7[i][j] == sixBy7[i + 1][j + 1] &&
                sixBy7[i][j] == sixBy7[i + 2][j + 2] &&
                sixBy7[i][j] == sixBy7[i + 3][j + 3] &&
                sixBy7[i][j] == c)
            {
                win = 1;
            }
        }
    }
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 3; j < 6; j++)
        {
            if (sixBy7[i][j] == sixBy7[i + 1][j - 1] &&
                sixBy7[i][j] == sixBy7[i + 2][j - 2] &&
                sixBy7[i][j] == sixBy7[i + 3][j - 3] &&
                sixBy7[i][j] == c)
            {
                win = 1;
            }
        }
    }
   return win;
}

//print updated game board after each turn, 
//verify is isFour and create array of 1-7 to label
//isFilled checks to see if the board is done for
void Player::gmeBord (char sixBy7[6][7])
{
    int array[6];
    for(int i=1; i<=6; i++)
    {
        for(int j=1; j<=7; j++)
        {
            if(sixBy7[i][j] != 'O' && sixBy7[i][j] != 'X')
            {
                sixBy7[i][j] = ' ';   
            }
            cout << sixBy7[i][j] << "|";
        }
        cout << endl;
    }

    for(int i=1; i<=7; i++)
    {
        array[i] = i;
        cout << array[i] <<  " ";
    }
    cout << endl;
}

//checks the array column by column to see if full board
//no incrementation and reset is asked in this situation
//called in PlayGame
int Player::isFilld(char sixBy7[6][7])
{
    int filled = 0;
    for(int j = 1; j <= 7; j++)
    {
        if(sixBy7[1][j] != ' ')
        {
            ++filled;
        }
    }
    return filled;
}

//this function checks after each Player's turn using the takeTurn
//and isValid functions. When a completed game is registered
//the winning player's total++ and the Easter Egg counter-- 
//the lossMsg is randomly generated, and the choice to end or
//play again is presented. After end game is selected, the stats
//are outputed and the winner is declared
//logic is implemented in order to show the correct number of
//game(s), with unique sentences for plurals and tied games
char Player::reset (char sixBy7[6][7], fstream &file, Player *ptr)
{
//verify 'y' or 'n' for replay  
    srand (time(NULL));
    float winPerc;
    int maxWin, gmTot;
    Player play;
    loserP loser;
    char yesNo;
    int num = 6;
    int egg = (1 - (play.gtGmCnt()/2 - 3)) - 1; //5
    char yOrN;
    if(yOrN != 'n')
    {
        EastEgg line(egg);
        display(line);
        if(egg == 0){
            cout << "You've unlocked the Easter Egg!"<<endl;
            if(rand()%5 == 3)
            {
                loser.dynamic(num);
            }else{
            dynamic(num);
            }
            cout << "You have also unlocked the 'Golden' nametag." <<endl;
            cout << "Would you like to activate this? (y/n)" << endl;
            cin >> yesNo;
            if (yesNo == 'y'){
                +ptr[0];
                +ptr[1];
            }
        }
        cout << "Play again? (y/n) " << endl;
        cin  >> yOrN;
        if (yOrN == 'y')
        {
            for(int i=1; i<=6; i++)
            {
                for(int j = 1; j <= 7; j++)
                {
                    sixBy7[i][j] = ' ';  //clear sixBy7
                }
            }
            gmeBord(sixBy7);
        }else if (yOrN == 'n')
        {
            if((egg) == 1)
            {
                cout << "Good Game!";
            }else if((egg) != 1)
            {
                cout << "Good Games!";
            }
            maxWin=retMax<int>(ptr[PLAYER1].winTot,
                               ptr[PLAYER2].winTot);
                        gmTot = ptr[PLAYER1].winTot 
                              + ptr[PLAYER2].winTot;
            winPerc = (float)maxWin/(float)(gmTot);
            winPerc *= 100;
            if(ptr[PLAYER1] > ptr[PLAYER2])
            {
                cout << endl << ptr[PLAYER1].name;
                cout << endl << "has been crowned ruler of " 
                     << "all the land with" << endl; 
                if(maxWin == 1)
                {
                    cout << maxWin << " game won";
                }else if (maxWin > 1)
                {
                    cout << maxWin << " games won";
                }
                cout << ", for a win/loss percentage of "
                     << winPerc << "%.\n";
            }else if(ptr[PLAYER2] > ptr[PLAYER1])
            {
                cout << endl << ptr[PLAYER2].name;
                cout << endl << "has been crowned ruler of " 
                     << "all the land with" << endl;
                if(maxWin == 1)
                {
                    cout << maxWin << " game won";
                }else if (maxWin > 1)
                {
                    cout << maxWin << " games won";
                }
                cout << ", for a win/loss percentage of "
                     << winPerc << "%.\n";
            }else if (ptr[PLAYER2] && ptr[PLAYER1])
            {
                cout<<endl;
                cout << "Both Players Tied." << endl;
                cout << tieMsg[rand()%6] << endl;
            }
            cout << "Stats for Nerds: " << endl;
            cout << "Number of games played this session: " << gmTot;
            play = gtPlaDat(file);
            cout << "Thank ye for playing." << endl;
            cout << "Goodbye.";
            exit(0);
        }else{
            throw Xcption();
            yOrN = reset(sixBy7, file, ptr);
        }
    }
    return yOrN;
}

//this function is a lottery number generator
//it is called after the case of an Easter Egg scenario
//there is a one in 5 chance of getting a "Troll" copy
//this alternate function is in a derived Player class called LoserP
int *Player::dynamic(int num)
{
    int *array = nullptr;
    if(num <= 0)
        return nullptr;
    array = new int[num]; //allocate dynamic
    srand(time(0));
    cout << "You get some winning lottery numbers!: ";
    for(int i =0; i < num; i++)
    {
        array[i] = rand()%47;
        cout << array[i] << " ";
    }
    cout << endl << "These will surely help you escape serfdom." << endl;
    return array;
}

//write to file the win and loss totals, increment and write each time
//loop dependent on PlayAgn variable returned by reset() after completion
//the isFilld function is called to check the full board and return
//a reset game in this scenario, without incrementing the winTots
void Player::playGme (char sixBy7[6][7], Player *ptr)
{
    int slction, isWin, filled = 0;
    char playAgn;
    ofstream wf("score.bin", ios::in | ios::out | ios::binary); 
    //score.bin must exist
    fstream file;
    string str;
    cout << "Rule: enter any non-integer to concede." << endl;
    while (playAgn != 'n')
    {
        for(int i=0; i<=1; i++)
        {
            try
            {
                slction = takeTrn(sixBy7, ptr[i]);
            }
            catch(Player::Xcption)
            {
                cout << "Bad Input" << endl;
            }
            isValid(sixBy7, ptr[i], slction);
            gmeBord(sixBy7);
            isWin = isFour(sixBy7, ptr[i]);
            if(isWin == 1){
                ptr[i].winTot++;
                cout << ptr[i].name << " has declared victory!" << endl;
                if(i == PLAYER1)
                {
                    ptr[PLAYER2].lossTot++;
                    str = sntStrt[rand()%4] + ptr[PLAYER2].name + lossMsg[rand()%8];
                    cout << str << endl;
                }else{
                    ptr[PLAYER1].lossTot++;
                    str = sntStrt[rand()%4] + ptr[PLAYER1].name + lossMsg[rand()%8];
                    cout << str << endl;
                }
                for(int i=0; i<2; i++)
                {
                    wf.write((char *) &ptr[i], sizeof(&ptr[i]));
                }
                for(int i=0; i<2; i++) 
                {
                    cout << ptr[i].name << " has won "
                         << setw(2)   
                         << ptr[i].winTot 
                         << " time(s) and lost " 
                         << setw(2)
                         << ptr[i].lossTot 
                         << " time(s)."<< endl;
                }
                wf.close();
                playAgn = reset(sixBy7, file, ptr);                   
            }
            filled = isFilld(sixBy7);
            if (filled == 7)
            {
                cout << "Tie game." << endl;
                playAgn = reset(sixBy7, file, ptr);
            }
        }
    }
}

//this function calls a file with the high scores printed 
//in a single line, and rejects the first few characters
// that represent the developer's score
//empty class is shown (Player) with the constructors
// showcased in the form of passing variables in the
//parentheses, and showing the user some behind the scenes info
Player Player::gtPlaDat(fstream &file)
{
    char ch[20];
    ofstream outFile("out.txt");
    file.open("test.txt", ios::in);
    file.seekg(11L, ios::beg); //ignore programmer's score
    cout << endl << "Previous win streaks: " << endl;
    while (file >> ch[20])
    {
        outFile.put(ch[20]);
        cout << ch[20];
    }
    file.close();
    cout << endl << "Here's what the empty structure looks like:" << endl;
    Player temp("Empty", 'E');
    for(int i = 0; i < 2; i++)
    {
        cout << "P" << i+1 << " = " << temp.name << endl;
        cout << "Game piece = " << temp.XorO << endl;
    }
    return temp;
}

//this function replaces the 4 lines in case of a bad input
//after the confirm function doesn't receive a Y or N
void badInpt()
{
    cout << "Bad Input" << endl;
    cout << "Win the most number of matches to claim victory!" << endl;
    cout << "Connect four tokens in any direction to win the match."<< endl;
    cout << "Enter any non-number to surrender the match." << endl; 
}

//this function provides the royal flair by calling wavyLn() x4
//all rights for crown art attributed to lc on asciiart.eu
void roylDec()
{
    wavyLn();
    cout << endl << "~~~~~Welcome to Royal Connect Four!~~~~~" << endl;
    wavyLn();
    cout << R"(
         *                    *
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
            " for the right to sit on the throne!" << endl;
}

//this function calls in the rare case of both players
//having the same exact name entered and appended titles
//program and writing to BIN still works in this scenario
//but a redo is suggested for clarity and for the unique outputs
void samNam()
{
    cout << "Both of you have the same name?" <<endl;
    cout << "And you received the same titles?" <<endl;
    cout << "Very strange indeed, consider a redo."<<endl;
}

//this function prints out a fancy wavy line
void wavyLn()
{
    for(int i = 0; i < 40; i++)
    {
        cout << "~";
    }
}