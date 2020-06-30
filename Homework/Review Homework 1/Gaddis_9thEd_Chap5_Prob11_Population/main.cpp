/* 
 * File: Population
 * Author: Dennis Lang
 * Date: 06/26/20
 * Purpose: HW, population size
 * Version: 1
 */

//x(t) = x0 × (1 + r) ^ t

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
#include <math.h>
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
    int startNum;
    int numDays;
    int percent;
    int finalNum;
    //7 characters or less
    
    //Initialize or input data here
    cout << "How many individuals are in the population?" << endl;
    cin >> startNum;
    cout << "By what percentage is the population increasing?" << endl;
    cin >> percent;
    cout << "How many days will the population multiply?" << endl;
    cin >> numDays;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    if(startNum <= 1)
    {
        cout << "Starting number too low, please re-enter." << endl;
        cin >> startNum;
    }
    if(percent < 0)
            
    {
        cout << "Percentage too low, please re-enter." << endl;
        cin >> percent;
    }
    if(numDays < 2)
    {
        cout << "Number of days too low, please re-enter." << endl;
        cin >> numDays;
    }

    //Format and display outputs here
    int x = 1 + (percent/100);
    int y = pow(x, numDays);
    finalNum = y*startNum;
    
    cout << "The population after " << numDays << " days is " << finalNum << endl;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}
