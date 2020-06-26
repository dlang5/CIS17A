/* 
 * File:
 * Author:
 * Date:
 * Purpose:
 * Version:
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
    float num1 = 0;
    float num2 = 0;
    float num3 = 0;
    float num4 = 0;
    //7 characters or less
    
    //Initialize or input data here
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;
    //Format and display outputs here
    cout << "        " << num1 << showpoint << "       " << setprecision(2) << num1 << "      " << setprecision(3) << num1 << endl;
    cout << "        " << noshowpoint << num2 << showpoint << "       " << setprecision(2) << num2 << "      " << setprecision(3) << num2 << endl;
    cout << "        " << noshowpoint << num3 << showpoint << "       " << setprecision(2) << num3 << "      " << setprecision(3) << num3 << endl;
    cout << "        " << noshowpoint << num4 << showpoint << "       " << setprecision(2) << num4 << "      " << setprecision(3) << num4;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}