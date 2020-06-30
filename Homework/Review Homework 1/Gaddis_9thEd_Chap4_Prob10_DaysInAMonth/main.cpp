/* 
 * File: DaysInAMonth
 * Author: Dennis Lang
 * Date: 06/26/20
 * Purpose: HW, calculate days in a given month
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    int month = 0;
    int year = 0;
    //7 characters or less
    
    //Initialize or input data here
    cout << "What month is it? (1-12)" << endl;
    cin >> month;
    cout << "What year is it?" << endl;
    cin >> year;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    //Format and display outputs here
    cout << "That month has ";
    if(month == 2)
    {
    if(year % 100 == 0)
    {
        if (year % 400 == 0)
            cout << "29 days." << endl;
        else
            cout << "28 days." << endl;
    }
    else if(year % 100 != 0)
    {
        if (year % 4 == 0)
            cout << "29 days." << endl;
        else
            cout << "28 days." << endl;
    }
    }
    else if (month != 4 && month != 6 && month != 9 && month != 11)
    {
        cout << "31 days." << endl;
    }
    else
    {
        cout << "30 days." << endl;
    }
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}
