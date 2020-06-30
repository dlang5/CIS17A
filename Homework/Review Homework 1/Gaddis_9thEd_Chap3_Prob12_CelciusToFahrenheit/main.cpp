/* 
 * File: CelciusToFahrenheit
 * Author: Dennis Lang
 * Date: 06/26/20
 * Purpose: HW
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
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
    float celcius = 0;
    //7 characters or less
    
    //Initialize or input data here
    cout << "What is the temp in C?" << endl;
    cin >> celcius;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    //Format and display outputs here
    cout << ((9*celcius)/5) + 32;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}