/* 
 * File: RainOrShine
 * Author: Dennis Lang
 * Date: 06/26/20
 * Purpose: HW
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
const int row = 3;
const int column = 30;
string weather_types[row]  = {"Rainy", "Cloudy", "Sunny"};
string months[row]         = {"June", "July", "August"};
char weather_day_names[row]= {'R', 'C', 'S'};
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here
void getInfoFromFile(char[][COLUMNS], string);
void displayMonths(const char[][COLUMNS], int);
void displayDays(const char[][COLUMNS], int);
void displayHighest(const char[][COLUMNS]);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    
    //Initialize or input data here
    char weather_conditions[ROWS][COLUMNS];

    getInfoFromFile(weather_conditions, "RainOrShine.txt");

    for (int letter = 0; letter < ROWS; letter++)
        displayDays(weather_conditions, letter);
    
    for (int i = 0; i < ROWS; i++)
        displayMonths(weather_conditions, i);
    //Display initial conditions, headings here
    displayHighest(weather_conditions);

    cout << endl;
    //Process inputs  - map to outputs here
    //Format and display outputs here
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}

void getInfoFromFile(char array[][COLUMNS], string file_name)
{
    ifstream inputFile;

    inputFile.open(file_name);

    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLUMNS; col++)
            inputFile >> array[row][col];
    }

    inputFile.close();
}

void displayDays(const char array[][COLUMNS], int i)
{
    int total;
    for (int row = 0; row < ROWS; row++)
    { 
        total = 0;
        for (int col = 0; col < COLUMNS; col++)
            if (array[row][col] == weather_day_names[i]) { total++; }

        cout << "Total "
             << weather_types[i]
             << " days for "
             << months[row]
             << " = "
             << total
             << endl;
    }
    cout << endl;
}

void displayMonths(const char array[][COLUMNS], int i)
{
    int total = 0;
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLUMNS; col++)
            if(array[row][col] == weather_day_names[i]) { total++; }
    }

    cout << "Total "
         << weather_types[i]
         << " days for all months = "
         << total
         << endl;

}

void displayHighest(const char array[][COLUMNS])
{
    int sum;
    int total_rainy_days[ROWS];
    
    for (int row = 0; row < ROWS; row++)
    {
        sum = 0;
        for (int col = 0; col < COLUMNS; col++)
            if (array[row][col] == 'R') { sum++; }
            
        total_rainy_days[row] = sum;
    }

    cout << endl;


    int highest_rainy_day = total_rainy_days[0];
    string highest_rainy_day_name = months[0];

    for(int i = 1; i < ROWS; i++)
    {
        if(total_rainy_days[i] > highest_rainy_day)
        {
            highest_rainy_day = total_rainy_days[i];
            highest_rainy_day_name = months[i];
        } 
        else if(total_rainy_days[i] == highest_rainy_day)
        {
            highest_rainy_day = total_rainy_days[i];
            highest_rainy_day_name += ", ";
            highest_rainy_day_name += months[i];
        }
            
    }

    cout << highest_rainy_day_name
         << " had the highest rainy days, "
         << "with "
         << highest_rainy_day
         << " days."
         << endl;
}