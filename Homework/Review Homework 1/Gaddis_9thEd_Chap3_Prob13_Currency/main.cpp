/* 
 * File: Currency
 * Author: Dennis Lang
 * Date: 06/26/20
 * Purpose: HW, convert currency
 * Version: 1
 */

//1 dollar = 106.97 Yen
//1 dollar = 0.89 Euro

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
    const float YEN_PER_DOLLAR = 0;
    const float EUROS_PER_DOLLAR = 0;
    float US_DOLLARS = 0;
    //7 characters or less
    
    //Initialize or input data here
    cout << "How much money do you have?" << endl;
    cin >> US_DOLLARS;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout << "$" << US_DOLLARS << " = " << setprecision(2) << fixed << US_DOLLARS * 106.97 << " Yen." << endl;
    cout << "$" << noshowpoint << US_DOLLARS << setprecision(2) << fixed << " = " << US_DOLLARS * .89 << " Euros." << endl;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}
